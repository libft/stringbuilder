/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:58:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 12:39:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft_stringbuilder.h>

#define BUFFER_SIZE 1024

int	main(int argc, char **argv)
{
	char			value[BUFFER_SIZE];
	size_t			buffer_size;
	t_stringbuilder	*sb;
	char			*str;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (argc == 3)
		freopen(argv[1], "r", stdin);
	buffer_size = atoi(argv[1]);
	sb = new_stringbuilder(buffer_size);
	while (fgets(value, BUFFER_SIZE - 1, stdin))
	{
		if (stringbuilder_append(sb, strlen(value), value))
			return (EXIT_FAILURE);
		str = stringbuilder_to_string(sb, 0);
		if (!str)
			return (EXIT_FAILURE);
		puts(str);
		free(str);
	}
	if (ferror(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
