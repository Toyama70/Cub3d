/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:12 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/08 13:49:35 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_cleanpath(int ln, t_game *game)
{
	int i = 0;
	int k = 0;
	char *temp;
   
	temp = game->txtr[ln];
	while(game->txtr[ln][i] != '.')
		i++;
	while(game->txtr[ln][i] != 0)
	{
		temp[k] = game->txtr[ln][i];
		if (temp[k] == '\n')
		{
			temp[k + 1] = 0;
			break;
		}
	   	i++;
		k++;
	}
	i = 0;
	k = 0;
	while (temp[k] != 0)
	{
		game->txtr[ln][i] = temp[k];
		i++;
		k++;
	}
	game->txtr[ln][i] = 0;
}

void	ft_maketxtr(char **tab, int i, int k, t_game *game)
{
	int range;
	int start = 0;

	range = i + 4;
	game->txtr = malloc(sizeof(char *) * 4); //I could set that in a initiate
	game->txtr = ft_calloc(sizeof(char), game->maplen);
	while (start < 4)
	{
		game->txtr[start] = tab[i];
		ft_cleanpath (start, game);
		start++;
		i++;
	}
}

void	ft_dividein3(char **tab, t_game *game, int len)
{
	int i = 0;
	int k = 0;
	
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'N' && tab[i][k+1] == 'O')
			{
				ft_maketxtr(tab, i, k, game);
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}

	i = 0;
	k = 0;
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'F' && tab[i][k+1] == ' ')
			{
				ft_makefloor(tab, i, k, game);
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
	
	i = 0;
	k = 0;
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			if (tab[i][k] == 'C' && tab[i][k+1] == ' ')
			{
				ft_makeceiling(tab, i, k, game);
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}





int ft_skipline(int *ln, int fd)
{
	int i = 0;
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			break;
	}

	return 0;

}
