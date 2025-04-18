/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:14 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/15 17:42:42 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if (temp_c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
	}
}

void	handle_read_receipt(int sig)
{
	if (sig == SIGUSR1)
		write(1, "[1]", 3);
	if (sig == SIGUSR2)
		write(1, "[0]", 3);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	if (argc != 3)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" <pid> <message>\n");
		exit(0);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
