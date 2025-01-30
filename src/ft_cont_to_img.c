#include "so_long.h"

// turns each character from the map object
// into the respective image from the image object
void	*ft_cont_to_img(t_win *win, char in)
{
	if (in == '1')
		return (win->img->wall);
	else if (in == '0')
		return (win->img->empty);
	else if (in == 'C')
		return (win->img->coin);
	else if (in == 'P')
		return (win->img->player);
	else if (in == 'E')
		return (win->img->exit);
	return (win->img->player);
}