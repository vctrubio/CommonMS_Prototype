name = cube
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f
UNAME = $(shell uname)


ifeq ($(UNAME), Darwin)
all: 
	gcc $(SRCS) lmlx/libmlx.a -framework OpenGL -framework AppKit -o ../$(name)

else
all:
	cd mlx_linux && make
	gcc $(SRCS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address -o $(name) #-fsanitize=address
endif
run: all
	./$(name)

clean:
	$(RM) $(OBJS) $(NAME)

re: clean all