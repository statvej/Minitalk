/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:03:10 by fstaryk           #+#    #+#             */
/*   Updated: 2022/06/17 18:04:04 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libftprintf/inc/libftprintf.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

void	wrong_pid(void);
void	send_byte(char byte, int pid);
void	send_message(char *msg, int pid);
void	msg_recieved(int sig);

# define USAGE_MSG "usage is : client [server PID] [message]\n"
# define WRONG_PID_MSG "PID is unreachable\n"
# define DELIVERY_MSG "Message have been succesful\n"
# define EMPTY_MSG "Message can't be empty"

#endif
