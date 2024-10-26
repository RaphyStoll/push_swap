#!/bin/bash

# test_push_swap.sh
# Script interactif pour tester push_swap avec des arguments aléatoires
# Auteur : [Votre Nom]
# Date : [Date]

# Fonction pour afficher un message d'erreur et quitter
error_exit() {
	echo "Erreur : $1" >&2
	exit 1
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

# Fonction pour exécuter les tests
run_test() {
	local exec_path="$1"
	local num_args="$2"
	local min_val="$3"
	local max_val="$4"

	# Vérifier que la plage est suffisante pour générer des nombres uniques
	local range=$((max_val - min_val + 1))
	if [ "$num_args" -gt "$range" ]; then
		error_exit "Impossible de générer $num_args nombres uniques dans la plage [$min_val, $max_val]."
	fi

	# Générer des nombres aléatoires uniques
	numbers=$(generate_unique_numbers "$num_args" "$min_val" "$max_val")

	# Afficher les arguments générés
	echo "Arguments générés : $numbers"

	# Exécuter push_swap avec les arguments générés
	output=$("$exec_path" $numbers)

	# Vérifier si push_swap s'est exécuté correctement
	if [ $? -ne 0 ]; then
		error_exit "push_swap a rencontré une erreur lors de l'exécution."
	fi

	# Afficher la sortie de push_swap
	echo "Sortie de push_swap :"
	echo "$output"
}

# Fonction pour le mode interactif
interactive_mode() {
	echo "=== Mode Interactif de Test pour push_swap ==="

	# 1. Demander le chemin de l'exécutable push_swap, par défaut ./push_swap
	exec_path=$(prompt_with_default "Entrez le chemin de l'exécutable push_swap" "./push_swap")

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
		num_args=$(prompt_with_default "Entrez le nombre d'arguments à générer" "10")
		if is_integer "$num_args" && [ "$num_args" -gt 0 ]; then
			break
		else
			echo "Veuillez entrer un entier positif."
		fi
	done

	# 3. Demander la valeur minimale pour la randomisation
	while true; do
		min_val=$(prompt_with_default "Entrez la valeur minimale pour la randomisation" "-100")
		if is_integer "$min_val"; then
			break
		else
			echo "Veuillez entrer un entier valide."
		fi
	done

	# 4. Demander la valeur maximale pour la randomisation
	while true; do
		max_val=$(prompt_with_default "Entrez la valeur maximale pour la randomisation" "100")
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
	run_test "$exec_path" "$num_args" "$min_val" "$max_val"
}

# Fonction pour afficher l'aide
display_help() {
	echo "Usage: $0 [OPTIONS]"
	echo ""
	echo "Options :"
	echo "  -h, --help        Affiche ce message d'aide et les valeurs par défaut."
	echo "  -m                Lance le script en mode interactif pour configurer les paramètres."
	echo ""
	echo "Sans options, le script exécute push_swap avec les valeurs par défaut :"
	echo "  Chemin de l'exécutable : ./push_swap"
	echo "  Nombre d'arguments : 10"
	echo "  Valeur minimale : -100"
	echo "  Valeur maximale : 100"
	exit 0
}

# Fonction pour le mode par défaut 
default_mode() {
	#---------modifier ici-----------
	local exec_path="./push_swap"
	local num_args=4
	local min_val=-100
	local max_val=100

	# Vérifier si l'exécutable existe
	if [ ! -f "$exec_path" ]; then
		error_exit "L'exécutable '$exec_path' n'existe pas."
	fi

	# Vérifier si le fichier est exécutable
	if [ ! -x "$exec_path" ]; then
		error_exit "Le fichier '$exec_path' n'est pas exécutable."
	fi

	# Exécuter le test avec les paramètres par défaut
	run_test "$exec_path" "$num_args" "$min_val" "$max_val"
}

# Analyse des arguments en ligne de commande
if [ $# -gt 1 ]; then
	error_exit "Nombre d'arguments invalide. Utilisez -h pour l'aide."
fi

if [ $# -eq 1 ]; then
	case "$1" in
		-h|--help)
			display_help
			;;
		-m)
			interactive_mode
			;;
		*)
			error_exit "Option invalide. Utilisez -h pour l'aide."
			;;
	esac
else
	# Mode par défaut
	default_mode
fi