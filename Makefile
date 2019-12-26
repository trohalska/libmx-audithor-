NAMEA = libmx.a

INC = libmx.h
SRC = *.c
OBJ = *.o
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
	@cp src1/_main.c .

install:
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rcs $(NAMEA) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(NAMEA)

clean:
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
