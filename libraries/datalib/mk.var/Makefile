NAME	:= libmlx_data.a
SRCS	:= libmlx_data.c img_4_byte.c
OBJS	:= $(SRCS:%.c=%.o)

# For export
MPATH	:= $(patsubst %/, %, $(dir $(abspath $(dir $(lastword $(MAKEFILE_LIST))))))
