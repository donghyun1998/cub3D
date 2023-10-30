/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:51:09 by donghyk2          #+#    #+#             */
/*   Updated: 2023/10/30 19:34:38 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_background_map(t_cub *cub)
{
	int		idx;
	t_list	*cur;

	cur = cub->list;
	cub->map_info.map = malloc(sizeof(char *) * (cub->map_info.height + 1));
	if (cub->map_info.map == NULL)
		cub_error(cub, "Memory allocation failed");
	idx = -1;
	while (cur)
	{
		cub->map_info.map[++idx] = malloc(sizeof(char) * \
			(cub->map_info.width + 1));
		if (cub->map_info.map[idx] == NULL)
			cub_error(cub, "Memory allocation failed");
		ft_memset(cub->map_info.map[idx], ' ', cub->map_info.width + 1);
		ft_strncpy(cub->map_info.map[idx], cur->line, ft_strlen(cur->line));
		cub->map_info.map[idx][cub->map_info.width] = '\0';
		cur = cur->next;
	}
	cub->map_info.map[++idx] = NULL;
}

static char	*init_map_list(char *line, t_cub *cub)
{
	while (line)
	{
		if (*line == '\0')
			break ;
		cub->map_info.width = ft_max(ft_strlen(line), cub->map_info.width);
		cub->map_info.height++;
		add_back_list(&cub->list, line);
		free(line);
		line = ft_strrepl(get_next_line(cub->fd), '\n', '\0');
	}
	return (line);
}

void	parse_map(t_cub *cub)
{
	char	*line;

	while (42)
	{
		line = ft_strrepl(get_next_line(cub->fd), '\n', '\0');
		if (line == NULL)
			cub_error(cub, "Invaild map");
		if (is_empty_line(line) == 0)
			break ;
		free(line);
	}
	line = init_map_list(line, cub);
	while (line)
	{
		if (*line != '\0')
		{
			free(line);
			cub_error(cub, "Invaild map");
		}
		free(line);
		line = ft_strrepl(get_next_line(cub->fd), '\n', '\0');
	}
	set_background_map(cub);
	free_list(cub->list);
	cub->list = NULL;
}
