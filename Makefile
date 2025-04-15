# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaiane <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 19:10:29 by jaiane            #+#    #+#              #
#    Updated: 2025/04/15 19:10:38 by jaiane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = helpers.c
HEADERS = minitalk.h

all: client server

bonus: client_bonus server_bonus

client: client.c $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o client client.c $(SRCS)

client_bonus: client_bonus.c $(SRCS) $(HEADERS)
	 $(CC) $(CFLAGS) -o client_bonus client_bonus.c $(SRCS)

server: server.c $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o server server.c $(SRCS)

server_bonus: server_bonus.c $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o server_bonus server_bonus.c $(SRCS)

clean:
	rm -f client server client_bonus server_bonus

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
