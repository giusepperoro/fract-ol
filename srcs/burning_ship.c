#include "../includes/fractol.h"

static int	ft_change_num(t_fractol *f)
{
	f->old_re = f->new_re;
	f->old_im = f->new_im;
	f->new_re = fabs(f->old_re * f->old_re - f->old_im * f->old_im + f->c_re);
	f->new_im = fabs(2 * f->old_re * f->old_im) + f->c_im;
	if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	count_point(int x, int y, t_fractol f, t_mlx *mlx)
{
	int		i;

	i = -1;
	f.new_re = 1.5 * (x + mlx->cam.offsetx - WIN_WIDTH / 2)
		/ (0.5 * mlx->cam.scale * WIN_WIDTH);
	f.new_im = (y + mlx->cam.offsety - WIN_HEIGHT / 2)
		/ (0.5 * mlx->cam.scale * WIN_HEIGHT);
	f.c_re = f.new_re;
	f.c_im = f.new_im;
	i = -1;
	while (++i < f.iter)
		if (ft_change_num(&f))
			break ;
	if (i < f.iter - 1)
		ft_image_set_pixel(mlx->image, x, y, ft_pixel_color(i, f.iter,
				f.color));
}

void	*burning_ship(void *inc)
{
	t_fractol	f;
	int			x;
	int			y;
	t_mlx		*mlx;

	mlx = (t_mlx *)inc;
	f = mlx->fractol;
	y = mlx->ymin - 1;
	while (++y < mlx->ymax)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			count_point(x, y, f, mlx);
	}
	return (NULL);
}
