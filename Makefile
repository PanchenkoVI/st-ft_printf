HEAD = libftprintf.h

NAME = libftprintf.a

SRC = print_hex.c \
	first_way.c \
	flags.c \
	ft_printf.c \
	ft_transformation.c \
	second_way.c \
	spac_trans_cllc.c \
	struct.c \
	utuls.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD) 
	@ar -rcs $(NAME) $(OBJS)
	@echo "Objects created"

%.o: %.c
	@gcc -Wall -Werror -Wextra -I ./ -c $<  -o $(<:.c=.o)
	@echo "Objects created"

clean :
	@rm -f $(OBJS)
	@echo "Objects deleted"

fclean : clean
	@rm -f $(NAME)
	@echo "Objects deleted"

re : fclean all

.PHONY: all re fclean clean