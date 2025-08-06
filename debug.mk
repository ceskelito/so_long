include libraries/mk.var.export/Makefile


#LIBRARIES	= $(MLXD_LIB) \
#				$(COLORS_LIB) \
#				$(LIBFT_PATH)/libft.a \
#				$(MLX_PATH)/libmlx.a
#
# ─── ────────── ─── #
# === MAIN RULES === #
# ─── ────────── ─── #

debug:
	@echo "MLXD:\n"
	@echo "path: $(MLXD_PATH)"
	@echo "lib: $(MLXD_LIB)"
	@echo "objs: $(MLXD_OBJS)"
#	@echo "COLORS PATH: $(COLORS_PATH)"
