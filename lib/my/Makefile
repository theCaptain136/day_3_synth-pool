##
## EPITECH PROJECT, 2020
## a
## File description:
## a
##

SRC	= 	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CLEAN 	= 	SAUBER

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

clean:	$(CLEAN)

$(CLEAN):
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: 	fclean
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..