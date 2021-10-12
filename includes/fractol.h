#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>

enum	e_key {
	WIN_WIDTH = 1280,
	WIN_HEIGHT = 640,
	KEY_ESC = 53,
	KEY_SPACE = 49,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	HEY_H = 4,
	KEY_G = 5,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};

typedef struct s_image
{
	void		*ptr;
	char		*data;
	int			bitspp;
	int			string;
	int			endian;
}				t_image;

typedef struct s_cam
{
	double		offsetx;
	double		offsety;
	double		scale;
	int			zoomx;
	int			zoomy;
}				t_cam;

typedef struct s_mouse
{
	int			x;
	int			y;
	int			prevx;
	int			prevy;
	int			down;
	int			flag;
}				t_mouse;

typedef struct s_fractol
{
	double		c_im;
	double		c_re;
	double		old_re;
	double		old_im;
	double		new_re;
	double		new_im;
	int			iter;
	int			color;
}				t_fractol;

typedef struct s_mlx
{
	void		*init;
	void		*window;
	t_image		*image;
	t_cam		cam;
	t_mouse		mouse;
	t_fractol	fractol;
	int			pthreads;
	int			ymin;
	int			ymax;
	char		name;
}				t_mlx;

int		main(int argc, char **argv);
int		check_arg(int argc, char *argv);
int		return_er(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*argv_commannds(void *inc);
void	launch(t_mlx *mlx);
int		close_window(int *argc);
void	move_arrows(int key, t_mlx *mlx);
int		ft_pixel_color(int iter, int max, int scheme);
int		ft_color_calc(int iter, int max, int scheme);
t_image	*ft_delimage(t_mlx *mlx, t_image *img);
void	ft_image_set_pixel(t_image *image, int x, int y, int color);
t_image	*ft_new_image(t_mlx *mlx);
void	hook(t_mlx *mlx, int *argc);
void	*memandmalloc(size_t size);
void	*burning_ship(void *inc);
void	*drop(void *inc);
void	*julia(void *inc);
void	*lambda(void *inc);
void	*mandelbrot(void *inc);
void	*spider(void *inc);
void	ft_memdel(void **ap);

#endif
