NAME	= Bureaucrat
CC		= c++
FLAGS	= -Wall -Werror -Wextra -I -std=c++98 -fsanitize=address

RM 		= rm -rf

SRCS	= Bureaucrat.cpp main.cpp
INC		= Bureaucrat.hpp

OBJS	= ${SRCS:%.cpp=%.o}

%.o: %.cpp ${INC}
		@printf "\033[38;5;121mCompiling $<...\033[0m\r"
		@${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
		@echo "\n\033[38;5;204mMama I want to be a bureaucrat.\033[0m"
		@${CC} ${FLAGS} ${OBJS} -o $@

clean:
		@echo "\033[38;5;227mRemoving Objects\033[0m"
		@${RM} ${OBJS}

fclean:	clean
		@echo "\033[38;5;81mRemoving Executable\033[0m"
		@${RM} ${NAME}

re: fclean all
