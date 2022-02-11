/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadivider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:51 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/10 15:19:02 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void ft_divideno(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'N' && tab[i][k+1] == 'O')
			{
				ft_cleanpath(tab, i, 0, game);

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

void ft_divideso(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'S' && tab[i][k+1] == 'O')
			{
				ft_cleanpath(tab, i, 1, game);

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

void ft_divideea(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'E' && tab[i][k+1] == 'A')
			{
				ft_cleanpath(tab, i, 2, game);

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

void ft_dividewe(int i, int k, char **tab, t_game *game)
{
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'W' && tab[i][k+1] == 'E')
			{
				ft_cleanpath(tab, i, 3, game);

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
