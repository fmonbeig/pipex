/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:53:01 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/28 14:54:40 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_process(t_data *data, int argc, t_list *list, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (i == data->i + 1 && j == 1)
				continue ;
			close(data->end[i][j]);
		}
	}
	dup2(data->infile, STDIN_FILENO);
	dup2(data->end[data->i + 1][1], STDOUT_FILENO);
	close(data->end[data->i + 1][1]);
	close(data->infile);
	if (list->cmd_path == NULL || execve(list->cmd_path, list->cmd, env) == -1)
		error_command(data);
}

void	middle_process(t_data *data, int argc, t_list *list, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (i == data->i + 1 && j == 1)
				continue ;
			else if (i == data->i && j == 0)
				continue ;
			close(data->end[i][j]);
		}
	}
	dup2(data->end[data->i][0], STDIN_FILENO);
	dup2(data->end[data->i + 1][1], STDOUT_FILENO);
	close(data->end[data->i + 1][1]);
	close(data->end[data->i][0]);
	if (list->cmd_path == NULL || execve(list->cmd_path, list->cmd, env) == -1)
		error_command(data);
}

void	last_process(t_data *data, int argc, t_list *list, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (i == data->i && j == 0)
				continue ;
			close(data->end[i][j]);
		}
	}
	dup2(data->end[data->i][0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->end[data->i][0]);
	close(data->outfile);
	close(data->infile);
	if (list->cmd_path == NULL || execve(list->cmd_path, list->cmd, env) == -1)
		error_command(data);
}

void	parent_process(t_data *data, int argc, int pid)
{
	int	i;

	i = -1;
	close_all_fd(argc, data);
	while (++i < argc - 3)
		waitpid(pid, NULL, 0);
	free_all_success(data);
}
