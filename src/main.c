#include "ft_ssl.h"

void	free_arr(char **str)
{
	char **tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
}

void 	console_ssl(t_ssl *ssl)
{
	char	*str;
	char	**tmp;
	int		i;

	while(1)
	{
		ft_bzero(ssl, sizeof(t_ssl));
		ft_printf("ft_ssl> ");
		i = get_next_line(0, &str);
		if (!str)
			continue ;
		tmp = ft_strsplit(str, ' ');
		if (!ft_strcmp(str, "q") || !i)
		{
			free_arr(tmp);
			free(str);
			break ;
		}
		if (!check_argv(ssl, tmp))
			usage(str);
		free_arr(tmp);
		free(str);
		str = NULL;
	}
}

int main(int argc, char **argv)
{
	t_ssl	ssl;

	ft_bzero(&ssl, sizeof(t_ssl));
	if (argc == 1)
		console_ssl(&ssl);
	else
		if (!check_argv(&ssl, &argv[1]))
			usage(argv[1]);
	//system("leaks ft_ssl");
}
