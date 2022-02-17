/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:12 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/17 10:46:38 by ybestrio         ###   ########.fr       */
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

void	ft_dividein3(char **tab, t_game *game)
{
	int i;
	int k;
	
	i = 0;
	k = 0;
	game->txtr = malloc(sizeof(char *) * 4); //I could set that in a initiate
	
	for(int turn = 0; turn < 4 ; turn++) //supprimer ce for
		game->txtr[turn] = ft_calloc(sizeof(char), game->maplen + 1);
	
	ft_divideno(i, k, tab, game);
	ft_divideso(i, k, tab, game);
	ft_dividewe(i, k, tab, game);
	ft_divideea(i, k, tab, game);
	ft_dividefloor(i, k, tab, game);
	ft_divideceiling(i, k, tab, game);
	ft_dividemap(i, k, tab, game);	
	// I NEED TO ADD A FREE FUNCTION FOR THE TAB 2DArray
	ft_verifrgb(tab, i, k, game);
	free_tab(tab);

}

void	ft_locatefloor(char **tab, int i, int k, t_game *game)
{
	while (i < game->maphei)
	{
		while (tab[i][k] != '\n')
		{
			if (tab[i][k] == 'F' && tab[i][k+1] == ' ')
			{
				ft_rgbinvalid(tab, i, k + 1);
				ft_checkfloor(tab, i, 0);
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_locateceiling(char **tab, int i, int k, t_game *game)
{
	while (i < game->maphei)
	{
		while (tab[i][k] != '\n')
		{
			if (tab[i][k] == 'C' && tab[i][k+1] == ' ')
			{
				ft_rgbinvalid(tab, i, k + 1);
				ft_checkceiling(tab, i, 0);
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_verifrgb(char **tab, int i, int k, t_game *game)
{
	ft_locatefloor(tab, i, k, game);
	ft_locateceiling(tab, i, k, game);
	//ft_checkfloor(tab, i, k, game);
//	ft_checkceiling(tab, i, k, game);
}

void ft_rgbsize(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
	{
		printf("Error RGB is too big ?\n");
		exit(1);
	}
	if (r < 0 || g < 0 || b < 0)
	{
		printf("Error RGB is too small ?\n");
		exit(1);
	}
}

int ft_skipline(int fd)
{
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			break;
	}

	return 0;

}


void	ft_checkfloor(char **tab, int i, int k) // need to rewrite and optimize
{
	char r[40];
	char g[40];
	char b[40];
	int m;
	
	m = 0;
	if (tab[i][k] == 'F')
	{
		k++;
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[m++] = tab[i][k++];
		r[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[m++] = tab[i][k++];
		g[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[m++] = tab[i][k++];
		b[m] = 0;
	}
	ft_rgbsize(atoi(r), atoi(g), atoi(b));
}

void	ft_checkceiling(char **tab, int i, int k) // need to rewrite and optimize
{
	char r[40];
	char g[40];
	char b[40];
	int m;
	
	m = 0;
	if (tab[i][k] == 'C')
	{
		k++;
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[m++] = tab[i][k++];
		r[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[m++] = tab[i][k++];
		g[m] = 0;
		m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[m++] = tab[i][k++];
		b[m] = 0;
	}
	printf("r = %s\n", r);
	printf("g = %s\n", g);
	printf("b = %s\n", b);
	ft_rgbsize(atoi(r), atoi(g), atoi(b));
}
