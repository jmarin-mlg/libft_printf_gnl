/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 07:01:35 by jmarin-o          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:19 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialize the t_opt structure with default values.
**
** opt: A pointer to the t_opt structure to initialize.
*/
void	init_opt(t_opt *opt)
{
	opt->is_negative = false;
	opt->has_zero = false;
	opt->has_sharp = false;
	opt->has_space = false;
	opt->has_plus = false;
	opt->has_minus = false;
	opt->has_precision = false;
	opt->print_plus = false;
	opt->print_minus = false;
	opt->field_min_width = 0;
	opt->precision = -1;
	opt->spaces = 0;
	opt->zeros = 0;
}

/*
** Initialize the t_conversion structure with default values.
**
** conversion: A pointer to the t_conversion structure to initialize.
*/
void	init_conversion(t_conversion *conversion)
{
	conversion->conversion = '\0';
	init_opt(&conversion->options);
}

/*
** Initialize the t_data structure with default values.
**
** data: A pointer to the t_data structure to initialize.
*/
void	init_data(t_data *data)
{
	data->character = '\0';
	data->string = NULL;
	data->pointer = NULL;
	data->number = 0;
	data->u_number = 0;
}
