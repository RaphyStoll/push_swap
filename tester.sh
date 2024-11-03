#!/bin/bash

# test_push_swap.sh
# Script interactif pour tester push_swap avec des arguments aléatoires
# Auteur : [Votre Nom]
# Date : [Date]

# Définir les variables par défaut globalement
exec_path="./push_swap"
num_args=5
min_val=-1000
max_val=1000

# Fonction pour afficher un message d'erreur et quitter
error_exit() {
    echo "Erreur : $1" >&2
    exit 1
}

# Fonction pour afficher les critères d'évaluation de push_swap
display_eval_criteria() {
    echo "=== Critères d'évaluation pour push_swap ==="
    echo ""
    echo "- Pour une pile de 3 éléments :"
    echo "  - Maximum de 3 instructions."
    echo ""
    echo "- Pour une pile de 5 éléments :"
    echo "  - Maximum de 12 instructions."
    echo ""
    echo "- Pour une pile de 100 éléments :"
    echo "  - 5 points si 700 instructions ou moins."
    echo "  - 4 points si 900 instructions ou moins."
    echo "  - 3 points si 1100 instructions ou moins."
    echo "  - 2 points si 1300 instructions ou moins."
    echo "  - 1 point si 1500 instructions ou moins."
    echo ""
    echo "- Pour une pile de 500 éléments :"
    echo "  - 5 points si 5500 instructions ou moins."
    echo "  - 4 points si 7000 instructions ou moins."
    echo "  - 3 points si 8500 instructions ou moins."
    echo "  - 2 points si 10000 instructions ou moins."
    echo "  - 1 point si 11500 instructions ou moins."
    echo ""
    exit 0
}

# Fonction pour demander une entrée avec une valeur par défaut
prompt_with_default() {
    local prompt_message="$1"
    local default_value="$2"
    read -p "$prompt_message [$default_value]: " input
    # Utiliser la valeur par défaut si l'entrée est vide
    if [ -z "$input" ]; then
        echo "$default_value"
    else
        echo "$input"
    fi
}

# Fonction pour vérifier si une valeur est un entier
is_integer() {
    local s="$1"
    [[ "$s" =~ ^-?[0-9]+$ ]]
}

# Fonction pour générer des nombres aléatoires uniques sans utiliser 'shuf'
generate_unique_numbers() {
    local num_args="$1"
    local min_val="$2"
    local max_val="$3"
    local -a numbers=()
    local rand
    local exists

    while [ "${#numbers[@]}" -lt "$num_args" ]; do
        # Générer un nombre aléatoire dans la plage [min_val, max_val]
        rand=$((RANDOM % (max_val - min_val + 1) + min_val))

        # Vérifier si le nombre existe déjà dans le tableau
        exists=0
        for number in "${numbers[@]}"; do
            if [ "$rand" -eq "$number" ]; then
                exists=1
                break
            fi
        done

        # Ajouter le nombre s'il est unique
        if [ "$exists" -eq 0 ]; then
            numbers+=("$rand")
        fi
    done

    # Retourner les nombres générés
    echo "${numbers[@]}"
}

# Fonction pour valider les nombres générés
validate_numbers() {
    local numbers="$1"
    local min_val="$2"
    local max_val="$3"
    local -a num_array=($numbers)
    local seen=()

    for num in "${num_array[@]}"; do
        # Vérifier la plage
        if [ "$num" -lt "$min_val" ] || [ "$num" -gt "$max_val" ]; then
            error_exit "Le nombre $num est en dehors de la plage [$min_val, $max_val]."
        fi

        # Vérifier l'unicité
        for seen_num in "${seen[@]}"; do
            if [ "$num" -eq "$seen_num" ]; then
                error_exit "Le nombre $num est dupliqué."
            fi
        done
        seen+=("$num")
    done
}

# Fonction pour exécuter les tests avec une option pour compter les lignes
run_test() {
    local count_lines="$1"

    # Vérifier que la plage est suffisante pour générer des nombres uniques
    local range=$((max_val - min_val + 1))
    if [ "$num_args" -gt "$range" ]; then
        error_exit "Impossible de générer $num_args nombres uniques dans la plage [$min_val, $max_val]."
    fi

    # Générer des nombres aléatoires uniques
    numbers=$(generate_unique_numbers "$num_args" "$min_val" "$max_val")

    # Valider les nombres générés
    validate_numbers "$numbers" "$min_val" "$max_val"

    # Si en mode débogage, afficher les nombres générés
    if [ "$debug_flag" -eq 1 ]; then
        echo "Nombres générés : $numbers"
    fi

    if [ "$count_lines" -eq 1 ]; then
        # Exécuter push_swap et compter les lignes de sortie
        output=$("$exec_path" $numbers 2>/dev/null)
        line_count=$(echo "$output" | wc -l)
        echo "$line_count"
    else
        # Afficher les arguments générés
        echo "Arguments générés : $numbers"

        # Exécuter push_swap avec les arguments générés
        output=$("$exec_path" $numbers)
        echo "Sortie de push_swap :"
        echo "$output"

        # Vérifier si push_swap s'est exécuté correctement
        if [ $? -ne 0 ]; then
            error_exit "push_swap a rencontré une erreur lors de l'exécution."
        fi
    fi
}

