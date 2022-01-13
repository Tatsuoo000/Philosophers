SRCDIR	= ./srcs/
SRCNAME	= 	main.c
			
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./includes
NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBDIR	= ./libft/
LIBFT	= libft.a

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBDIR)$(LIBFT) -o $(NAME)

$(LIBFT):
			make -C $(LIBDIR)

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBDIR)

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBDIR)

re		:	fclean all

sani	:	$(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LIBDIR)$(LIBFT) -o $(NAME)

.PHONY	:	all clean fclean re $(LIBFT)