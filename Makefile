NAMEA = libmx.a

INC = libmx.h
SRC = *.c
OBJ = *.o
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rcs $(NAMEA) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj

	@cp src1/_main.c .
	@clang $(CFLAGS) libmx.a _main.c -o a

uninstall: clean
	@rm -rf $(NAMEA)

clean:
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
