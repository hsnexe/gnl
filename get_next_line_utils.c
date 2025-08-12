/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */

/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:45:34 by hashammo          #+#    #+#             */
/*   Updated: 2025/08/02 15:45:51 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	 size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*newp;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	newp = malloc(ft_strlen(s) + 1);
	if (!newp)
		return (NULL);
	while (s[i])
	{
		newp[i] = s[i];
		i++;
	}
	newp[i] = '\0';
	return (newp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	i;
	size_t	j;

	if (!s1 && s2)
		return (ft_strdup(s2));
    if (!s2)
            return(NULL);
	j = 0;
	i = 0;
	news = malloc((ft_strlen(s1) +ft_strlen(s2) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		news[i + j] = s2[j];
		j++;
	}
	news[i + j] = '\0';
 //   free(s1);
	return (news);
}

char	*ft_strchr(const char *s, int c)
{
    if(!s)
        return (NULL);
    while(*s)
    {
        if(*s == (char)c)
               return((char *)s);
         s++;
    }
    if(c== '\0')
        return ((char *)s);
    return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*news;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	news = malloc(len + 1);
	if (!news)
		return (NULL);
	while (i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}
