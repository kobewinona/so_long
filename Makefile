.PHONY: all clean fclean re asan

NAME		= so_long
ASAN_NAME	= so_long_asan

CC			= gcc
# CFLAGS		= -Wall -Wextra -Werror -MMD
CFLAGS		= -MMD
ASAN_FLAGS	= -fsanitize=address
RM			= rm -rf
INCLUDES	= ./includes
LIBFTPRINTF	= -lftprintf
MINILIBX	= -lmlx -framework OpenGL -framework AppKit

SRCS_DIR	= ./src
UTILS_DIR	= ./utils
LIBS_DIR	= ./libs
OBJS_DIR	= ./obj

rwildcard	= $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SRCS		= $(call rwildcard, $(SRCS_DIR)/, *.c) $(call rwildcard, $(UTILS_DIR)/, *.c)
OBJS 		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPS 		= $(OBJS:.o=.d)

all: $(LIBS_DIR)/minilibx_macos/libmlx.a $(NAME) asan

$(LIBS_DIR)/minilibx_macos/libmlx.a:
	make -C $(LIBS_DIR)/minilibx_macos
	
$(NAME): $(OBJS) $(INCLUDES)/libft.h $(INCLUDES)/libftprintf.h $(INCLUDES)/so_long.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBS_DIR)/minilibx_macos $(MINILIBX) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

asan: $(OBJS)
	$(CC) $(ASAN_FLAGS) $(OBJS) -o $(ASAN_NAME) -L$(LIBS_DIR)/minilibx_macos $(MINILIBX) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)
	
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
	
-include $(DEPS)

clean:
	$(RM) $(OBJS_DIR) $(DEPS)

fclean: clean
	$(RM) $(NAME) $(ASAN_NAME)

re: fclean all