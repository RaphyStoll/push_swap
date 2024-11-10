#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <ctype.h>

typedef struct s_stack
{
	int				value;
	int				id;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//! fonction principale
int					main(int argc, char **argv);
void				switch_algo(t_stack **stack_a, t_stack **stack_b,
						int lst_size);
//! split si argc == 1
char	**ft_split(char const *s, char c);
char	**allocate_and_fill(char const *s, char c);
char	*get_next_word(char const *s, char c, int *index);
int	count_words(const char *s, char c);
void	free_split(char **split, int words);

//! split utils
char	*ft_substr_split(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_split(const char *s);
char	*ft_strdup_split(const char *s1);

//! Algo 2 - 5
void				small_algo(t_stack **a, t_stack **b, int lst_size);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);

//!radix sort
void radix_sort(t_stack **a, t_stack **b, int size);

//! quik sort
void				q_sort(t_stack **main_stack, t_stack **aux_stack,
						int lst_size, char stack_name);
void				partition_stack(t_stack **a, t_stack **b, int pivot,
						char stack_name);
void	partition_stack_b(t_stack **a, t_stack **b, int pivot, int i_size);
void paprrtition_stack_a(t_stack **a, t_stack **b, int pivot, int i_size);

int					find_pivot(int lst_size, t_stack *stack);
//! algo utils
void				find_smallest(t_stack **a, t_stack **b);
void				find_biggest(t_stack **a, t_stack **b);

//! Action
void				push(t_stack **src, t_stack **dest);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **head);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rotate(t_stack **head);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				swap(t_stack **lst);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

//! cration de la pille via arg et assignation de tout les id
int					ft_isnumber(char *str);
t_stack				*create_stack(int argc, char **argv);
void				bubble_sort(int *tab, int size);
void				assign_indices(t_stack *a, int size);
int					stack_size(t_stack *stack);
void				quick_sort(int *arr, int low, int high);
int					partition_func(int *arr, int low, int high);
int	is_dooble(int argc, char **argv);

//! utils
void				ft_putstr_fd(char *s, int fd);
void				ft_exit_error(void);
int					ft_atoi(const char *str);
int					ft_strlen(char *s);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				print_list(t_stack **head);
t_stack				*ft_create_node(int value);
void				print_node(t_stack *current);
void				ft_putchar(char c);
void				ft_putnbr(int n);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strdup(char *s1);
int					set_last(t_stack **lst);
int					set_prev(t_stack **lst);
int					is_sorted(t_stack *stack);
void				free_stack(t_stack **a);

// //!juste split
// void	free_split(char **split, int words);
// int	count_words(char *s, char c);
// char	*get_next_word(char *s, char c, int *index);
// char	**allocate_and_fill(char *s, char c);
// char	**ft_split(char *s, char c);

#endif