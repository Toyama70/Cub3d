/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/22 18:43:37 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//pos joueur
//vue pdt le spwan

int	img_pix(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->l_l + x * (img->bpp / 8));
	return (*((int *)ptr));
}

int main(int argc, char **argv)
{
    t_data data;


	yasin(&data, argc, argv);
	data.press = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3d");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix, &data.len_pix, &data.endian);
	data.map_l = 24;
	data.map_h = 24;//a modifier ?/
	data.north.img = mlx_xpm_file_to_image(data.mlx, "./north.xpm", &data.north.w, &data.north.h);
	data.north.addr = mlx_get_data_addr(data.north.img, &data.north.bpp, &data.north.l_l, &data.north.endian);
	data.south.img = mlx_xpm_file_to_image(data.mlx, "./south.xpm", &data.south.w, &data.south.h);
	data.south.addr = mlx_get_data_addr(data.south.img, &data.south.bpp, &data.south.l_l, &data.south.endian);
	data.west.img = mlx_xpm_file_to_image(data.mlx, "./west.xpm", &data.west.w, &data.west.h);
	data.west.addr = mlx_get_data_addr(data.west.img, &data.west.bpp, &data.west.l_l, &data.west.endian);
	data.east.img = mlx_xpm_file_to_image(data.mlx, "./east.xpm", &data.east.w, &data.east.h);
	data.east.addr = mlx_get_data_addr(data.east.img, &data.east.bpp, &data.east.l_l, &data.east.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	make_player(&data);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
   	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data); 
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
	//free_tab(data.map);*/
}

/* float i = 0;
	float j = 0;
	float x = 0;
	float y = 0;
	int color = 0;
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			x = (i / 200.0) * data.w_n;
			y = (j / 200.0) * data.h_n;
			color = img_pix(&data, x, y);
			my_mlx_pixel_put(&data, i, j, color);
			i++;
		}
		j++;
	}*/
