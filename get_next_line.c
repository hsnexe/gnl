/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:52:02 by hashammo          #+#    #+#             */
/*   Updated: 2025/08/19 14:37:58 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract(char *s)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = ft_substr(s, 0, i);
	return (line);
}

char	*join_help(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*update(char *s)
{
	int		i;
	char	*new_string;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new_string = ft_substr(s, i + 1, ft_strlen(s) - i -1);
	free(s);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while ((!s || !ft_strchr(s, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		s = ft_strjoin(s, buffer);
	}
	if (bytes_read == 0 && (!s || s[0] == '\0'))
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	line = extract(s);
	s = update(s);
	return (line);
}
