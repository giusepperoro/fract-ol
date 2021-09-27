#include "fractol.h"

int	check_arg(int argc, char *argv)
{
	if (argc < 2 || (ft_strcmp(argv, "julia")
			&& ft_strcmp(argv, "mandelbrot")
			&& ft_strcmp(argv, "spider")
			&& ft_strcmp(argv, "burning_ship")
			&& ft_strcmp(argv, "lambda")
			&& ft_strcmp(argv, "drop")))
	{
		ft_putstr_fd("usage: ./fractol fractol_names", STDERR_FILENO);
		ft_putstr_fd("available names:", STDERR_FILENO);
		ft_putstr_fd("julia, mandelbrot, spider, burning_ship, drop, lambda",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}
