#include "minitalk.h"

void	signal_client(char s, pid_t id)
{
	int	bit;
	int	k;

	bit = 8;
	while (bit != 0)
	{
		--bit;
		if ((s >> bit & 1) != 0)
		{
			k = kill(id, SIGUSR1);
		}
		else
		{
			k = kill(id, SIGUSR2);
		}
		if (k == -1)
		{
			ft_putstr("ERROR: Invalid Process ID\n");
			exit(1);
		}
		usleep(120);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	id;

	i = 0;
	if (argc != 3 || argv[2] == NULL)
	{
		ft_putstr("Arguments should be: ./client [pid] [string]\n");
		exit(1);
	}
	id = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		signal_client(argv[2][i], id);
		i++;
	}
	signal_client(argv[2][i], id);
}
