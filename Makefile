# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:34:39 by mbortnic          #+#    #+#              #
#    Updated: 2018/02/18 12:34:42 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mbortnic.filler

SRC = ft_piece.c \
		ft_utils.c \
		ft_utils2.c \
		ft_utils3.c \
		main.c

INC = ft_filler.h

CFLAGS = -Wall -Wextra -Werror -I.

OBJ = $(SRC:.c=.o)

LIBD = ./libft/

RM = rm -f

all: $(NAME)


$(NAME): $(OBJ) $(LIBD)libft.a
	gcc -I $(INC) $(OBJ) -o $(NAME) -L$(LIBD) -lft
	@ echo "\033[32;1mfiller is ready\033[0m"

%.o: %.c
	gcc -I $(INC) -c $< -o $@

$(LIBD)libft.a:
	make -C $(LIBD)

clean:
	make clean -C $(LIBD)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBD)
	$(RM) $(NAME)

re: fclean all

norm:
	@ echo "\033[35;1mWait a sec.\033[0m"
	norminette *.c *.h ./libft/*.c *.h
	@ echo "\033[35;1mnorminette check finished\033[0m"

.PHONY: all clean fclean re norm




# all: $(NAME)

# $(NAME): $(OBJ)
# 	make -C libft
# 	gcc -o $(NAME) $(CFLAGS) $(OBJ) libft/libft.a
# 	@ echo "\033[32;1mfiller is ready\033[0m"

# clean:
# 	make -C clean ./libft/
# 	$(RM) $(OBJ)
# 	@ echo "\033[33;1mobj files are removed\033[0m"

# fclean:
# 	make -C fclean ./libft/
# 	$(RM) $(NAME)
# 	@ echo "\033[31;m$(NAME) is deleted\033[0m"

# re: fclean all
# 	@ echo "\033[36;1mre performed\033[0m"

# norm:
# 	@ echo "\033[35;1mWait a sec.\033[0m"
# 	norminette *.c *.h ./libft/*.c *.h
# 	@ echo "\033[35;1mnorminette check finished\033[0m"

# .PHONY: all clean fclean re norm