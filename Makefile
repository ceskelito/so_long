# ──────────────────────── #
#    EXTERNAL INCLUDES     #
# ──────────────────────── #
include libraries/mk.var.export/Makefile
include libft/mk.var.export/Makefile

# ──────────────────────── #
#      PROJECT CONFIG      #
# ──────────────────────── #
NAME       = bin/so_long
CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g
RM         = rm -f
MKDIR      = mkdir -p

# ──────────────────────── #
#        DIRECTORIES       #
# ──────────────────────── #
BUILD_DIR  = build
SRCS_DIR   = sources
BIN_DIR    = bin
LIBFT_PATH = libft
MLX_PATH   = minilibx-linux

# ──────────────────────── #
#      SOURCE FILES        #
# ──────────────────────── #
SRCS_NAMES = assets_checker.c flood_fill.c main.c map_parser.c map_parser_2.c \
             map_helper_functions.c movement.c utils.c
OBJS       = $(addprefix $(BUILD_DIR)/, $(SRCS_NAMES:%.c=%.o))
SRCS       = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

# ──────────────────────── #
#     EXTERNAL LIBRARIES   #
# ──────────────────────── #
MLX_LIB    = $(MLX_PATH)/libmlx.a
LIBRARIES  = $(MLXD_NAME) \
             $(COLORS_NAME) \
             $(LIBFT_PATH)/libft.a

# ──────────────────────── #
#      INCLUDE & LINK      #
# ──────────────────────── #
INC_PATHS  = -I$(MLX_PATH) -I$(MLXD_PATH) -I$(COLORS_PATH) \
             -I$(LIBFT_PATH)/headers -Iheaders

LIB_PATHS  = -L$(MLX_PATH) -L$(MLXD_PATH) -L$(COLORS_PATH) \
             -L$(LIBFT_PATH)

LIB_NAMES  = -l$(MLXD_LIB) -l$(COLORS_LIB) -lmlx -lft -lm -lX11 -lXext

# ──────────────────────── #
#        ANSI COLORS       #
# ──────────────────────── #
RED        := \033[0;31m
GREEN      := \033[0;32m
BLUE       := \033[0;34m
RESET      := \033[0m

# ──────────────────────── #
#       MAIN RULES         #
# ──────────────────────── #
all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@
	@printf "$(GREEN)Compiling $(BLUE)$<$(RESET)\n"

$(NAME): $(OBJS) $(LIBRARIES) | $(BIN_DIR)
	@if [ ! -f "$(MLX_LIB)" ]; then \
		echo "$(RED)\nNOTE: The minilibx-linux library is not compiled, and is necessary in order to link $(NAME).\n$(RESET)"; \
		echo "$(BLUE)Please compile it manually by running $(GREEN)'make -C minilibx-linux'$(BLUE),"; \
		echo "or running $(GREEN)'make'$(BLUE) in the $(GREEN)minilibx$(BLUE) directory.$(RESET)\n"; \
		exit 1; \
	else \
		printf "$(GREEN)\n- Minilibx-linux library is compiled yet. -\n\n$(RESET)"; \
	fi
	@$(CC) $(OBJS) $(LIB_PATHS) $(LIB_NAMES) -no-pie -o $(NAME)
	@printf "$(GREEN)Linking $(BLUE)$(NAME)$(RESET)\n"	

$(BIN_DIR) $(BUILD_DIR):
	$(MKDIR) $@

# ──────────────────────── #
#    LIBRARY COMPILATION   #
# ──────────────────────── #

# MLX Data Library
$(MLXD_NAME): $(MLXD_OBJS)

$(MLXD_OBJS): $(MLXD_SRCS)
	$(MAKE) -C $(MLXD_PATH)

# Colors Library
$(COLORS_NAME): $(COLORS_OBJS) 

$(COLORS_OBJS):$(COLORS_SRCS)
	$(MAKE) -C $(COLORS_PATH)

# Libft Library
$(LIBFT_PATH)/libft.a: $(LIBFT_OBJS)

$(LIBFT_OBJS): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_PATH)

# ──────────────────────── #
#      CLEANING RULES      #
# ──────────────────────── #
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
	@echo "\n$(GREEN)Deep clean completed.\n$(RESET)"
	@echo "$(RED)Note: This will not remove the minilibx-linux library files.$(RESET)"
	@echo "$(BLUE)You can do that by running $(GREEN)'make clean -C minilibx-linux'$(BLUE) from here, "
	@echo "or by running $(GREEN)'make clean'$(BLUE) in the minilibx-linux directory.\n$(RESET)"

deepfclean: fclean
	$(MAKE) fclean -C $(MLXD_PATH)
	$(MAKE) fclean -C $(COLORS_PATH)
	$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "\n$(GREEN)Deep fclean completed.\n$(RESET)"
	@echo "$(RED)Note: This will not remove the minilibx-linux library files.$(RESET)"
	@echo "$(BLUE)You can do that by running $(GREEN)'make clean -C minilibx-linux'$(BLUE) from here, "
	@echo "or by running $(GREEN)'make clean'$(BLUE) in the minilibx-linux directory.\n$(RESET)"

deepre: deepfclean all

# ──────────────────────── #
.PHONY: all re clean fclean deepre deepclean deepfclean
