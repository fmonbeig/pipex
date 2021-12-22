/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:52:55 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/28 11:41:10 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_data	*init_struct(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->cmd = NULL;
	data->path = NULL;
	data->list = NULL;
	data->end = NULL;
	data->i = -1;
	data->argc = argc;
	data->infile = open(argv[1], O_RDONLY);
	data->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->infile < 0 || data->outfile < 0)
		error_opening_file(data);
	return (data);
}

void	init_pipe(int argc, t_data *data)
{
	int	i;

	i = -1;
	data->end = malloc(sizeof(int *) * (argc - 2));
	while (++i < (argc - 2))
	{
		data->end[i] = malloc(sizeof(int) * 2);
		pipe(data->end[i]);
		if (pipe(data->end[i]) == -1)
			error_pipe(data);
	}
}
