/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:40:49 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/28 11:41:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd1;
	int		fd2;
	t_data	*data;

	if (argc == 5)
	{
		data = init_struct(argc, argv);
		take_env(data, env);
		parse_cmd(argc, argv, data);
		init_pipe(argc, data);
		pipex(argc, data, env);
		free_all_success(data);
	}
	else
		error_not_enough_argument(data);
}

void	pipex(int argc, t_data *data, char **env)
{
	int	cmd_numb;
	int	pid;
	int	x;

	cmd_numb = 0;
	x = -1;
	while (++x < argc - 3)
	{
		++cmd_numb;
		data->i++;
		pid = fork();
		if (pid < 0)
			error_fork(data);
		if (pid == 0)
			do_cmd(cmd_numb, argc, data, env);
	}
	parent_process(data, argc, pid);
}

void	do_cmd(int cmd_numb, int argc, t_data *data, char **env)
{
	if (cmd_numb == 1)
		first_process(data, argc, select_list(cmd_numb, data), env);
	else if (cmd_numb > 1 && cmd_numb < argc - 3)
		middle_process(data, argc, select_list(cmd_numb, data), env);
	else if (cmd_numb == argc - 3)
		last_process(data, argc, select_list(cmd_numb, data), env);
}
