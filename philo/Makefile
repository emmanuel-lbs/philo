#############################  MAKEFILE MINITALK  #############################

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 14:01:13 by elabasqu          #+#    #+#              #
#    Updated: 2021/06/23 14:01:13 by elabasqu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##############################  SOURCE & OBJETS  ###############################

SRCS = src/main.c \
	   src/parsing.c \
	   src/time.c	\
	   src/init.c	\
	   src/algo.c	\
	   src/its_no_libft/ft_atoi.c \
	   src/its_no_libft/ft_itoa.c \
	   src/its_no_libft/ft_strncmp.c \
	   src/its_no_libft/ft_strlen.c \

OBJS = $(SRCS:.c=.o)

################################  VARIABLES  ###################################

NAME = philo

INCLUDE = includes/philo.h includes/structure.h

RM = rm -f

GCCF = gcc -Wall -Wextra #-Werror

##################################  RULES  #####################################

all :	libf $(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
	$(GCCF) $(OBJS) -o $(NAME)

%.o: %.c	$(INCLUDE) 
	${GCCF} -c $< -o $@


############################  CLEAN & RE & phony  ##############################

clean:
	${RM} ${OBJS} 

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus libf

#################################### FIN  ######################################
