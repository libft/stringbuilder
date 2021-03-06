/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:04:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 15:34:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "leak_test/include/ft/leak_test.h"

#include "test.h"

int	main(int argc, char **argv)
{
	int			result;
	t_context	context;

	if (argc != 3)
		return (EXIT_FAILURE);
	context.buffer_size = atoi(argv[1]);
	context.stream = fopen(argv[2], "r+");
	if (!context.stream)
		return (EXIT_FAILURE);
	result = leak_test((t_leak_test)(&test_append_string), &context, NULL);
	if (!result)
		result = leak_test((t_leak_test)(&test_append_char), &context, NULL);
	if (!result)
		result = leak_test((t_leak_test)(&test_append), &context, NULL);
	fclose(context.stream);
	if (result)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
