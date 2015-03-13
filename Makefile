CC	= gcc
RM	= rm -fr

NAME	= khelljyr

SRC	= src/main.c
SRC	+= src/compile.c
SRC	+= src/add_resource.c
SRC	+= src/examples.c
SRC	+= src/env.c
SRC	+= src/clean.c
SRC	+= src/logs.c
SRC	+= src/exec.c
SRC	+= src/install.c
SRC	+= src/ins.c
SRC	+= src/install_js.c
SRC	+= src/create_project.c
SRC	+= src/project_update.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wextra -Wall -O2 -Isrc/

CLIBS	= -ljansson

all: jansson $(NAME)

jansson:
	git clone https://github.com/akheron/jansson
	cd jansson && cmake . && make && sudo make install

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CLIBS)

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)
	$(RM) jansson

re: fclean all

install: all
	sudo cp $(NAME) /bin/

.PHONY: all clean fclean re
