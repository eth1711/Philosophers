NAME	= philosophers
DIR		= philo/
SRCS	=
SRCS_B	=
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
INCS	= -Iincludes
CC		= gcc
C_FLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
RM		= rm -rf

%.o: %c 
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS)

