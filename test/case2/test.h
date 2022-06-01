/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:05:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/01 15:31:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdbool.h>

typedef struct s_context
{
	FILE	*stream;
	size_t	buffer_size;
}	t_context;

bool	test_append_string(t_context *context);
bool	test_append_char(t_context *context);
bool	test_append(t_context *context);

#endif
