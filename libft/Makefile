include mk.var.local/Makefile

include ft_lib/mk.var/Makefile
include ft_printf/mk.var/Makefile
include get_next_line/mk.var/Makefile

NAME		= libft.a

OBJS		= $(addprefix ft_lib/, $(FTLIB_OBJS)) \
			$(addprefix ft_printf/, $(PF_OBJS)) \
			$(addprefix get_next_line/, $(GNL_OBJS))
			
SUBPROJECTS	= $(patsubst %/objs/, %, $(sort $(dir $(OBJS))))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "==> Collecting objects and building $(NAME)"
	$(AR) $@ $(OBJS)

$(OBJS):
	$(foreach dir, $(SUBPROJECTS), $(MAKE) objects -C $(dir);)

clean:
	@$(foreach dir, $(SUBPROJECTS), $(MAKE) clean -C $(dir);)

fclean: clean
	$(RM) $(NAME)
	@$(foreach dir, $(SUBPROJECTS), $(MAKE) fclean -C $(dir);)

re: fclean all

.PHONY: all clean fclean re $(SUBPROJECTS)
