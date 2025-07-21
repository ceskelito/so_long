NAME = bin/so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
MKDIR	= mkdir -p

BUILD_DIR	= build
SRCS_DIR	= sources
BIN_DIR		= bin

SRCS_NAMES = main.c map_parser.c
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS_NAMES:%.c=%.o))
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

INC_PATHS = -Iminilibx-linux -Ilibraries/datalib -Ilibraries/colors \
			-Ilibft/headers -Iheaders

LIB_PATHS = -Lminilibx-linux -Llibraries/datalib -Llibraries/colors \
			-Llibft

LIB_NAMES = -ldatalib -lmlx -lft -lm -lX11 -lXext 

vpath %.c sources/

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	@echo "$@"
	$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $^ $(LIB_PATHS) $(LIB_NAMES) -no-pie -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
