NAME = bin/so_long

CC		= gcc
CFLAGS	= -g
RM		= rm -f
MKDIR	= mkdir -p

BUILD_DIR	= build
SRCS_DIR	= sources
BIN_DIR		= bin

SRCS_NAMES = main.c
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS_NAMES:%.c=%.o))
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

LIBRARIES	= minilibx-linux libraries/datalib libraries/colors LIBFT_EXTENSIBLE 

INC_PATHS = $(addprefix -I,$(LIBRARIES))
LIB_PATHS = $(addprefix -L,$(LIBRARIES))
LIB_NAMES = -ldatalib -lmlx -lft -lm -lX11 -lXext 

vpath %.c sources/

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	@echo "$@"
	$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $^ $(LIB_PATHS) $(LIB_NAMES) -o $@

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
