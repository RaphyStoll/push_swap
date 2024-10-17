#include "push_swap.h"


char generate_list(char *argv)
{
	int count = 0;
	t_stack *a;
	while (argv[count])
	{
		a = malloc(sizeof(t_stack));
		a->value = argv[count];
		a->next = NULL;
		count++;
	}
}


int main (int argc, char **argv)
{
	if (argc < 0)
	{
		return (puts("errror argc"));
	}
	while(argv[count], count++)
		generate_list(argv[count]);
}
