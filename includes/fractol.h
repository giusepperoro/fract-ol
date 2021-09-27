#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 960
# define WIN_HEIGHT 480

# include "../mylib/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_fractol
{
	t_mlx	mlx;
}				t_fractol;

int	main(int argc, char **argv);
int	check_arg(int argc, char *argv);

#endif