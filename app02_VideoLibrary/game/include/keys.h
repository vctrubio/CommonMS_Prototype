#ifndef KEYS_H
#define KEYS_H

#ifdef __linux__
#  define K_A	0
#  define K_S	1
#  define K_D 2
#  define K_W	13
#  define K_ESC	53
#else

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_Q 12
# define K_ESC 53
# define K_G 5
#endif

# define MYRED 0x00820010
# define MYREDISH 0x81102299
# define MYGREEN 0x0000F900
# define MYBLUE 0x00F90000
# define MYWHITE 0x00F0F0F0

typedef struct	s_key
{
	int	W;
	int	S;
	int	A;
	int	D;
	int	Q;
	int	E;
	int	ESC;
}		t_key;

#endif
