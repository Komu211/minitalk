/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:04:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/06 13:30:35 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_retrieve_next_line(char *static_buffer)
{
	int		len;
	char	*r_buffer;
	int		nl_index;

	nl_index = ft_gnl_strchr(static_buffer, '\n');
	if (nl_index == -1)
		len = ft_gnl_strlen(static_buffer);
	else
		len = nl_index + 1;
	r_buffer = malloc(len + 1);
	if (!r_buffer)
		return (NULL);
	ft_gnl_strlcpy(r_buffer, static_buffer, len + 1);
	if (static_buffer[len] == '\0')
		static_buffer[0] = '\0';
	else
		ft_gnl_strlcpy(static_buffer, static_buffer + len,
			ft_gnl_strlen(static_buffer + len) + 1);
	return (r_buffer);
}

static char	*gnl_load_next_set(int fd, char *static_buffer, int *status)
{
	char	*tmp;
	char	*new_buffer;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		free(static_buffer);
		return (NULL);
	}
	*status = read(fd, tmp, BUFFER_SIZE);
	if (*status <= 0)
	{
		free(tmp);
		if (*status < 0 || static_buffer[0] == '\0')
			return (free(static_buffer), NULL);
		return (static_buffer);
	}
	tmp[*status] = '\0';
	new_buffer = ft_gnl_strjoin(static_buffer, tmp);
	free(tmp);
	free(static_buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

static char	*gnl_retrieve_and_cleanup(char **static_buffer)
{
	char	*line;

	if ((*static_buffer)[0] == '\0')
	{
		free(*static_buffer);
		*static_buffer = NULL;
		return (NULL);
	}
	line = gnl_retrieve_next_line(*static_buffer);
	if (!line)
	{
		free(*static_buffer);
		*static_buffer = NULL;
	}
	return (line);
}

static void	gnl_fd_lst_rm(int fd, t_fd_list **node, int all)
{
	t_fd_list	*prev;
	t_fd_list	*curr;

	curr = *node;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd || all == 1)
		{
			if (prev != NULL)
				prev->next = curr->next;
			else
				*node = curr->next;
			if (all == 1 && (*node)->next)
				gnl_fd_lst_rm(fd, &((curr)->next), all);
			free(curr->buffer);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_list	*node = NULL;
	char				*line;
	int					status;
	t_fd_list			*curr_fd;

	status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr_fd = node;
	while (curr_fd != NULL && curr_fd->fd != fd)
		curr_fd = curr_fd->next;
	if (curr_fd == NULL)
		curr_fd = ft_gnl_lst_add_new(fd, &node);
	if (!curr_fd)
		return (gnl_fd_lst_rm(fd, &node, 1), NULL);
	while (ft_gnl_strchr(curr_fd->buffer, '\n') == -1 && status > 0)
	{
		curr_fd->buffer = gnl_load_next_set(fd, curr_fd->buffer, &status);
		if (!curr_fd->buffer || status < 0)
			return (gnl_fd_lst_rm(fd, &node, 0), NULL);
	}
	line = gnl_retrieve_and_cleanup(&curr_fd->buffer);
	if (!line || !curr_fd->buffer)
		gnl_fd_lst_rm(fd, &node, 0);
	return (line);
}
