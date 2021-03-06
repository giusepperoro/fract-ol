#include "../includes/fractol.h"

static int	ft_change_num(t_fractol *f)
{
	double	p;
	double	q;

	f->old_re = f->new_re;
	f->old_im = f->new_im;
	p = f->old_re - f->old_re * f->old_re + f->old_im * f->old_im;
	q = f->old_im - 2 * f->old_re * f->old_im;
	f->new_re = f->c_re * p - f->c_im * q;
	f->new_im = f->c_re * q + f->c_im * p;
	if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
		return (1);
	return (0);
}

static void	count_point(int x, int y, t_fractol f, t_mlx *mlx)
{
	int		i;

	i = -1;
	f.c_re = 1.5 * (x + mlx->cam.offsetx - WIN_WIDTH / 2)
		/ (0.5 * mlx->cam.scale * WIN_WIDTH);
	f.c_im = (y + mlx->cam.offsety - WIN_HEIGHT / 2)
		/ (0.5 * mlx->cam.scale * WIN_HEIGHT);
	i = -1;
	f.new_re = 0.5;
	f.new_im = 0;
	while (++i < f.iter)
		if (ft_change_num(&f))
			break ;
	if (i < f.iter - 1)
		ft_image_set_pixel(mlx->image, x, y, ft_pixel_color(i, f.iter,
				f.color));
}

void	*lambda(void *inc)
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
