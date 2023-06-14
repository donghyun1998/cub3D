/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:51:05 by donghyk2          #+#    #+#             */
/*   Updated: 2023/06/14 16:51:06 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_movable(char position)
{
	if (position == '0')
		return (1);
	if (position == 'N' || position == 'S'
		|| position == 'E' || position == 'W')
		return (2);
	return (0);
}

int	get_direction(int idx)
{
	if (idx % 4 == 3)
		return (0);
	return (idx % 4 - 1);
}

int	is_empty_line(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] != ' ')
			return (0);
		idx++;
	}
	return (1);
}
