/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:46:20 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/27 17:18:27 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// +------------------------------------------+ //
//   System header files                        //
// +------------------------------------------+ //

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

// +------------------------------------------+ //
//   Libft                                      //
// +------------------------------------------+ //

# include "../libft/libft.h"

// +------------------------------------------+ //
//   MACRO                                      //
// +------------------------------------------+ //

# define BUFFER_SIZE 25

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //

typedef struct s_data
{
	char	**cmd;
	char	**path;
	int		**end;
	int		i;
	int		argc;
	int		infile;
	int		outfile;
	t_list	*list;
}		t_data;

// +------------------------------------------+ //
//                  main                        //
// +------------------------------------------+ //
int		main(int argc, char **argv, char **env);
t_data	*init_struct(int argc, char **argv);
void	init_pipe(int argc, t_data *data);
void	pipex(int argc, t_data *data, char **env);
void	do_cmd(int cmd_numb, int argc, t_data *data, char **env);
// +------------------------------------------+ //
//                  process                       //
// +------------------------------------------+ //
void	first_process(t_data *data, int argc, t_list *list, char **env);
void	middle_process(t_data *data, int argc, t_list *list, char **env);
void	last_process(t_data *data, int argc, t_list *list, char **env);
void	parent_process(t_data *data, int argc, int pid);
// +------------------------------------------+ //
//                  utils                       //
// +------------------------------------------+ //
void	take_env(t_data *data, char **env);
void	parse_cmd(int argc, char **argv, t_data *data);
void	find_command_path(t_data *data, t_list *list);
t_list	*select_list(int cmd_numb, t_data *data);
// +------------------------------------------+ //
//                  free                       //
// +------------------------------------------+ //
void	free_all_success(t_data *data);
void	free_all_failure(t_data *data);
void	free_split(char **ptr);
void	close_all_fd(int argc, t_data *data);
void	free_pipe(t_data *data);
// +------------------------------------------+ //
//                  error                       //
// +------------------------------------------+ //
void	error_pipe(t_data *data);
void	error_fork(t_data *data);
void	error_command(t_data *data);
void	error_opening_file(t_data *data);
void	error_not_enough_argument(t_data *data);
// +------------------------------------------+ //
//                  print                       //
// +------------------------------------------+ //
void	print_list(t_data *data);

#endif
