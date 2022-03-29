/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:24:27 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/29 14:44:13 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit(0);
	yasin(&data, argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "cub3d");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.b_pix,
			&data.len_pix, &data.endian);
	data.press = 0;
	if (open(data.txtr[0], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data.txtr[1], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data.txtr[2], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	if (open(data.txtr[3], O_RDWR) == -1)
	{
		printf("Texture failure\n");
		exit(1);
	}
	sprites_init(&data);
	make_player(&data);
	mlx_hook(data.win, 2, 1L << 0, presskey, &data);
	mlx_hook(data.win, 3, 1L << 0, un_presskey, &data);
	mlx_hook(data.win, 17, 1L << 0, &exit_mlx, &data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
}
