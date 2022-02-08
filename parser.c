/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:12 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/08 18:14:25 by yasinbest        ###   ########.fr       */
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

void	ft_dividemap(int i, int k, char **tab, t_game *game)
{
	int rest;
	int m;
	
	m = 0;
	i = game->lowhei + 1;
	rest = (game->maphei - i) + 1;
	game->map = ft_calloc(sizeof(char *), rest);	
	
	printf("i = %d\n", i);
	printf("rest = %d\n", rest);
	printf("k = %d\n", k);

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
	
	printf("line = %s", game->map[1]);
	printf("line = %s", game->map[2]);
	printf("line = %s", game->map[3]);
	printf("line = %s", game->map[4]);
	printf("line = %s", game->map[5]);
	printf("line = %s", game->map[6]);
	printf("line = %s", game->map[7]);
	printf("line = %s", game->map[8]);
	printf("line = %s", game->map[9]);
	printf("line = %s", game->map[10]);
	printf("line = %s", game->map[11]);
	printf("line = %s", game->map[12]);
	printf("line = %s", game->map[13]);
	printf("line = %s", game->map[14]);
	printf("line = %s", game->map[15]);

}

void	ft_dividein3(char **tab, t_game *game, int len)
{
	int i;
	int k;
	
	i = 0;
	k = 0;

	ft_dividetxtr(i, k, tab, game);
	ft_dividefloor(i, k, tab, game);
	ft_divideceiling(i, k, tab, game);
	ft_dividemap(i, k, tab, game);	

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
