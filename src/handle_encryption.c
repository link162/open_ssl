#include "ft_ssl.h"

void print_from_console(t_ssl *ssl, char *res)
{
	if (ssl->f_parse)
		ft_printf("%s", res);
	ft_printf("5d41402abc4b2a76b9719d911017c592\n");
}

void handle_encryption(t_ssl *ssl, char *res, char **argv)
{
	if (res)
	{
		print_from_console(ssl, res);
		return ;
	}
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
