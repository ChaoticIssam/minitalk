#include "minitalk.h"

void	signal_server(int sign)
{
	static int	bit;
	static char	f;

	f |= (sign == SIGUSR1);
	if (++bit == 8)
	{
		ft_putchar(f);
		bit = 0;
		f = 0;
	}
	else
		f = f << 1;
}

int	main(void)
{
	pid_t	p;

	p = getpid();
	ft_putstr("Running...\n");
	ft_putstr("Process ID: ");
	ft_putnbr(p);
	ft_putchar('\n');
	signal(SIGUSR1, signal_server);
	signal(SIGUSR2, signal_server);
	while (1)
		pause();
}
