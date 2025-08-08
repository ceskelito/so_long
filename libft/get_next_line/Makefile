include ../mk.var.local/Makefile
include mk.var/Makefile

NAME		= libgnl.a
OBJS_DIR	= $(GNL_OBJS_DIR)
OBJS		= $(GNL_OBJS)

vpath %.c .

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

objects: $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re objects
