/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:04:11 by fstaryk           #+#    #+#             */
/*   Updated: 2022/06/17 18:05:49 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libftprintf/inc/libftprintf.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

typedef struct s_temp_state{
	int		i;
	char	prog_char;
	int		client_pid;
}t_temp_state;

void	init_temp_state(void);
void	sig_handle(int sig, siginfo_t *info, void *ucontext);

#endif