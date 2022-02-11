/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:12 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/10 15:34:28 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_cleanpath(char **tab, int ln, int tx, t_game *game)
{
	int i = 0;
	int k = 0;
	
	while(tab[ln][i] != '.')
		i++;
	while(tab[ln][i] != 0 && tab[ln][i] != '\n')
	{
		game->txtr[tx][k] = tab[ln][i];
	   	i++;
		k++;
	}
	game->txtr[tx][k] = 0;
}

void	ft_dividemap(int i, int k, char **tab, t_game *game)
{
	int rest;
	int m;
	
	m = 0;
	i = game->lowhei + 1;
	rest = (game->maphei - i) + 1;
	game->map = ft_calloc(sizeof(char *), rest);	
	while (k < rest)
	{
		game->map[k] = ft_calloc(sizeof(char), game->maplen);
		k++;
	}
	k = 0;
	while(i < game->maphei)
	{
		while(k < game->maplen)
		{
			game->map[m][k] = tab[i][k];
			k++;
		}
		k = 0;
		i++;
		m++;
	}
}

void	ft_dividein3(char **tab, t_game *game, int len)
{
	int i;
	int k;
	
	i = 0;
	k = 0;
	game->txtr = malloc(sizeof(char *) * 4); //I could set that in a initiate
	
	for(int turn = 0; turn < 4 ; turn++)
		game->txtr[turn] = ft_calloc(sizeof(char), game->maplen + 1);
	
	
	ft_divideno(i, k, tab, game);
	ft_divideso(i, k, tab, game);
	ft_dividewe(i, k, tab, game);
	ft_divideea(i, k, tab, game);
	ft_dividefloor(i, k, tab, game);
	ft_divideceiling(i, k, tab, game);
	ft_dividemap(i, k, tab, game);	
	// I NEED TO ADD A FREE FUNCTION FOR THE TAB 2DArray


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
