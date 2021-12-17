CC = gcc
FLAGS = -c -Wall -Wextra -Werror
CFILES = ft_printf.c ft_putnbr.c ft_Xxdicsp.c
NAME = libftprintf.a
OFILES = ${CFILES:.c=.o}
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

all :
	@echo "$(GREEN)*******ALL********"
	${CC} ${FLAGS} ${CFILES}
	ar -r ${NAME} ${OFILES}
clean :
	@echo "$(RED)*******CLEAN********"
	rm -rf ${OFILES}
	rm -rf *.out
fclean : clean
	@echo "$(BLUE)*******FCLEAN********"
	rm -rf ${NAME}
re : clean all
	@echo "$(YELLOW)*******RE********"
.PHONY : all clean fclean re