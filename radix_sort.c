#include "push_swap.h"

void radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_bits = 0;
    int max_num = size - 1;
    int i, j;

    // Trouver le nombre maximum de bits nécessaires
    while ((max_num >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->id >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        // Réintégrer les éléments de b dans a
        while (*b != NULL)
            pa(a, b);
        i++;
    }
}
