#include "fractol.h"

int	check_arg(int argc, char *str)
{
	if (argc < 2 || (ft_strcmp(str, "julia")
			&& ft_strcmp(str, "mandelbrot")
			&& ft_strcmp(str, "spider")
			&& ft_strcmp(str, "burning_ship")
			&& ft_strcmp(str, "lambda")
			&& ft_strcmp(str, "drop")))
	{
		ft_putstr_fd("usage: ./fractol fractol_names", STDERR_FILENO);
		ft_putstr_fd("available names:", STDERR_FILENO);
		ft_putstr_fd("julia, mandelbrot, spider, burning_ship, drop, lambda",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	return_er(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}
