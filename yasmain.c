/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yasmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/05/04 10:55:06 by ybestrio         ###   ########.fr       */
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

int	ft_control(int fd, char *line)
{
	if ((line = get_next_line(fd)))
	{
		return (1);
	}
	return (0);

}

void	ft_setrange(char *path, char **tab, t_data *data)
{
	int		fd;
	char	*line = NULL;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	fd = open(path, O_RDWR);
	while ((line = get_next_line(fd)))
	{
		if (strlen(line) > len)
			len = strlen(line);
		i++;
		free(line);
	}
	close(fd);
	data->map_h = i;
	data->map_l = len;
	tab = ft_calloc(sizeof(char *), i + 3);
	fd = open(path, O_RDWR);
	i = -1;
	while ((line = get_next_line(fd)))
		tab[++i] = line;

	close(fd);
	ft_setup(tab, data, len);
}

void	ft_setup(char **tab, t_data *data, size_t len)
{
	len = 0;
	ft_dividein3(tab, data);
	ft_error(data);
}

void	ft_nameissues(char *str)
{
	int	i;

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


void	ft_revlines(t_data *data, int i)
{
	char c;
	int k;
	int m = 0;
	int max;
	int len = 0;

/*	k = strlen(data->map[i]);
	printf("k = %d\n", k);
	printf("len = %d\n\n", len);

	while (k < len && data->map[i][0] != '\n')
	{
		data->map[i][k] = '1';
		k++;
	}
*/

	while (data->map[m] != 0)
	{
		if ((int)strlen(data->map[m]) > len)
			len = strlen(data->map[m]);
		m++;
	}
	k = strlen(data->map[i]);
	m = 0;
	while (k != 0)
	{
		k--;
		if (data->map[i][k] == '1')
		{
			while (k < len)
			{
				data->map[i][k] = '1';
				k++;
			}
			break ;
		}
	}

	k = strlen(data->map[i]);

	max = len / 2;
	
	while ((data->map[i][k] == '\n' || data->map[i][k] == 0) && k > 0)
		k--;
	
	while (k >= 0 && k >= max)
	{
		c = data->map[i][k];
		data->map[i][k] = data->map[i][m];
		data->map[i][m] = c;
		m++;
		k--;
	}
}


void	yasin(t_data *data, int argc, char **argv)
{
	char	**tab;
	
	tab = NULL;
	data->argc = argc;
	data->lowhei = 0;
	ft_nameissues(argv[1]);
	ft_setrange(argv[1], tab, data);
	int i = 0;
	i = 0;
	while (data->map[i] != 0)
	{
		ft_revlines(data, i);
			i++;	
	}
	i = 0;
	int k = 0;
	while (data->map[i] != 0)
	{
		while (data->map[i][k] != 0)
		{
			ft_setposition(data, i, k);
			k++;
		}
		k = 0;
		i++;
	}
}
