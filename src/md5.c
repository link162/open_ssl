#include "ft_ssl.h"
#include <stdio.h>

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

void *md5(t_ssl *ssl, int len)
{
	unsigned char *st = malloc(512);
	int table[64];

	ft_bzero(st, 512);
	st[0] = 0x80;
	set_table(table);
	static uint32_t ABCD[4];
	static uint32_t abcd[4];
	ABCD[0] = 0x67452301;
	ABCD[1] = 0xEFCDAB89;
	ABCD[2] = 0x98BADCFE;
	ABCD[3] = 0x10325476;
	ft_memcpy(abcd, ABCD, 128);
	uint32_t s[4][4] = {{7, 12, 17, 22}, {5,  9, 14, 20}, {4, 11, 16, 23}, {6, 10, 15, 21}};
	uint32_t f, g;
	uint32_t *str = (uint32_t *)st;
	for (int i = 0; i < 64; i++)
	{
		if (i >= 0 && i <= 15)
		{
			f = F(ABCD[1], ABCD[2], ABCD[3]);
			g = i;
		}
		if (i >= 16 && i <= 31)
		{
			f = G(ABCD[1], ABCD[2], ABCD[3]);
			g = (i * 5 + 1) % 16;
		}
		if (i >= 32 && i <= 47)
		{
			f = H(ABCD[1], ABCD[2], ABCD[3]);
			g = (i * 3 + 5) % 16;
		}
		if (i >= 48 && i <= 63)
		{
			f = I(ABCD[1], ABCD[2], ABCD[3]);
			g = (i * 7) % 16;
		}
		f = f + ABCD[0] + table[i] + str[g];
		ABCD[0] = ABCD[3];
		ABCD[3] = ABCD[2];
		ABCD[2] = ABCD[1];
		ABCD[1] = ABCD[1] + ((f << s[i / 16][i % 4]) | (f >> (32 - s[i / 16][i % 4])));
	}
	abcd[0] += ABCD[0];
	abcd[1] += ABCD[1];
	abcd[2] += ABCD[2];
	abcd[3] += ABCD[3];
	for(int t = 0; t < 4; t++)
	{
		uint8_t *pt = (uint8_t *)&abcd[t];
		for (int a = 0; a < 4; a++)
		{
			ft_printf("%x", *pt);
			pt++;
		}
	}
	ft_printf("\n");
	return NULL;
}
