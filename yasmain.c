/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yasmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/24 11:15:27 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_setrange(char *path, char **tab, t_data *data)
{
	t_gnl	gnl;

	ft_setgnl(&gnl, path);
	while (assign(&gnl) == 1)
	{
		if (strlen(gnl.line) > gnl.len)
			gnl.len = strlen(gnl.line);
		gnl.i++;
		free(gnl.line);
	}
	close(gnl.fd);
	data->map_h = gnl.i;
	data->map_l = gnl.len;
	tab = calloc(sizeof(char *), gnl.i + 1);
	gnl.fd = open(path, O_RDWR);
	if (gnl.fd == -1)
		exit (1);
	gnl.i = -1;
	while (assign(&gnl) == 1)
		tab[++gnl.i] = gnl.line;
	close(gnl.fd);
	ft_setup(tab, data, gnl.len);
}

void	ft_setup(char **tab, t_data *data, size_t len)
{
	len = 0;
	ft_dividein3(tab, data);
	ft_error(data);
}

void	yasin(t_data *data, int argc, char **argv)
{
	char	**tab;

	tab = NULL;
	data->argc = argc;
	data->lowhei = 0;
	ft_setrange(argv[1], tab, data);
}
