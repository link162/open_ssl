#include "ft_ssl.h"

int scan_type(t_ssl *ssl, char *str)
{
	if (!ft_strcmp(str, "md5"))
		ssl->func_ptr = md5;
	else if (!ft_strcmp(str, "sha256"))
		ssl->func_ptr = sha256;
	if (ssl->func_ptr)
		return (1);
	return (0);
}

int	check_flags(char *str, t_ssl *ssl)
{
	int i;

	i = 1;
	if (!str || ft_strlen(str) < 2 || str[0] != '-')
		return (-1);
	while (str[i])
	{
		if (str[i] == 'q')
			ssl->f_quiet++;
		else if (str[i] == 'r')
			ssl->f_reverse++;
		else if (str[i] == 'p')
			ssl->f_parse++;
		else if (str[i] == 's')
		{
			ssl->f_string = 1;
			return (i + 1);
		}
		else
			return (i);
		i++;
	}
	return (0);
}

void	error_handle(t_ssl *ssl, int res, int i, char **argv)
{
	if (res == 1)
	{
		ft_printf("md5: illegal option -- %c\n\
usage: md5 [-pqr] [-s string] [files ...]\n", argv[i][res]);
		exit(-1);
	}
	if (ssl->f_string && !argv[i][res] && !argv[i + 1])
	{
		ft_printf("md5: option requires an argument -- s\n\
				usage: md5 [-pqrtx] [-s string] [files ...]\n");
		exit(-1);
	}
}

void read_string_from_console(t_ssl *ssl)
{
	char	*res;
	char	*tmp;
	char	buff[BUFFSIZE];
	int		i;

	res = ft_strnew(0);
	while (0 < (i = read(0, buff, BUFFSIZE - 1)))
	{
		
		tmp = ft_strjoin(res, buff);
		free(res);
		res = tmp;
	}
	handle_encryption(ssl, res, NULL);
	free(res);
}

void parse_args(t_ssl *ssl)
{
	char *str;

	ssl->was_parse = 1;
	read_string_from_console(ssl);
	while(--(ssl->f_parse))
		handle_encryption(ssl, "", NULL);
	if (ssl->f_reverse)
		handle_encryption(ssl, "", NULL);
}

int check_argv(t_ssl *ssl, char **argv)
{
	int		i;
	int		res;

	i = 1;
	if (!argv || !scan_type(ssl, argv[0]))
		return (0);
	while (!(res = check_flags(argv[i], ssl)))
		i++;
	if (ssl->f_parse)
		parse_args(ssl);
	while (ssl->f_parse--)
		read_string_from_console(ssl);
	if (res > 1 && !ssl->f_string)
		usage_illegal_option(argv[i][res]);
	if (ssl->f_string && !argv[i][res] && !argv[i + 1])
		usage_option_requires_argument();
	if (ssl->f_string)
		ssl->string = argv[i][res] ? &argv[i++][res] : argv[++i];
	if (!argv[i] && !ssl->was_parse)
		read_string_from_console(ssl);
	else
		ssl->filename = argv[i++];
	handle_encryption(ssl, NULL, &argv[i]);
	return (1);
}
