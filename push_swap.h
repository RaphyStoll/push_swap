#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} t_stack;

int main (int argc, char **argv); 

#endif