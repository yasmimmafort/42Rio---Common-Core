
#include "minitalk.h"
#include <stdio.h>

void	check_signal(int sig)
{
	static int	bin;
	static char	chr;

	if (bin < 8)
	{
		if (sig == SIGUSR1)
			chr += (1 << (7 - bin));
		bin++;
	}
	if (bin == 8)
	{
		ft_printf("%c", chr);
		chr = 0;
		bin = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\t\t\tThe server pid is: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, check_signal);
		signal(SIGUSR2, check_signal);
		pause();
	}
}
