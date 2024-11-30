#!/bin/bash

# Script autonorm.sh
# Surveille et exécute norminette sur les fichiers C spécifiés
# Auteur : [Votre Nom]
# Date : [Date]

# Fonction pour afficher un message d'erreur et quitter
error_exit() {
    echo "Erreur : $1" >&2
    exit 1
}

# Fonction pour afficher l'aide
display_help() {
    echo "Usage: $0 [OPTIONS] <fichier1.c> <fichier2.c> ... <fichierN.c>"
    echo ""
    echo "Options :"
    echo "  -h              Affiche ce message d'aide."
    echo "  -e              Exclut les fichiers dont le nom commence par 'test_'."
    echo ""
    echo "Exemples :"
    echo "  $0 file1.c file2.c"
    echo "  $0 -e file1.c file2.c"
    exit 0
}

# Vérifier si au moins un argument est passé
if [ "$#" -lt 1 ]; then
    echo "Erreur : Aucun fichier spécifié."
    display_help
fi

# Initialiser les variables
exclude_test=0
files=()

# Parser les options
while getopts ":he" opt; do
    case "$opt" in
        h)
            display_help
            ;;
        e)
            exclude_test=1
            ;;
        \?)
            error_exit "Option non supportée : -$OPTARG. Utilisez -h pour l'aide."
            ;;
    esac
done

shift $((OPTIND -1))

# Récupérer les fichiers restants comme fichiers à surveiller
for file in "$@"; do
    # Vérifier si le fichier existe
    if [ ! -f "$file" ]; then
        error_exit "Le fichier '$file' n'existe pas."
    fi
    # Vérifier si le fichier a l'extension .c
    if [[ "$file" != *.c ]]; then
        error_exit "Le fichier '$file' n'est pas un fichier C (.c)."
    fi
    # Si l'option -e est activée, exclure les fichiers commençant par test_
    if [ "$exclude_test" -eq 1 ]; then
        basename=$(basename "$file")
        if [[ "$basename" == test_* ]]; then
            echo "Exclusion du fichier '$file' car il commence par 'test_'."
            continue
        fi
    fi
    files+=("$file")
done

# Vérifier si des fichiers restent après exclusion
if [ "${#files[@]}" -eq 0 ]; then
    error_exit "Aucun fichier à surveiller après application des critères."
fi

# Initialiser le dernier résultat de norminette
last_norminette_result=$(norminette -R CheckForbiddenSourceHeader "${files[@]}")

# Afficher le résultat initial de norminette
echo "$last_norminette_result"

# Utiliser fswatch pour surveiller les modifications de fichiers
fswatch -o "${files[@]}" | while read -r event; do
    # Exécuter la commande norminette
    norminette_result=$(norminette -R CheckForbiddenSourceHeader "${files[@]}")
    
    # Si le résultat de norminette a changé, l'afficher et le sauvegarder
    if [ "$norminette_result" != "$last_norminette_result" ]; then
        clear
        echo "$norminette_result"
        last_norminette_result="$norminette_result"
    fi
done