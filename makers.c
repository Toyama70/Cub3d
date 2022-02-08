/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:53 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/08 13:49:06 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_makefloor(char **tab, int i, int k, t_game *game) // need to rewrite and optimize
{
	char r[4];
	char g[4];
	char b[4];
	int m;
	m = 0;

	if (tab[i][k] == 'F')
	{
		k++;
		while(tab[i][k] == ' ')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ')
		{
			r[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		r[m] = 0;
		m = 0;
		while(tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ')
		{
			g[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		g[m] = 0;
		m = 0;
		while(tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
		{
			b[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		b[m] = 0;
	}
	game->floor = create_rgb(atoi(r), atoi(g), atoi(b));
}


void	ft_makeceiling(char **tab, int i, int k, t_game *game) // need to rewrite and optimize
{
	char r[4];
	char g[4];
	char b[4];
	int m;
	m = 0;

	if (tab[i][k] == 'C')
	{
		k++;
		while(tab[i][k] == ' ')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ')
		{
			r[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		r[m] = 0;
		m = 0;
		while(tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ')
		{
			g[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		g[m] = 0;
		m = 0;
		while(tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while(tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
		{
			b[m] = tab[i][k]; // need atoi to create rgb
			m++;
			k++;
		}
		b[m] = 0;
	}
	game->ceiling = create_rgb(atoi(r), atoi(g), atoi(b));
}
