#include "push_swap.h"

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[count])
		write(1, str[count], 1);
}

void	ft_exit_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int ft_printf