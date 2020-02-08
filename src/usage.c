#include "ft_ssl.h"

void usage_illegal_option(char c)
{
	ft_printf("md5: illegal option -- %c\n\
usage: md5 [-pqr] [-s string] [files ...]\n", c);
	exit(-1);
}
void usage_option_requires_argument(void)
{
	ft_printf("md5: option requires an argument -- s\n\
			usage: md5 [-pqrtx] [-s string] [files ...]\n");
}

void	usage(char *str)
{
	if (str)
		ft_printf("ft_ssl:Error: '%s' is an invalid command.\n\
Standart commands\n\
\n\
Message Digest commands(see the 'dgst' command for more details)\n\
md5\n\
sha215\n\
\n\
Cipher commands (see the 'enc' command for more details)\n\
\n\
", str);
}

