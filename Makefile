CC	= gcc
RM	= rm -fr

NAME	= khelljyr

SRC	= src/main.c
SRC	+= src/exec.c
SRC	+= src/install_js.c
SRC	+= src/create_project.c
SRC	+= src/project_update.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wextra -Wall -O2 -Isrc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)


re: fclean all

install:
	sudo cp $(NAME) /bin/

.PHONY: all clean fclean re
