#include "../includes/fractol.h"

void	*memandmalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		exit (EXIT_FAILURE);
	memset(res, 0, size);
	return (res);
}

static t_mlx	*ft_init(char frname, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)memandmalloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->init = init;
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx->image = ft_new_image(mlx);
	if ((mlx->window == NULL) || (mlx->image == NULL))
		return (NULL);
	mlx->pthreads = 8;
	mlx->mouse.x = 0;
	mlx->mouse.y = 0;
	mlx->cam.offsetx = 0;
	mlx->cam.offsety = 0;
	mlx->cam.zoomx = 0;
	mlx->cam.zoomy = 0;
	mlx->cam.scale = 1;
	mlx->fractol.iter = 24;
	mlx->fractol.color = 1;
	mlx->name = frname;
	if (frname != 'j')
		mlx->mouse.flag = 1;
	return (mlx);
}

static void	init_fractol(t_mlx *mlx)
{
	if (mlx->name == 'm')
	{
		mlx->fractol.new_re = 0;
		mlx->fractol.old_re = 0;
		mlx->fractol.new_im = 0;
		mlx->fractol.old_im = 0;
		mlx->cam.offsetx = -250;
	}
	else if (mlx->name == 'j')
	{
		mlx->fractol.c_im = 0.5f;
		mlx->fractol.c_re = -0.5f;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	**mlx;
	int		i;
	void	*init;
	int		count;

	init = mlx_init();
	count = argc;
	mlx = (t_mlx **)memandmalloc(sizeof(t_mlx) * count);
	i = -1;
	while (++i < argc - 1)
	{
		if (check_arg(argc, argv[i + 1]))
			return_er("Error: memory allocation\n");
		mlx[i] = ft_init(argv[i + 1][0], init);
		if (!mlx[i])
			return (EXIT_FAILURE);
		init_fractol(mlx[i]);
		launch(mlx[i]);
		hook(mlx[i], &count);
	}
	if (i == 0)
		return_er("Usage: fractol_names\n");
	mlx_loop(init);
	return (EXIT_SUCCESS);
}
