#include "../includes/fractol.h"

int	check_arg(int argc, char *str)
{
	if (argc < 2 || (ft_strcmp(str, "julia")
			&& ft_strcmp(str, "mandelbrot")
			&& ft_strcmp(str, "spider")
			&& ft_strcmp(str, "burning_ship")
			&& ft_strcmp(str, "lambda")
			&& ft_strcmp(str, "drop")))
	{
		printf("usage: ./fractol fractol_names");
		printf("available names:");
		printf("julia, mandelbrot, spider, burning_ship, drop, lambda");
		return (1);
	}
	return (0);
}

int	return_er(char *str)
{
	printf("%s\n", str);
	exit (1);
}
