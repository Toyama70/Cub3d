/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yasmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/15 12:09:43 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_setrange(char *path, char **tab, t_data *data)
{
	int		fd;
	char	*line;
	size_t		len;
	int		i;
	
	len = 0;
	i = 0;
	fd = open(path, O_RDWR); //if open fail fd == -1
	while ((line = get_next_line(fd))) //if gnl malloc fail return null
	{
		if (strlen(line) > len)
			len = strlen(line);
		i++;
		free(line);
	}
	close(fd);
	data->map_h = i;
	data->map_l = len;//Probleme possible
	tab = calloc(sizeof(char *), i + 1);//tab non protege
	fd = open(path, O_RDWR);//if open fail fd == -1
	i = -1;
	while ((line = get_next_line(fd)))
		tab[++i] = line;
	close(fd);
	ft_setup(tab, data, len);
}

void	ft_setup(char **tab, t_data *data, size_t len)
{
	len = 0;
//	ft_exception(tab, data, len);
	ft_dividein3(tab, data);
	ft_error(data);
}

void	ft_nameissues(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i < 5)
	{
		printf("Error in file name, too short ?\n");
		exit(1);
	}
	if (str[i - 4] != '.' && str[i - 3] != 'c' && str[i - 2] != 'u')
	{
		printf("Invalid extension ?");
		exit(1);
	}
	if (str[i - 1] != 'b')
	{
		printf("Invalid extension ?");
		exit(1);
	}
}

void yasin(t_data *data, int argc, char **argv)
{
	char **tab = NULL;

	data->argc = argc;
	data->lowhei = 0;

	ft_nameissues(argv[1]);
	ft_setrange(argv[1], tab, data);
	//ft_images(data);//matrix
}
