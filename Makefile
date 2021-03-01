NAME = libasm.a
HEADER = libasm.h

SRC = ft_read.s ft_strcmp.s ft_strcpy.s \
	ft_strdup.s ft_strlen.s ft_write.s

OBJ = $(SRC:.s=.o)

%.o	: %.s
	@nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $@ $(OBJ)
	@ranlib $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re