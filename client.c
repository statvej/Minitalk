/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:00:06 by fstaryk           #+#    #+#             */
/*   Updated: 2022/06/18 14:45:22 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/client.h"

void	wrong_pid(void)
{
	ft_putstr_fd(WRONG_PID_MSG, STDERR_FILENO);
	exit(0);
}

void	send_byte(char byte, int pid)
{
	int	i;
	int	kill_ret;

	kill_ret = 0;
	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill_ret = kill(pid, SIGUSR2);
		else
			kill_ret = kill(pid, SIGUSR1);
		if (kill_ret == -1)
			wrong_pid();
		usleep(100);
		i--;
	}
}

void	send_message(char *msg, int pid)
{
	while (*msg)
	{
		send_byte(*msg, pid);
		msg++;
	}
	send_byte(0, pid);
}

void	msg_recieved(int sig)
{
	ft_printf("Message was recieved\n");
}

int	main(int ac, char *av[])
{
	int		pid;

	signal(SIGUSR1, msg_recieved);
	if (ac != 3)
	{
		ft_putstr_fd(USAGE_MSG, STDERR_FILENO);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	if (!av[2][0])
		ft_putstr_fd(EMPTY_MSG, STDERR_FILENO);
	send_message(av[2], pid);
	return (0);
}
