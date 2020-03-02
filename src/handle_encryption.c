#include "ft_ssl.h"

void print_from_console(t_ssl *ssl, void *res, int len)
{
	if (ssl->f_parse)
		write(1, res, len);
	ft_printf("5d41402abc4b2a76b9719d911017c592\n");
}

void handle_encryption(t_ssl *ssl, char **argv)
{
	ssl->func_ptr(ssl, 0);
	if (ssl->string)
	{
		if (!ssl->f_reverse && !ssl->f_quiet)
			ft_printf("MD5 (\"%s\") = ", ssl->string);
		ft_printf("5d41402abc4b2a76b9719d911017c592");
		if (ssl->f_reverse && !ssl->f_quiet)
			ft_printf(" \"%s\"", ssl->string);
		ft_putchar('\n');
	}
	while (ssl->filename)
	{
		if (!ssl->f_reverse && !ssl->f_quiet)
			ft_printf("MD5 (%s) = ", ssl->filename);
		ft_printf("5d41402abc4b2a76b9719d911017c592");
		if (ssl->f_reverse && !ssl->f_quiet)
			ft_printf(" %s", ssl->filename);
		ft_putchar('\n');
		ssl->filename = *argv;
		argv++;
	}
}
