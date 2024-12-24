# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 06:16:42 by yabenman          #+#    #+#              #
#    Updated: 2024/12/24 03:03:33 by yabenman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all : server client


server : server.c minitalk_utils.c $(INC) 
						cc $(CFLAGS) server.c minitalk_utils.c -o server

client : client.c minitalk_utils.c $(INC)
						cc $(CFLAGS) client.c minitalk_utils.c -o client



clean :

fclean : clean
					rm -rf server client

re : fclean all