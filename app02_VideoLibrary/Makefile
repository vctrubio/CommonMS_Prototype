NAME		=	videoLib
SRCS		=	$(wildcard srcs/*.cpp)
OBJS		=	$(SRCS:.c=.o)

all: 
	g++ $(SRCS) --std=c++17 -W -Wextra -Werror -o $(NAME) 

run: 
	g++ $(SRCS) --std=c++17 -o $(NAME) && ./$(NAME)
