#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fr	**fr;
	int	i;

	i = -1;
	
	while(++i < argc - 1)
	{
		if (check_arg(argc, argv[i + 1]))
			return(STDERR_FILENO);
	}
	return (0);
}