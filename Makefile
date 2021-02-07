# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izouiten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 14:08:15 by izouiten          #+#    #+#              #
#    Updated: 2019/09/27 15:32:51 by izouiten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

FLAGS= -Wall -Wextra -Werror

FILES=  files/fillit.c files/reader.c files/solve.c files/solve1.c libft/libft.a

HEADERS= files/fillit.h

HEADERS_LIBFT= libft/libft.h

OBJ = files/fillit.o files/reader.o files/solve.o files/solve1.o

all: $(NAME)

$(NAME): #$(OBJ)
	@make re -C libft
	@gcc $(FLAGS) $(FILES) -I $(HEADERS) -I $(HEADERS_LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re:     fclean all
