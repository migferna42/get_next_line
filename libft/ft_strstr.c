/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adomingu <adomingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:25:08 by adomingu          #+#    #+#             */
/*   Updated: 2014/11/03 22:35:53 by adomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s2);
	if (!s2[i])
		return ((char *)s1);
	while (s1[i])
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
