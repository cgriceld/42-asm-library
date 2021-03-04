NAME = libasm.a
HEADER = libasm.h
TEST = test

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s \
		ft_write.s ft_read.s

OBJ = $(SRC:.s=.o)

%.o	: %.s
	@nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $@ $(OBJ)
	@ranlib $@

test: all main.c
	@$(CC) $(CFLAGS) -L. -lasm main.c -o $(TEST) && ./$(TEST)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(TEST)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re