SRCS =  main.cpp\
        Bureaucrat.cpp\
		Form.cpp

OBJS =  ${SRCS:.cpp=.o}

CC =    c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

NAME =  module05

all: ${NAME}

${NAME}: ${OBJS}
				${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
				$(CC) $(FLAGS) -o $@ -c $<

clean:
				rm -rf $(OBJS)

fclean: clean
				rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean