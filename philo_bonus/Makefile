# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/07/05 15:40:26 by ezequeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_main.c $(shell find src/ -name '*.c')

OBJS		= 		$(SRCS:.c=.o)
CC			= 		gcc
# -pthread -fsanitize=thread
CFLAGS		= 		-Wall -Wextra -Werror -lpthread -fsanitize=thread
LIB			= 		ar rcs
RM			= 		/bin/rm -f
NAME		= 		philo
INCLUDES	= 	-Iheaders/
LIBS 		+= 	-lpthread -lrt

all: $(NAME) 

$(NAME): $(OBJS)
		@$(CC) $(^) -o $(@)
		
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
						$(RM) $(NAME)
				
m: fclean				

re			:		fclean all

m			: 		clean fclean

r			: 		
					make re && clear && ./philo
