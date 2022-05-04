/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:53 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/04 11:33:25 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_makefloor(char **tab, int i, int k, t_data *data)
{
	char	r[4];
	char	g[4];
	char	b[4];

	if (tab[i][k++] == 'F')
	{
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[data->m++] = tab[i][k++];
		r[data->m] = 0;
		data->m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[data->m++] = tab[i][k++];
		g[data->m] = 0;
		data->m = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[data->m++] = tab[i][k++];
		b[data->m] = 0;
	}
	data->floor = create_rgb(atoi(r), atoi(g), atoi(b));
}

void	ft_rgbinvalid(char **tab, int i, int m)
{
	while (tab[i][m] != 0 && tab[i][m] != '\n')
	{
		if (tab[i][m] > 57 || tab[i][m] < 48)
		{
			if (tab[i][m] != ' ' && tab[i][m] != ',')
			{
				printf("Error : invalid RGB value\n");
				exit(1);
			}
		}
		m++;
	}
}

void	ft_makeceiling(char **tab, int i, int k, t_data *data)
{
	char	r[4];
	char	g[4];
	char	b[4];

	if (tab[i][k++] == 'C')
	{
		while (tab[i][k] == ' ')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			r[data->l++] = tab[i][k++];
		r[data->l] = 0;
		data->l = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ')
			g[data->l++] = tab[i][k++];
		g[data->l] = 0;
		data->l = 0;
		while (tab[i][k] == ' ' || tab[i][k] == ',')
			k++;
		while (tab[i][k] != ',' && tab[i][k] != ' ' && tab[i][k] != '\n')
			b[data->l++] = tab[i][k++];
		b[data->l] = 0;
	}
	data->ceiling = create_rgb(atoi(r), atoi(g), atoi(b));
}
