# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 11:12:37 by irodrigo          #+#    #+#              #
#    Updated: 2020/07/22 01:13:47 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

NAMEBONUS=libftprintf_bonus.a

cc=gcc

CFLAGS=-Wall -Werror -Wextra

RM=rm -f

LDFLAGS=-L

SRC=libftprintf.c ft_aux_utils.c ft_display.c ft_printf.c ft_printc.c ft_printf_threatment.c ft_printf_utils.c ft_print_w.c ft_print_s.c ft_print_d.c ft_print_x.c ft_print_u.c ft_print_o.c ft_print_p.c ft_print_sw.c ft_itoa_base.c

SRCBONUS=libftprintf_bonus.c ft_aux_utils_bonus.c ft_display_bonus.c ft_printf_bonus.c ft_printc_bonus.c ft_printf_threatment_bonus.c ft_printf_utils_bonus.c ft_print_w_bonus.c ft_print_s_bonus.c ft_print_d_bonus.c ft_print_x_bonus.c ft_print_u_bonus.c ft_print_o_bonus.c ft_print_p_bonus.c ft_print_sw_bonus.c ft_itoa_base_bonus.c

OBJ=$(SRC:.c=.o)

OBJBONUS=$(SRCBONUS:.c=.o)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -c -I libft  $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ) ./libft/*.o
	ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|  libftprintf.a  |"
	@echo "|   was created   |"
	@echo "[=================]"

all: $(NAME)

bonus:
	make -C libft
	@$(CC) $(CFLAGS) -c $(SRC) $(SRCBONUS) $(HDDIRS)
	ar rc $(NAMEBONUS) $(OBJBONUS)
	ranlib $(NAMEBONUS)
	@echo $(SRCBONUS)
	@echo "[====================]"
	@echo "|       succes !     |"
	@echo "|libftprintf_bonus.a |"
	@echo "|     was created    |"
	@echo "[====================]"

debug:
	$(CC) $(CFLAGS) main.c $(SRC) ./libft/*.c -g

compile:
	$(CC) $(CFLAGS) main.c $(SRC) ./libft/*.c

crun: compile
	clear
	./a.out

clean:
	@$(RM) $(OBJ) $(OBJBONUS)
	@echo "[===============]"
	@echo "|   success!    |"
	@echo "|    xxxx.o     |"
	@echo "|  was deleted  |"
	@echo "[===============]"

fclean: clean
	@$(RM) $(NAME) $(NAMEBONUS) $(OBJ) $(OBJBONUS)
	@echo "[===============]"
	@echo "|    success!   |"
	@echo "| libftprintf.a |"
	@echo "|  was removed  |"
	@echo "[===============]"

re: fclean all

.PHONY:clean fclean
