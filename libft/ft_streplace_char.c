/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streplace_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:39:25 by artclave          #+#    #+#             */
/*   Updated: 2024/01/09 20:26:49 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_streplace_char(char **str, char old_char, char new_char)
{
	int	i;

	i = -1;
	while ((*str)[++i] != '\0')
	{
		if ((*str)[i] == old_char)
			(*str)[i] = new_char;
	}
}
