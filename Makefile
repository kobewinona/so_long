.PHONY: all clean fclean re asan

NAME		= so_long
ASAN_NAME	= so_long_asan

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ASAN_FLAGS	= -fsanitize=address
RM			= rm -rf
INCLUDES	= ./includes
LIBFTPRINTF	= -lftprintf
MINILIBX	= -lmlx -framework OpenGL -framework AppKit

SRCS_DIR	= ./src
OBJS_DIR	= ./obj
LIBS_DIR	= ./libs
UTILS_DIR	= ./utils

SRCS 		= $(addprefix $(SRCS_DIR)/, main.c)
UTILS_SRCS	= $(addprefix $(UTILS_DIR)/, colors.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
OBJS		+= $(patsubst $(UTILS_DIR)/%.c,$(OBJS_DIR)/%.o,$(UTILS_SRCS))

all: $(LIBS_DIR)/minilibx_macos/libmlx.a $(NAME) asan

$(LIBS_DIR)/minilibx_macos/libmlx.a:
	make -C $(LIBS_DIR)/minilibx_macos

$(NAME): $(OBJS) $(INCLUDES)/libft.h $(INCLUDES)/libftprintf.h $(INCLUDES)/so_long.h $(LIBS_DIR)/minilibx_macos/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBS_DIR)/minilibx_macos $(MINILIBX) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

asan: $(OBJS)
	$(CC) $(ASAN_FLAGS) $(OBJS) -o $(ASAN_NAME) -L$(LIBS_DIR)/minilibx_macos $(MINILIBX) -L$(LIBS_DIR) $(LIBFTPRINTF) -I$(INCLUDES)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean: 
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(ASAN_NAME)

re: fclean all