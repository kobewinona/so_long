.PHONY: all clean fclean re asan

NAME			= so_long
ASAN_NAME		= so_long_asan

CC				= gcc
#CFLAGS			= -Wall -Wextra -Werror -MMD
CFLAGS			= -MMD
ASAN_FLAGS		= -fsanitize=address
RM				= rm -rf
INCLUDES		= ./includes
LIBFT			= -lft
LIBFTPRINTF		= -lftprintf
LIBGNL			= -lgnl
MINILIBX		= -lmlx -framework OpenGL -framework AppKit

SRCS_DIR		= ./src
UTILS_DIR		= ./utils
LIBS_DIR		= ./libs
MINILIBX_DIR	= $(LIBS_DIR)/minilibx_macos
OBJS_DIR		= ./obj

rwildcard		= $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SRCS			= $(call rwildcard, $(SRCS_DIR)/, *.c) $(call rwildcard, $(UTILS_DIR)/, *.c)
OBJS 			= $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPS 			= $(OBJS:.o=.d)

LIBS			= -L$(MINILIBX_DIR) $(MINILIBX) -L$(LIBS_DIR) $(LIBFT)
LIBS			+= -L$(LIBS_DIR) $(LIBFTPRINTF) -L$(LIBS_DIR) $(LIBGNL)

all: $(MINILIBX_DIR)/libmlx.a $(NAME) asan

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) -I$(INCLUDES)

asan: $(OBJS)
	$(CC) $(ASAN_FLAGS) $(OBJS) -o $(ASAN_NAME) $(LIBS) -I$(INCLUDES)
	
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS_DIR) $(DEPS)

fclean: clean
	$(RM) $(NAME) $(ASAN_NAME)

re: fclean all