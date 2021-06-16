##
## EPITECH PROJECT, 2021
## week_1_synth-pool
## File description:
## Makefile
##

NAME	= fridge

CC	= gcc

RM	= rm -f

SRCS	=	./main.c \
			./my_strtok.c \
			./init.c \
			./cook.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -lm -L./lib -lmy  -g3

all: $(NAME)

$(NAME): $(OBJS)
	cd lib/my && make
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	$(RM) lib/my/libmy.a

re: fclean all

.PHONY: all clean fclean re
