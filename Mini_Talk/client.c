

#include "minitalk.h"

void	transform(int pid, char sign)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (sign & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Check the syntax: ./client server-pid text-to-send\n");
		return (0);
	}
	if (kill(ft_atoi(av[1]), 0) == -1)
	{
		ft_printf("Wrong pid, please check and try again!");
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		transform(pid, av[2][i]);
		i++;
	}
	return (0);
}