# Fonction pour exécuter plusieurs tests et afficher uniquement le nombre de lignes
weighted_mode() {
    local num_runs="$1"

    # Vérifier si l'exécutable existe
    if [ ! -f "$exec_path" ]; then
        error_exit "L'exécutable '$exec_path' n'existe pas."
    fi

    # Vérifier si le fichier est exécutable
    if [ ! -x "$exec_path" ]; then
        error_exit "Le fichier '$exec_path' n'est pas exécutable."
    fi

    # Exécuter les tests en boucle
    for ((i=1; i<=num_runs; i++)); do
        run_test 1
    done
}

# Fonction pour le mode interactif
interactive_mode() {
    echo "=== Mode Interactif de Test pour push_swap ==="

    # 1. Demander le chemin de l'exécutable push_swap, par défaut ./push_swap
    exec_path=$(prompt_with_default "Entrez le chemin de l'exécutable push_swap" "$exec_path")

    # Vérifier si l'exécutable existe
    if [ ! -f "$exec_path" ]; then
        error_exit "L'exécutable '$exec_path' n'existe pas."
    fi

    # Vérifier si le fichier est exécutable
    if [ ! -x "$exec_path" ]; then
        error_exit "Le fichier '$exec_path' n'est pas exécutable."
    fi

    # 2. Demander le nombre d'arguments à générer
    while true; do
        num_args=$(prompt_with_default "Entrez le nombre d'arguments à générer" "$num_args")
        if is_integer "$num_args" && [ "$num_args" -gt 0 ]; then
            break
        else
            echo "Veuillez entrer un entier positif."
        fi
    done

    # 3. Demander la valeur minimale pour la randomisation
    while true; do
        min_val=$(prompt_with_default "Entrez la valeur minimale pour la randomisation" "$min_val")
        if is_integer "$min_val"; then
            break
        else
            echo "Veuillez entrer un entier valide."
        fi
    done

    # 4. Demander la valeur maximale pour la randomisation
    while true; do
        max_val=$(prompt_with_default "Entrez la valeur maximale pour la randomisation" "$max_val")
        if is_integer "$max_val"; then
            if [ "$max_val" -ge "$min_val" ]; then
                break
            else
                echo "La valeur maximale doit être supérieure ou égale à la valeur minimale."
            fi
        else
            echo "Veuillez entrer un entier valide."
        fi
    done

    # Exécuter le test avec les paramètres fournis
    run_test "$count_flag"
}

# Fonction pour afficher l'aide
display_help() {
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "Options :"
    echo "  -h, --help              Affiche ce message d'aide et les valeurs par défaut."
    echo "  -m, --modif             Lance le script en mode interactif pour configurer les paramètres."
    echo "  -c, --count             Compte le nombre de lignes de sortie de push_swap."
    echo "  -w, --weight  <nombre>  Lance plusieurs tests et affiche uniquement le nombre de lignes de sortie par test."
    echo "  -d, --debug             Active le mode débogage pour afficher les nombres générés."
    echo "  -e, --eval              Affiche les critères d'évaluation de push_swap."
    echo ""
    echo "Sans options, le script exécute push_swap avec les valeurs par défaut :"
    echo "  Chemin de l'exécutable : $exec_path"
    echo "  Nombre d'arguments : $num_args"
    echo "  Valeur minimale : $min_val"
    echo "  Valeur maximale : $max_val"
    exit 0
}

# Fonction pour le mode par défaut 
default_mode() {
    # Vérifier si l'exécutable existe
    if [ ! -f "$exec_path" ]; then
        error_exit "L'exécutable '$exec_path' n'existe pas."
    fi

    # Vérifier si le fichier est exécutable
    if [ ! -x "$exec_path" ]; then
        error_exit "Le fichier '$exec_path' n'est pas exécutable."
    fi

    # Exécuter le test avec les paramètres par défaut ou avec comptage
    run_test "$count_flag"
}

# Initialiser les flags
count_flag=0
weight_flag=0
weight_count=0
debug_flag=0

# Utiliser getopt pour parser les options longues et courtes
PARSED_OPTIONS=$(getopt -n "$0" -o hmcw:de --long help,modif,count,weight:,debug,eval -- "$@")
if [ $? -ne 0 ]; then
    error_exit "Options incorrectes. Utilisez -h ou --help pour l'aide."
fi

# Réorganiser les paramètres selon getopt
eval set -- "$PARSED_OPTIONS"

# Boucle pour traiter les options
while true; do
    case "$1" in
        -h|--help)
            display_help
            ;;
        -m|--modif)
            interactive_mode
            exit 0
            ;;
        -c|--count)
            count_flag=1
            shift
            ;;
        -w|--weight)
            weight_flag=1
            weight_count="$2"
            if ! is_integer "$weight_count" || [ "$weight_count" -le 0 ]; then
                error_exit "Le nombre de tests avec -w doit être un entier positif."
            fi
            shift 2
            ;;
        -d|--debug)
            debug_flag=1
            shift
            ;;
        -e|--eval)
            display_eval_criteria
            ;;
        --)
            shift
            break
            ;;
        *)
            error_exit "Option non supportée: $1. Utilisez -h ou --help pour l'aide."
            ;;
    esac
done

# Si l'option -w est activée, exécuter en mode poids
if [ "$weight_flag" -eq 1 ]; then
    weighted_mode "$weight_count"
    exit 0
fi

# Mode par défaut ou avec -c
default_mode
