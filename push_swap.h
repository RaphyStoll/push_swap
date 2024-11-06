#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
						int lst_size, int fd);

//! Algo 2 - 5
void				small_algo(t_stack **a, t_stack **b, int lst_size, int fd);
void				sort_2(t_stack **a, int fd);
void				sort_3(t_stack **a, int fd);
void				sort_4(t_stack **a, t_stack **b, int fd);
void				sort_5(t_stack **a, t_stack **b, int fd);

//! Algo 5 - 100
void				quick_sort_a_3_voies(t_stack **a, t_stack **b, int lst_size,
						int fd);
void				partition_stack_a(t_stack **a, t_stack **b, int pivot,
						int fd);
int					find_pivot(int lst_size,t_stack *stack);
//! algo utils
void				find_smallest(t_stack **a, t_stack **b, int fd);
void				find_biggest(t_stack **a, t_stack **b, int fd);

//! Action
void				push(t_stack **src, t_stack **dest);
void				pa(t_stack **a, t_stack **b, int fd);
void				pb(t_stack **a, t_stack **b, int fd);
void				reverse_rotate(t_stack **head);
void				rra(t_stack **a, int fd);
void				rrb(t_stack **b, int fd);
void				rrr(t_stack **a, t_stack **b, int fd);
void				rotate(t_stack **head);
void				ra(t_stack **a, int fd);
void				rb(t_stack **b, int fd);
void				rr(t_stack **a, t_stack **b, int fd);
void				swap(t_stack **lst);
void				sa(t_stack **a, int fd);
void				sb(t_stack **b, int fd);
void				ss(t_stack **a, t_stack **b, int fd);

//! cration de la pille via arg et assignation de tout les id
int					ft_isnumber(char *str);
t_stack				*create_stack(int argc, char **argv);
void				bubble_sort(int *tab, int size);
void				assign_indices(t_stack *a, int size);
int					stack_size(t_stack *stack);
void	quick_sort(int *arr, int low, int high);
int	partition_func(int *arr, int low, int high);

//! utils
void				ft_putstr_fd(char *s, int fd);
void				ft_exit_error(void);
int					ft_atoi(const char *str);
int					ft_strlen(char *s);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				print_list(t_stack **head, int fd);
t_stack				*ft_create_node(int value);
void				print_node(t_stack *current, int fd);
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