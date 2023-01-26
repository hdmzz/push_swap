#include "libft/libft.h"

void	insert


int	main(int ac, char **av)
{
	int	*stack_a;
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac <= 2)
	{
		ft_printf("Il faut une liste d'entiers à trier");
		exit(EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(int) * (ac - 1));
	if (!stack_a)
		exit(EXIT_FAILURE);
	while (i < ac)
	{
		stack_a[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	for (int x = 0; x < ac - 1; x++)
	{
		ft_printf("%d\n", stack_a[x]);
	}
}
