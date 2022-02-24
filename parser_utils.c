/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:07:08 by ybestrio          #+#    #+#             */
/*   Updated: 2022/02/24 11:08:42 by ybestrio         ###   ########.fr       */
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

void	ft_setgnl(t_gnl *gnl, char *path)
{
	gnl->len = 0;
	gnl->i = 0;
	gnl->fd = open(path, O_RDWR);
	if (gnl->fd == -1)
		exit (1);
}

int	assign(t_gnl *gnl)
{
	gnl->line = get_next_line(gnl->fd);
	if (gnl->line)
		return (1);
	else
		return (0);
}
