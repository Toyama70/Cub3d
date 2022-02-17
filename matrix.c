/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:59 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/16 18:03:57 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_fillnorth(t_game *game, t_comp *north, char *file)
{
	north->img = mlx_xpm_file_to_image(game->mlx, file, &north->w, &north->h);
	north->addr = mlx_get_data_addr(north->img, &north->bpp, &north->l_l,
			&north->endian);
}

void	ft_fillsouth(t_game *game, t_comp *south, char *file)
{
	south->img = mlx_xpm_file_to_image(game->mlx, file, &south->w, &south->h);
	south->addr = mlx_get_data_addr(south->img, &south->bpp, &south->l_l,
			&south->endian);
}

void	ft_filleast(t_game *game, t_comp *east, char *file)
{
	east->img = mlx_xpm_file_to_image(game->mlx, file, &east->w, &east->h);
	east->addr = mlx_get_data_addr(east->img, &east->bpp, &east->l_l,
			&east->endian);
}

void	ft_fillwest(t_game *game, t_comp *west, char *file)
{
	west->img = mlx_xpm_file_to_image(game->mlx, file, &west->w, &west->h);
	west->addr = mlx_get_data_addr(west->img, &west->bpp, &west->l_l,
			&west->endian);
}

void	ft_matrix(t_game *game)
{
	t_comp	north;
	t_comp	south;
	t_comp	east;
	t_comp	west;

	ft_fillnorth(game, &north, game->txtr[0]);
	ft_fillsouth(game, &south, game->txtr[1]);
	ft_filleast(game, &east, game->txtr[2]);
	ft_fillwest(game, &west, game->txtr[3]);
	game->wall_no = north;
	game->wall_so = south;
	game->wall_ea = east;
	game->wall_we = west;
}
