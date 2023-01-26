SRCS =  main.cpp


OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}
CPP = c++
RM = rm -f
CPPFLAGS =  -Wall -Werror -Wextra -std=c++98 -fsanitize=address -MMD
HEADER = containers/vector.hpp
NAME = exec

%.o:%.cpp
	${CPP} ${CPPFLAGS} -I ${HEADER} -c $< -o ${<:.cpp=.o}

all:		${NAME}

-include $(DEPS)
${NAME}:	${OBJS}		
			${CPP} ${CPPFLAGS} ${OBJS} -o ${NAME}

test:		${NAME}
			./containers

clean: 		
			${RM} ${OBJS} $(DEPS)

fclean: 	clean
			${RM} ${NAME}
			@${RM} exec

re:			fclean
			${MAKE}

.PHONY: all clean fclean re test