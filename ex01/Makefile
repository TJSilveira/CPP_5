NAME	= ex01

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC		=	Bureaucrat.cpp \
			Form.cpp \
			main.cpp

OBJS	=	$(patsubst %.cpp,%.o,$(SRC))

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ $^

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}
