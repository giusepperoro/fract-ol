#ifndef FRACTOL_H
# define FRACTOL_H

#include "../mylib/libft.h"
#include "../minilibx/mlx.h"

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
#endif