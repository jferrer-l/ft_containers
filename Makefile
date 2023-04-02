SRCS =  std_main.cpp tests/vector_tests.cpp tests/utils_tests.cpp tests/map_tests.cpp tests/stack_tests.cpp tests/test_utils.cpp


OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}
CPP = c++
RM = rm -f
CPPFLAGS =  -Wall -Werror -Wextra -MMD -std=c++98 -D BUFFER_SIZE=50 el fallo es que siempre se ejecuta con este BUFFER_SIZE y no con los de abajo
# -fsanitize=address -MMD
HEADER = tests/tests.hpp containers/vector.hpp containers/map.hpp containers/iterator.hpp containers/stack.hpp
# STD = true false
NAME = exec

# %.o:%.cpp
# 	${CPP} ${CPPFLAGS} -I containers/vector.hpp -I containers/map.hpp -I containers/iterator.hpp -I containers/stack.hpp -I tests/tests.hpp -c $< -o ${<:.cpp=.o}

all:		${NAME}

# std: CPPFLAGS += -DSTD=true
# std: std_exec

# ft: CPPFLAGS += -DSTD=false
# ft: ft_exec

-include $(DEPS)
${NAME}:	${OBJS}
			${CPP} -D BUFFER_SIZE=500 ${CPPFLAGS} ${OBJS} -o ft_exec
			${CPP} ${CPPFLAGS} -D BUFFER_SIZE=500 ${OBJS} -o std_exec
			sleep 1
			

test:		${NAME}
			./containers

clean: 		
			${RM} ${OBJS} $(DEPS)

fclean: 	clean
			${RM} ${NAME}
			@${RM} std_exec ft_exec

re:			fclean
			${MAKE}

.PHONY: all clean fclean re test