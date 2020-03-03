/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:29:52 by ybuhai            #+#    #+#             */
/*   Updated: 2020/03/03 20:58:44 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# define BUFFSIZE 100

#include "libftprintf.h"
#include <math.h>
#define F(X, Y, Z) (((X) & (Y)) | ((~X) & (Z)))
#define G(X, Y, Z) (((X) & (Z)) | ((~Z) & (Y)))
#define H(X, Y, Z) ((X) ^ (Y) ^ (Z))
#define I(X, Y, Z) ((Y) ^ ((~Z) | (X)))

typedef struct	s_ssl
{
	void		*(*func_ptr)(struct s_ssl *, int len);
	char		*filename;
	char		*string;
	int			f_quiet;
	int			f_reverse;
	int			f_parse;
	int			f_string;
	char		was_parse;
}				t_ssl;

int check_argv(t_ssl *ssl, char **arr);
void *md5(t_ssl *ssl, int len);
void *sha256(t_ssl *ssl, int len);
void handle_encryption(t_ssl *ssl, char **argv);
void usage(char *str);
void usage_option_requires_argument(void);
void usage_illegal_option(char c);
void usage_read_error(void);
void *ft_str_concatinate(void *s1, void *s2, int len1, int len2);
void print_from_console(t_ssl *ssl, void *s, int len);

#endif
