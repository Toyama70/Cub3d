/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:18:03 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/14 12:22:14 by ybestrio         ###   ########.fr       */
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

void	ft_setrange(t_range *range, char *path, char **tab, t_game *game)
{
	int fd;
	char *line;
	int len = 0;
	int i = 0;
	int k = 0;
	
	fd = open(path, O_RDWR);
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
	
	tab = calloc(sizeof(char *), i + 1); //I will need to free this array
	fd = open(path, O_RDWR); 
	i = 0;
	while ((line = get_next_line(fd))) // Copies lines in double array
	{
		tab[i] = line;
		i++;
	}
	close(fd);
	ft_exception(tab, game, len);
	
	
	ft_dividein3(tab, game, len);
	ft_error(game, len);
}

void	ft_maphandler(t_range *range, char *path, char **tab, t_game *game)
{

	ft_setrange(range, path, tab, game);
//	free_tab
}


int main(int argc, char **argv)
{
	t_game game;
	char **tab;
	t_range range;
	game.lowhei = 0;
	game.argc = argc;
	ft_maphandler(&range, argv[1], tab, &game);

/*	printf("%s\n", game.txtr[0]);
	printf("%s\n", game.txtr[1]);
	printf("%s\n", game.txtr[2]);
	printf("%s\n", game.txtr[3]);

	printf("%s", game.map[0]);
	printf("%s", game.map[1]);
	printf("%s", game.map[2]);
	printf("%s", game.map[3]);
	printf("%s", game.map[4]);
	printf("%s", game.map[5]);
	printf("%s", game.map[6]);
	printf("%s", game.map[7]);
	printf("%s", game.map[8]);
	printf("%s", game.map[9]);
	printf("%s", game.map[10]);*/
	free_tab(game.map);
	//free_tab(tab);
	//free_tab(game.txtr);

	system("leaks a.out");

}
