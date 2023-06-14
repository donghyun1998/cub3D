/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:51:00 by donghyk2          #+#    #+#             */
/*   Updated: 2023/06/14 16:51:01 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	*make_node(char *line)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->line = ft_strdup(line);
	list->next = NULL;
	return (list);
}

void	add_back_list(t_list **list, char *line)
{
	t_list	*head;
	t_list	*new;

	new = make_node(line);
	if (*list == NULL)
		*list = new;
	else
	{
		head = *list;
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = new;
		*list = head;
	}
}

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->line);
		free(list);
		list = next;
	}
}
