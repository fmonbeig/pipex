/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:29:05 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/28 14:28:55 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char **cmd)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	list->cmd_path = NULL;
	if (!list)
		return (NULL);
	list->cmd = cmd;
	list->next = NULL;
	return (list);
}
