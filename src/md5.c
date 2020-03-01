#include "ft_ssl.h"

void set_table(int *table)
{
	int i;

	i = 0;
	while (i < 64)
	{
		table[i] = (unsigned)(fabs(sin(i + 1)) * 4294967296);
		i++;
	}
}

uint32_t F(uint32_t X, uint32_t Y, uint32_t Z)
{
	return ((X & Y) | (~X & Z));
}

uint32_t G(uint32_t X, uint32_t Y, uint32_t Z)
{
	return ((X & Z) | (~Z & Y));
}

uint32_t H(uint32_t X, uint32_t Y, uint32_t Z)
{
	return (X ^ Y ^ Z);
}

uint32_t I(uint32_t X, uint32_t Y, uint32_t Z)
{
	return (Y ^ (~Z | X));
}

void *md5(t_ssl *ssl, int len)
{
	char *str = malloc(512);
	int table[64];

	ft_bzero(str, 512);
	//ft_memcpy(str, ssl->string, len);
	str[0] = 0x80;
	str[511] = len;
	set_table(table);
	static uint32_t A = 0x01234567;
	static uint32_t B = 0x89ABCDEF;
	static uint32_t C = 0xFEDCBA98;
	static uint32_t D = 0x76543210;
	for (int i = 0; i < 16; i++)
	{
		
	}
	for (int i = 0; i < 16; i++)
	{
		
	}
	for (int i = 0; i < 16; i++)
	{
		
	}
	for (int i = 0; i < 16; i++)
	{
		
	}
	return NULL;
}
