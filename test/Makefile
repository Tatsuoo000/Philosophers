SRCDIR	= ./
SRCNAME	= 	test.c\
			philo.c\
			info_init.c
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBDIR)$(LIBFT) -o $(NAME) -lpthread

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

sani	:	$(OBJS)
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

.PHONY	:	all clean fclean re