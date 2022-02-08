/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadivider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:51 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/08 17:43:12 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void ft_dividetxtr(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'N' && tab[i][k+1] == 'O')
			{
				ft_maketxtr(tab, i, k, game);
				if (i > game->lowhei)
					game->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_dividefloor(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'F' && tab[i][k+1] == ' ')
			{
				ft_makefloor(tab, i, k, game);
				if (i > game->lowhei)
					game->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
	
void	ft_divideceiling(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'C' && tab[i][k+1] == ' ')
			{
				ft_makeceiling(tab, i, k, game);
				if (i > game->lowhei)
					game->lowhei = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
