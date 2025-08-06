include libraries/mk.var.export/Makefile
include LIBFT_EXTENSIBLE/mk.var.export/Makefile

# ─── ────────── ─── #
NAME = bin/so_long
# ─── ────────── ─── #
RED    := \033[0;31m
GREEN  := \033[0;32m
BLUE   := \033[0;34m
RESET  := \033[0m
# ─── ────────── ─── #

# Compiler and system directives and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
MKDIR	= mkdir -p

# Build directories
BUILD_DIR	= build
SRCS_DIR	= sources
BIN_DIR		= bin

# Paths -- if not specified it was included in mk.var.export
LIBFT_PATH	= LIBFT_EXTENSIBLE
MLX_PATH	= minilibx-linux

# External libraries names (for dependencies)
LIBRARIES	= $(MLXD_LIB) \
				$(COLORS_LIB) \
				$(LIBFT_PATH)/libft.a \
				$(MLX_PATH)/libmlx.a

# Project files
SRCS_NAMES = assets_checker.c flood_fill.c main.c map_parser.c map_parser_2.c map_helper_functions.c movement.c giwt.c utils.c
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS_NAMES:%.c=%.o))
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

# Include paths and link flags
INC_PATHS = -I$(MLX_PATH) -I$(MLXD_PATH) -I$(COLORS_PATH) \
			-I$(LIBFT_PATH)/headers -Iheaders

LIB_PATHS = -L$(MLX_PATH) -L$(MLX_DATA_PATH) -L$(COLORS_PATH) \
			-L$(LIBFT_PATH)

LIB_NAMES = -lmlx_data -lcolors -lmlx -lft -lm -lX11 -lXext

# ─── ────────── ─── #
# === MAIN RULES === #
# ─── ────────── ─── #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(NAME):  $(OBJS)  $(LIBRARIES) | $(BIN_DIR)
	$(CC) $(OBJS) $(LIB_PATHS) $(LIB_NAMES) -no-pie -o $(NAME)

$(BIN_DIR) $(BUILD_DIR):
	$(MKDIR) $@

# ─── ────────────────────────────── ─── #
# === EXTERNAL LIBRARIES COMPILATION === #
# ─── ────────────────────────────── ─── #

# Every variable has the path included in itself
$(MLXD_LIB): $(MLXD_OBJS)

$(MLXD_OBJS): $(MLXD_SRCS)
	$(MAKE) -C $(MLXD_PATH)

$(COLORS_LIB): $(COLORS_OBJS)

$(COLORS_OBJS): $(COLORS_SRCS)
	$(MAKE) -C $(COLORS_PATH)

$(LIBFT_PATH)/libft.a: $(LIBFT_OBJS)

$(LIBFT_OBJS): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_PATH)

MLX_EXISTS := $(shell test -f $(MLX_PATH)/libmlx.a && echo "yes" || echo "no")
ifeq ($(MLX_EXISTS), no)
    $(info $(shell echo "\n$(RED)Error: The minilibx-linux library is not compiled."))
    $(info $(shell echo "$(BLUE)"))
    $(info $(shell echo "Since the minilibx-linux library is not included in the repository,"))
    $(info $(shell echo "please compile it manually by running $(GREEN)'make'$(BLUE) in the $(GREEN)minilibx-linux$(BLUE) directory."))
    $(info $(shell echo "$(RESET)"))
    $(error impossible to compile $(NAME) due to missing minilibx library)
endif

## $(MLX_PATH)/libmlx.a: print_suggestion
## 	$(error impossible to compile $(NAME) due to the previous error(s))
## 
## print_suggestion:
## 	@echo "\n$(RED)Error: The minilibx-linux library is not compiled."
## 	@echo "$(BLUE)"
## 	@echo "Since the minilibx-linux library is not included in the repository,"
## 	@echo "please compile it manually by running $(GREEN)'make'$(BLUE) in the $(GREEN)minilibx-linux$(BLUE) directory."
## 	@echo "$(RESET)"
	
# ─── ────────────────────────────── ─── #
# === CLEANINGS AND RECOMPILITATIONS === #
# ─── ────────────────────────────── ─── #

# Project Only
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Project and External Libraries
deepclean: clean
	$(MAKE) clean -C $(MLXD_PATH)
	$(MAKE) clean -C $(COLORS_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)

deepfclean: fclean		
	$(MAKE) fclean -C $(MLXD_PATH)
	$(MAKE) fclean -C $(COLORS_PATH)
	$(MAKE) fclean -C $(LIBFT_PATH)

deepre: deepfclean all

# === PHONY === #
.PHONY: all re clean fclean deepre deepclean deepfclean print_suggestion
