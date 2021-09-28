#include "../includes/fractol.h"

int	ft_color_calc(int iter, int max, int scheme)
{
	int		s1;
	int		s2;
	int		s3;

	s1 = scheme / 100;
	s2 = (scheme / 10) % 10;
	s3 = scheme % 10;
	if (iter <= max / 2)
		return ((255 / (max / 2 - iter + 1)) << (s1 * 8));
	else
		return (255 << (s1 * 8) | (int)(255 * (iter - max / 2 + 1)
					/ (max / 2)) << (s2 * 8) | (int)(255 * ((iter - max
							/ 2 + 1) / (max / 2))) << (s3 * 8));
			return (0);
}

int	ft_pixel_color(int iter, int max, int scheme)
{
	if (scheme == 18)
		return (12345678 * iter);
	else if (scheme == 19)
		return (ft_color_calc(iter, max, 12));
	else if (scheme == 20)
		return (ft_color_calc(iter, max, 120));
	else if (scheme == 21)
		return (ft_color_calc(iter, max, 210));
	else if (scheme == 23)
		return (255 * iter / max | (255 * iter / max) << 8 |
				(255 * iter / max) << 16);
	else
		return (12345678 * iter);
	return (0);
}

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
