include libraries/mk.var/Makefile

NAME = bin/so_long

#──────────────────────────────────────────#
# Compiler and system directives and flags #
#──────────────────────────────────────────#
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
MKDIR	= mkdir -p

# Build directories
BUILD_DIR	= build
SRCS_DIR	= sources
BIN_DIR		= bin

# External libraries paths
MLX_DATA_PATH	= libraries/datalib
COLORS_PATH		= libraries/colors
MLX_PATH		= minilibx-linux
LIBFT_PATH		= LIBFT_EXTENSIBLE

# External libraries names (for dependencies)
LIBRARIES = $(MLX_DATA_PATH)/$(MLX_DATA_LIB) \
			$(COLORS_PATH)/$(COLORS_LIB) \
			$(MLX_PATH)/libmlx.a

# Project files
SRCS_NAMES = main.c map_parser.c assets_checker.c
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS_NAMES:%.c=%.o))
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

# Include paths and link flags
INC_PATHS = -I$(MLX_PATH) -I$(MLX_DATA_PATH) -I$(COLORS_PATH) \
			-I$(LIBFT_PATH)/headers -Iheaders

LIB_PATHS = -L$(MLX_PATH) -L$(MLX_DATA_PATH) -L$(COLORS_PATH) \
			-L$(LIBFT_PATH)

LIB_NAMES = -lmlx_data -lcolors -lmlx -lft -lm -lX11 -lXext

# === ========== === #
# === MAIN RULES === #
# === ========== === #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(NAME):  $(OBJS)  $(LIBRARIES) | $(BIN_DIR)
	$(CC) $(OBJS) $(LIB_PATHS) $(LIB_NAMES) -no-pie -o $(NAME)

$(BIN_DIR) $(BUILD_DIR):
	$(MKDIR) $@

# === ======== ========= =========== === #
# === EXTERNAL LIBRARIES COMPILATION === #
# === ======== ========= =========== === #

$(MLX_DATA_PATH)/$(MLX_DATA_LIB): $(MLX_DATA_PATH)/$(MLX_DATA_OBJS)

$(MLX_DATA_PATH)/$(MLX_DATA_OBJS): $(MLX_DATA_PATH)/$(MLX_DATA_SRCS)
	$(MAKE) -C $(MLX_DATA_PATH)

$(COLORS_PATH)/$(COLORS_LIB): $(COLORS_PATH)/$(COLORS_OBJS)

$(COLORS_PATH)/$(COLORS_OBJS): $(COLORS_PATH)/$(COLORS_SRCS)
	$(MAKE) -C $(COLORS_PATH)

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

# === ========= === ================ === #
# === CLEANINGS AND RECOMPILITATIONS === #
# === ========= === ================ === #

# Project Only
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Project and External Libraries
deepclean: clean
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(MLX_DATA_PATH)
	$(MAKE) clean -C $(COLORS_PATH)

deepfclean: fclean		
	$(MAKE) clean -C  $(MLX_PATH)
	$(MAKE) fclean -C $(MLX_DATA_PATH)
	$(MAKE) fclean -C $(COLORS_PATH)
	
deepre: deepfclean all

# === PHONY === #
.PHONY: all re clean fclean deepre deepclean deepfclean
