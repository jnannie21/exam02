/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:44:09 by jnannie           #+#    #+#             */
/*   Updated: 2020/10/15 20:19:11 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int			width = 0;
int			precision = 0;
int			is_precision = 0;
int			neg = 0;
char		digits[] = "0123456789abcdef";
int			output_len = 0;

int		count_digits(long num, int base)
{
	int		i;

	i = 1;
	while (num /= base)
		i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char **format)
{
	int			res;

	res = 0;
	while (is_number(**format))
	{
		res = res * 10 + (**format - 48);
		(*format)++;
	}
	return (res);
}

void		print_int_base(long int_res, int base)
{
	if (int_res < base)
	{
		write(1, digits + int_res, 1);
		output_len++;
	}
	else
	{
		print_int_base(int_res / base, base);
		print_int_base(int_res % base, base);
	}
}

void		print_int_format(long int_res, int base)
{
	int		len;
	int		i;

	if (int_res < 0)
	{
		neg = 1;
		int_res *= (-1);
	}
	len = count_digits(int_res, base);
	i = 0;
	if (precision > len)
	{
		if (width > precision + neg)
		{
			while (i++ < width - precision - neg)
			{
				write(1, " ", 1);
				output_len++;
			}
				
		}
		if (neg)
		{
			write(1, "-", 1);
			output_len++;
		}
		i = 0;
		while (i++ < precision - len)
		{
			write(1, "0", 1);
			output_len++;
		}
	}
	else if (width > len + neg)
	{
		while (i++ < width - len - neg)
		{
			write(1, " ", 1);
			output_len++;
		}
		if (neg)
		{
			write(1, "-", 1);
			output_len++;
		}
	}
	else if (neg)
	{
		write(1, "-", 1);
		output_len++;
	}
	print_int_base(int_res, base);
}

void		print_string(char *ch_res)
{
	int			i = 0;
	int			len;

	len = ft_strlen(ch_res);
	if (is_precision && precision < len)
		len = precision;
	if (width > len)
	{
		while (i++ < width - len)
		{
			write(1, " ", 1);
			output_len++;
		}
	}
	while (len--)
	{
		write(1, ch_res++, 1);
		output_len++;
	}
}

void		print_by_format(char **format, va_list args)
{
	long			int_res;
	char			*ch_res;

	(*format)++;
	if (is_number(**format))
		width = ft_atoi(format);
	if (**format == '.')
	{
		is_precision = 1;
		(*format)++;
		precision = ft_atoi(format);
	}
	if (**format == 'd')
	{
		int_res = va_arg(args, int);
		print_int_format(int_res, 10);
		(*format)++;
	}
	else if (**format == 'x')
	{
		int_res = va_arg(args, unsigned int);
		print_int_format(int_res, 16);
		(*format)++;
	}
	else if (**format == 's')
	{
		ch_res = va_arg(args, char *);
		print_string(ch_res);
		(*format)++;
	}
}

void		print_to_percent(char **format)
{
	while (**format && **format != '%')
	{
		write(1, *format, 1);
		(*format)++;
		output_len++;
	}
}

int			ft_printf(const char *format, ... )
{
	va_list			args;

	va_start(args, format);
	output_len = 0;
	while (*format)
	{
		width = 0;
		precision = 0;
		is_precision = 0;
		neg = 0;
		if (*format == '%')
			print_by_format((char **)&format, args);
		else
			print_to_percent((char **)&format);
	}
	va_end(args);
	return (output_len);
}


