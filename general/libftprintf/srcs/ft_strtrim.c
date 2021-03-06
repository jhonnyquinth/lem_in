/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:05:39 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	startt(char const *s)
{
	int		start;

	start = 0;
	while (s[start])
	{
		if (s[start] != ' ' && s[start] != '\n' && s[start] != '\t')
			break ;
		start++;
	}
	return (start);
}

static int	endd(char const *s)
{
	int		end;

	end = ft_strlen(s) - 1;
	while (end)
	{
		if (s[end] != ' ' && s[end] != '\n' && s[end] != '\t')
			break ;
		end--;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	start = startt(s);
	end = endd(s);
	if (start > end)
	{
		new = malloc(sizeof(char));
		*new = '\0';
		return (new);
	}
	if (!(new = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (start != end + 1)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
