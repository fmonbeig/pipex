/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:11:16 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/28 11:43:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all_success(t_data *data)
{
	if (data->path)
		free_split(data->path);
	if (data->end)
		free_pipe(data);
	if (data->list)
		ft_lstclear(data->list);
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
}

void	free_all_failure(t_data *data)
{
	if (data->path)
		free_split(data->path);
	if (data->end)
		free_pipe(data);
	if (data->list)
		ft_lstclear(data->list);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free (ptr[i++]);
	free(ptr);
}

void	free_pipe(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->argc - 2)
		free (data->end[i]);
	free (data->end);
}

void	close_all_fd(int argc, t_data *data)
{
	int	i;

	i = -1;
	while (++i < argc - 2)
	{
		if (i != argc - 2)
			close(data->end[i][0]);
		if (i != 0)
			close(data->end[i][1]);
	}
}
