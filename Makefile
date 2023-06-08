SRCS =  main.cpp


OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}
CPP = c++
RM = rm -f
CPPFLAGS =  -Wall -Werror -Wextra -MMD -std=c++98
# -fsanitize=address -MMD
HEADER = containers/vector.hpp containers/map.hpp containers/iterator.hpp containers/stack.hpp utils/BST.hpp utils/utils.hpp
# STD = true false
NAME = std_exec ft_exec

# %.o:%.cpp
# 	${CPP} ${CPPFLAGS} -I containers/vector.hpp -I containers/map.hpp -I containers/iterator.hpp -I containers/stack.hpp -I tests/tests.hpp -c $< -o ${<:.cpp=.o}

all:		${NAME}

# std: CPPFLAGS += -DSTD=true
# std: std_exec

# ft: CPPFLAGS += -DSTD=false
# ft: ft_exec

-include $(DEPS)
${NAME}:	${OBJS}
			${CPP} -D NAMESPACE=std ${CPPFLAGS} ${OBJS} -o std_exec
			${CPP} ${CPPFLAGS} ${OBJS} -o ft_exec
			

test:		${NAME}
			./containers

clean: 		
			${RM} ${OBJS} $(DEPS)

fclean: 	clean
			${RM} ${NAME}

re:			fclean
			${MAKE}

.PHONY: all clean fclean re test