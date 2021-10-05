CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

NAME	=	do-op

SDIR	=	./sources/
HDIR	=	./includes/

SRCS	=	do-op.c operators.c utils.c
HDRS	=	utils.h
OBJ		=	$(SRCS:.c=.o)

S		=	$(addprefix $(SDIR), $(SRCS))
H		=	$(addprefix $(HDIR), $(HDRS))
O		=	$(addprefix $(SDIR), $(OBJ))

RM		=	rm -rf

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(O)
	@$(CC) $(FLAGS) -o $(NAME) $(O)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HDIR)

clean:
	@$(RM) $(O)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all