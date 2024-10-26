# Définition des variables
NAME = push_swap
GCC = gcc
FLAGS = -Wall -Wextra -Werror
MKDIR = mkdir -p
RM = rm -f
OBJDIR = ../objects

# Liste des sources (sans virgules)
SRC = 	push \
		swap \
		rotate \
		reverse_rotate \
      	utils \
      	lst_utils \
		lst_utils2 \
      	create_stack \
      	assign_indices \
		utils1 \
      	main \
		small_algo \
		algo_utils
		


# Génération des noms de fichiers sources et objets
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# Liste complète des objets
OBJECTS = $(OBJS)

# Règle par défaut
all: $(NAME)

# Création du répertoire OBJDIR s'il n'existe pas
$(OBJDIR):
	$(MKDIR) $(OBJDIR)

# Règle de création de l'exécutable
$(NAME): $(OBJECTS)
	$(GCC) $(FLAGS) $(OBJECTS) -o $(NAME)

# Règle de compilation des fichiers objets dans OBJDIR
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(GCC) $(FLAGS) -c $< -o $@




# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)

# Nettoyage complet, incluant l'exécutable
fclean: clean
	$(RM) $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
