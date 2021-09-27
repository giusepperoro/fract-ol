#include "fractol.h"

static int	mouse_down(int but, int x, int y, t_mlx *mlx)
{
	if (but == HEY_H)
	{
		mlx->cam.offsetx += ((x - WIN_WIDTH / 2
					+ mlx->cam.offsetx) * (1.1f - 1.0f));
		mlx->cam.offsety += ((y - WIN_HEIGHT / 2
					+ mlx->cam.offsety) * (1.1f - 1.0f));
		mlx->cam.scale *= 1.1f;
		launch(mlx);
	}
	if (but == KEY_G)
	{
		mlx->cam.offsetx -= ((x - WIN_WIDTH / 2
					+ mlx->cam.offsetx) * (1.1f - 1.0f));
		mlx->cam.offsety -= ((y - WIN_HEIGHT / 2
					+ mlx->cam.offsety) * (1.1f - 1.0f));
		mlx->cam.scale *= 0.9f;
		launch(mlx);
	}
	mlx->mouse.down |= (1 << but);
	launch(mlx);
	return (EXIT_SUCCESS);
}

static int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == KEY_SPACE)
		mlx->mouse.flag++;
	else if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (key == KEY_Q)
		mlx->fractol.iter++;
	else if (key == KEY_E)
		mlx->fractol.iter--;
	else if (key == KEY_Z)
	{
		if (mlx->pthreads < 10000)
			mlx->pthreads += 5;
	}
	else if (key == KEY_X)
	{
		if (mlx->pthreads > 5)
			mlx->pthreads -= 5;
	}
	else if (key >= 18 && key <= 23)
		mlx->fractol.color = key;
	else if (key >= KEY_LEFT && key <= KEY_UP)
		move_arrows(key, mlx);
	launch(mlx);
	return (EXIT_SUCCESS);
}

static int	mouse_up(int but, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	mlx->mouse.down &= ~(1 << but);
	return (EXIT_SUCCESS);
}

static int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.prevy == 0)
		mlx->mouse.prevy = y;
	if (mlx->mouse.prevx == 0)
		mlx->mouse.prevx = x;
	mlx->mouse.prevx = mlx->mouse.x;
	mlx->mouse.prevy = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!(mlx->mouse.flag))
	{
		mlx->fractol.c_re += (x - mlx->mouse.prevx) / 500.f;
		mlx->fractol.c_im += (y - mlx->mouse.prevy) / 500.f;
	}
	else if (mlx->mouse.down & (1 << 1))
	{
		mlx->cam.offsetx -= (x - mlx->mouse.prevx);
		mlx->cam.offsety -= (y - mlx->mouse.prevy);
	}
	launch(mlx);
	return (EXIT_SUCCESS);
}

void	hook(t_mlx *mlx, int *argc)
{
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_hook(mlx->window, 4, 0, mouse_down, mlx);
	mlx_hook(mlx->window, 5, 0, mouse_up, mlx);
	mlx_hook(mlx->window, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->window, 17, 0, close_window, argc);
}
