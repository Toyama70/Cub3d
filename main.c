/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/08 13:17:15 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_setrange(t_range *range, char *path, char **tab, t_game *game)
{
	int fd;
	int cursor;
	char *line;
	int len = 0;

	cursor = 0;
	fd = open(path, O_RDWR);
	int i = 0;
	int k = 0;
	while ((line = get_next_line(fd)))
	{
		if (strlen(line) > len)
			len = strlen(line);
		i++;
		free(line);
	}
	close(fd);
	game->maphei = i;
	game->maplen = len;
	tab = malloc(sizeof(char *) * i); //I will need to free this array
	while (k < i)
	{
		tab[i] = calloc(sizeof(char), len);
		k++;
	}
	
	fd = open(path, O_RDWR); 
	i = 0;
	while ((line = get_next_line(fd))) // Copies lines in double array
	{
		tab[i] = line;
		i++;
	}
	close(fd);
	ft_dividein3(tab, game, len);

}

/*
void ft_parsemap(char *line, char **tab)
{
	int i = 0;
	int fd; 
	
	fd = open(str, O_RDWR);
	while()
}
*/

void	ft_maphandler(t_range *range, char *path, char **tab, t_game *game)
{
	char *line;

	line = NULL;
	ft_setrange(range, path, tab, game);
}

int main(int argc, char **argv)
{
	t_game game;
	char **tab;
	t_range range;

	game.argc = argc;
	ft_maphandler(&range, argv[1], tab, &game);

	printf("gamefloor = %x\n", game.floor);
}
