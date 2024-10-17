# Nom de la bibliothèque
NAME = libft.a

# Commandes
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

# Répertoire pour les fichiers objets
OBJDIR = ../objects

# Fichiers, sources et objets
FILES =	ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd

FILES_BONUS =	ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap \

SRCS = $(addsuffix .c, $(FILES))
SRCS_BONUS = $(addsuffix .c, $(FILES_BONUS))

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES_BONUS)))

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Création de la bibliothèque
$(NAME): $(OBJS)
	$(AR) $@ $^

# Compilation des fichiers bonus
bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

# Cible par défaut
all: $(NAME)

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) -r $(OBJDIR)

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re bonus