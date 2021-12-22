/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:26:14 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/12/22 11:52:36 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	here_doc_filling(char **argv, t_data *data)
{
	char	*line;

	while (get_next_line(0, &line, 0) != 0)
	{
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			if (line)
				free(line);
			line = NULL;
			get_next_line(0, &line, 1);
			break ;
		}
		write(STDOUT_FILENO, ">", 1);
		write(data->here_doc, line, ft_strlen(line));
		write(data->here_doc, "\n", 1);
		if (line)
			free(line);
	}
}
