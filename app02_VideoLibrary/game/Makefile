name = cube
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: 
	gcc $(SRCS) lmlx/libmlx.a -framework OpenGL -framework AppKit -o $(name)

run: all
	./$(name)

clean:
	$(RM) $(OBJS) $(NAME)

re: clean all
#YES- it needs imporvement
