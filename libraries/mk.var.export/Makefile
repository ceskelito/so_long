LOCAL_PATH	:= $(patsubst %/, %, $(dir $(abspath $(dir $(lastword $(MAKEFILE_LIST))))))

include $(LOCAL_PATH)/datalib/mk.var/Makefile

MLXD_PATH	:= $(MPATH)
MLXD_LIB	:= mlx_data
MLXD_NAME	:= $(addprefix $(MLXD_PATH)/, $(NAME))
MLXD_SRCS	:= $(addprefix $(MLXD_PATH)/, $(SRCS))
MLXD_OBJS	:= $(addprefix $(MLXD_PATH)/, $(OBJS))


include $(LOCAL_PATH)/colors/mk.var/Makefile

COLORS_PATH	:= $(MPATH)
COLORS_LIB	:= colors
COLORS_NAME	:= $(addprefix $(COLORS_PATH)/, $(NAME))
COLORS_SRCS	:= $(addprefix $(COLORS_PATH)/, $(SRCS))
COLORS_OBJS	:= $(addprefix $(COLORS_PATH)/, $(OBJS))
