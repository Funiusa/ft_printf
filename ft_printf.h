/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:29:56 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:14:59 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct			s_parser
{
	int					arg_type;
	int					f_min;
	int					f_zero;
	int					zr;
	int					sp;
	int					width;
	int					pre;
	char				*arg_s;
	int					arg_c;
	long unsigned int	arg_p;
	int					ret_count;
	unsigned int		arg_u;
	int					neg;

}						t_pars;

int						ft_printf(const char *format, ...);
const char				*ft_flags(const char *format, t_pars *p);
const char				*ft_width(const char *format, t_pars *p, va_list args);
const char				*ft_t_s(const char *format, t_pars *p, va_list args);
const char				*ft_t_udi(const char *format, t_pars *p, va_list args);
const char				*ft_t_c(const char *format, t_pars *p, va_list args);
const char				*ft_t_x(const char *format, t_pars *p, va_list args);
const char				*ft_t_p(const char *format, t_pars *p, va_list args);
const char				*ft_t_parser(const char *frmt, t_pars *p, va_list arg);
const char				*ft_prec(const char *format, t_pars *p, va_list args);
void					ft_initialize(t_pars *p);

size_t					ft_strlen(const char *str);
void					ft_putchar(char c, t_pars *p);
void					ft_putstr(char *s, unsigned int len, t_pars *p);
void					ft_locate(char *str, t_pars *p);
void					ft_min_mod(char *str, t_pars *p);
void					ft_mod(char *str, t_pars *p);
void					ft_dot(unsigned int lens, t_pars *p);
void					ft_str_locate(t_pars *p);
void					ft_p_locate(char *str, t_pars *p);
void					ft_p_min_mod(char *str, t_pars *p);
void					ft_p_dot(unsigned int lens, t_pars *p);
void					ft_p_mod(char *str, t_pars *p);
void					ft_c_locate(char *str, t_pars *p);
char					*ft_strdup(char *src);

#endif
