#include "../includes/fractol.h"

int	close_window(int *argc)
{
	(*argc)--;
	if (*argc == 1)
		exit(0);
	return (EXIT_SUCCESS);
}

void	move_arrows(int key, t_mlx *mlx)
{
	double	step;

	step = 30;
	if (key == KEY_UP)
		mlx->cam.offsety += step;
	else if (key == KEY_DOWN)
		mlx->cam.offsety -= step;
	else if (key == KEY_LEFT)
		mlx->cam.offsetx += step;
	else if (key == KEY_RIGHT)
		mlx->cam.offsetx -= step;
	launch(mlx);
}

void	*argv_commannds(void *inc)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)inc;
	if (mlx->name == 'b')
		burning_ship(inc);
	else if (mlx->name == 'd')
		drop(inc);
	else if (mlx->name == 'j')
		julia(inc);
	else if (mlx->name == 'l')
		lambda(inc);
	else if (mlx->name == 'm')
		mandelbrot(inc);
	else if (mlx->name == 's')
		spider(inc);
	return (NULL);
}

void	launch(t_mlx *mlx)
{
	pthread_t	*threads;
	t_mlx		*data;
	int			i;
	int			step;

	step = WIN_HEIGHT / mlx->pthreads + WIN_HEIGHT
		- WIN_HEIGHT / mlx->pthreads * mlx->pthreads;
	threads = (pthread_t *)memandmalloc(sizeof(pthread_t) * mlx->pthreads);
	data = (t_mlx *)memandmalloc(sizeof(t_mlx) * mlx->pthreads);
	bzero(mlx->image->data, WIN_WIDTH * WIN_HEIGHT * mlx->image->bitspp);
	i = -1;
	while (++i < mlx->pthreads)
	{
		data[i] = *mlx;
		data[i].ymin = step * i;
		data[i].ymax = step * (i + 1);
		pthread_create(&(threads[i]), NULL, argv_commannds, &(data[i]));
	}
	i = -1;
	while (++i < mlx->pthreads)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->ptr, 0, 0);
	free(threads);
	free(data);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = -1;
	while (s1[++i] != '\0' || s2[i] != '\0')
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
