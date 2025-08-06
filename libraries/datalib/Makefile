include mk.var/Makefile

CC      = gcc
AR      = ar rcs
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

INCLUDES	= -I../../minilibx-linux

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all
