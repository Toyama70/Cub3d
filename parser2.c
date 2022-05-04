/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:06 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/04 11:46:01 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_rgbsize(int r, int g, int b)
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

int	ft_skipline(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			break ;
	}
	return (0);
}

void	ft_checkfloor(char **tab, int i, int k, int m)
{
	char	r[40];
	char	g[40];
	char	b[40];
	
	if (tab[i][k++] == 'F')
	{
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

void	ft_checkceiling(char **tab, int i, int k, int m)
{
	char	r[40];
	char	g[40];
	char	b[40];

	if (tab[i][k++] == 'C')
	{
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
