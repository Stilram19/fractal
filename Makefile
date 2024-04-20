SRCS=	srcs/main.c \
		srcs/utils.c \
		srcs/init1.c \
		srcs/init2.c \
		srcs/init3.c \
		srcs/events.c \
		srcs/rendering.c \
		srcs/events_reactions.c \
		srcs/fractals.c \
		srcs/coloring_strategies.c
BONUS_SRCS=	bonus/main_bonus.c \
			bonus/utils_bonus.c \
			bonus/init_bonus.c \
			bonus/events_bonus.c \
			bonus/rendering_bonus.c \
			bonus/events_reactions_bonus.c \
			bonus/coloring_strategies_bonus.c
OBJS=	${SRCS:.c=.o}
NAME= fractol

CFLAGS= -Wall -Wextra -Werror
RM= rm -f

all: ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $< -o $@

# for linux
${NAME}: ${OBJS}
	gcc ${OBJS} -lSDL2 -lm -o ${NAME}
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
