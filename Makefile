##
## EPITECH PROJECT, 2025
## my_make
## File description:
## make assembly
##

SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/strrchr.asm	\
		src/strcmp.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strncmp.asm	\
		src/memmove.asm	\
		src/strcasecmp.asm	\
		src/strstr.asm	\
		src/strpbrk.asm	\
		src/strcspn.asm	\
		src/memfrob.asm	\
		src/ffs.asm

NAME	=	libasm.so

NASM	=	nasm

ASM_FLAGS	=	-f elf64

SHARED_FLAG	=	-shared

RENAME_FLAG	=	-o

CRITERION_FLAG	=	--coverage -lcriterion

CRITERION_BINARY	=	unit_tests

LD	=	ld

OBJ		=	$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) $(RENAME_FLAG) $(NAME) $(SHARED_FLAG) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o : %.asm
	$(NASM) $(ASM_FLAGS) $(RENAME_FLAG) $@ $<

compil:
	$(CC) main.c $(RENAME_FLAG) test -L. -lasm -fno-builtin

tests_run:	all
	$(CC) tests/tests_run.c $(RENAME_FLAG) $(CRITERION_BINARY) $(CRITERION_FLAG)
	./$(CRITERION_BINARY)

.PHONY: all $(NAME) clean fclean re %.o compil tests_run