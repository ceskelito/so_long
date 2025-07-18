NAME = bin/so_long

SRCS_NAMES = main.c
OBJS = $(addprefix build/, $(SRCS_NAMES:%.c=%.o))
SRCS = $(addprefix sources/, $(SRCS_NAMES))

CC		= gcc
CFLAGS	= -g
RM		= rm -f

LIBRARIES	= minilibx-linux libraries/datalib libraries/colors

INC_PATHS = $(addprefix -I,$(LIBRARIES))
LIB_PATHS = $(addprefix -L,$(LIBRARIES))
LIB_NAMES = -lmlx -lm -lX11 -lXext -ldatalib

vpath %.c=sources/

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(I_PATHS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ $(LIB_PATHS) $(LIB_NAMES) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
