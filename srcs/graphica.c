#include "../includes/fractol.h"

t_image	*ft_delimage(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->ptr != NULL)
			mlx_destroy_image(mlx->init, img->ptr);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

void	ft_image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->data + (x * image->bitspp + y * image->string)) = color;
}

t_image	*ft_new_image(t_mlx *mlx)
{
	t_image		*img;

	img = memandmalloc(sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT);
	if (img->ptr == NULL)
		return (ft_delimage(mlx, img));
	img->data = mlx_get_data_addr(img->ptr, &img->bitspp, &img->string,
			&img->endian);
	img->bitspp /= 8;
	return (img);
}
