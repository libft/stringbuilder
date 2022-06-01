/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:58:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 15:30:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft_stringbuilder.h>

#include "leak_test/include/ft/leak_test.h"

#include "test.h"

#define BUFFER_SIZE 1024

bool	test_append_string(t_context *context)
{
	char			value[BUFFER_SIZE];
	t_stringbuilder	*sb;
	t_err			err;

	fseek(context->stream, 0, SEEK_SET);
	leak_test_start();
	sb = new_stringbuilder(context->buffer_size);
	leak_test_end();
	if (!sb)
		return (false);
	err = false;
	while (!err && fgets(value, BUFFER_SIZE - 1, context->stream))
	{
		leak_test_start();
		err = stringbuilder_append_string(sb, value);
		free(stringbuilder_to_string(sb, 0));
		leak_test_end();
	}
	leak_test_start();
	stringbuilder_free(sb);
	leak_test_end();
	return (false);
}

bool	test_append_char(t_context *context)
{
	char			value[BUFFER_SIZE];
	t_stringbuilder	*sb;
	t_err			err;
	char			*tmp;

	fseek(context->stream, 0, SEEK_SET);
	leak_test_start();
	sb = new_stringbuilder(context->buffer_size);
	leak_test_end();
	if (!sb)
		return (false);
	err = false;
	while (!err && fgets(value, BUFFER_SIZE - 1, context->stream))
	{
		leak_test_start();
		tmp = value;
		while (!err && *tmp)
			err = stringbuilder_append_char(sb, *tmp++);
		free(stringbuilder_to_string(sb, 0));
		leak_test_end();
	}
	leak_test_start();
	stringbuilder_free(sb);
	leak_test_end();
	return (false);
}

bool	test_append(t_context *context)
{
	char			value[BUFFER_SIZE];
	t_stringbuilder	*sb;
	t_err			err;

	fseek(context->stream, 0, SEEK_SET);
	leak_test_start();
	sb = new_stringbuilder(context->buffer_size);
	leak_test_end();
	if (!sb)
		return (false);
	err = false;
	while (!err && fgets(value, BUFFER_SIZE - 1, context->stream))
	{
		leak_test_start();
		err = stringbuilder_append(sb, strlen(value), value);
		free(stringbuilder_to_string(sb, 0));
		leak_test_end();
	}
	leak_test_start();
	stringbuilder_free(sb);
	leak_test_end();
	return (false);
}
