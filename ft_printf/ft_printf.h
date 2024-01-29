/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:27:16 by jmarin-o          #+#    #+#             */
/*   Updated: 2024/01/24 19:10:57 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// STRINGS: ALL OPERATING SYSTEMS
# define S_EMPTY "(null)"
# define S_EMPTY_L 6

// POINTERS: ALL OPERATING SYSTEMS EXCEPT LINUX
# define P_EMPTY "0x0"
# define P_EMPTY_L 3

// POINTERS: LINUX
// # define P_EMPTY "(nil)"
// # define P_EMPTY_L 5

# include "../libft/libft.h" // For libft functions
# include <stdarg.h>  		 // For va_start, va_arg, va_copy, va_end
# include <stdbool.h> 		 // For type bool

typedef struct s_opt
{
	bool	is_negative;
	bool	has_zero;
	bool	has_sharp;
	bool	has_space;
	bool	has_plus;
	bool	has_minus;
	bool	has_precision;
	bool	print_plus;
	bool	print_minus;
	int		field_min_width;
	int		precision;
	int		spaces;
	int		zeros;
}	t_opt;

typedef struct s_conversion
{
	char	conversion;
	t_opt	options;
}	t_conversion;

typedef union u_data
{
	char				character;
	char				*string;
	void				*pointer;
	long long			number;
	unsigned long long	u_number;
}	t_data;

// FT_PRINTF PROGRAM
int		ft_printf(const char *format, ...);

// PROCESS DATA
int		ft_print_data(t_data data, t_conversion conversion);

// CONVERTERS
int		ft_print_character(char c, t_opt opt);
int		ft_print_string(char *str, t_opt opt);
int		ft_print_pointer(void *ptr, t_opt opt);
int		ft_print_number(long nl, t_opt opt);
int		ft_print_hexa(int nl, int is_maj, t_opt opt);

// INIT FUNCTIONS
void	init_opt(t_opt *opt);
void	init_conversion(t_conversion *conversion);
void	init_data(t_data *data);

// UTILS
int		print_char(char c);
int		print_str(char *str);
int		print_number_base(int nbr, char *base);
int		print_minus(t_opt *opt);
int		print_plus(t_opt *opt);
int		print_while_types(t_opt *opt, int type);
int		print_sharp(bool is_maj);

#endif
