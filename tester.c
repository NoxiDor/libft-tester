#include "libft.h"
#include "test.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

char **results_to_void(int count, ...)
{
	char **result;
	va_list list;
	int i = 0;

	result = malloc(sizeof(char *) * count);
	va_start(list, count);
	while (i < count)
		result[i++] = va_arg(list, void *);
	va_end(list);
	return (result);
}

char *tostr(int i)
{
	int j = 0;
	int k = (i == 0);
	char *s = malloc(sizeof(int) * 13);

	int cpy = i;
	while (cpy != 0)
	{
		k++;
		cpy = cpy / 10;
	}
	while (j < k)
	{
		s[k - j - 1] = (i % 10) + '0';
		i /= 10;
		j++;
	}
	s[j] = 0;
	return (s);
}

void memset_tester()
{
	char *ft_memset1 = calloc(5, 1);
	char *ft_memset2 = calloc(8, 1);
	char *ft_memset3 = calloc(10, 1);
	char *memset1 = calloc(5, 1);
	char *memset2 = calloc(8, 1);
	char *memset3 = calloc(10, 1);
	ft_memset(ft_memset1, '0', 3);
	ft_memset(ft_memset2, 'A', (0));
	ft_memset(ft_memset3, '1', 10);
	memset(memset1, '0', 3);
	memset(memset2, 'A', (0));
	memset(memset3, '1', 10);
	test("memset", 
		results_to_void(3,
			ft_memset1,
			ft_memset2,
			ft_memset3), 
		results_to_void(3,
			memset1,
			memset2,
			memset3), 3);
	free(ft_memset1);
	free(ft_memset2);
	free(ft_memset3);
	free(memset1);
	free(memset2);
	free(memset3);
}

void bzero_tester()
{
	char *ft1 = calloc(5, 1);
	char *ft2 = calloc(8, 1);
	char *ft3 = calloc(10, 1);
	char *b1 = calloc(5, 1);
	char *b2 = calloc(8, 1);
	char *b3 = calloc(10, 1);
	ft_bzero(ft1, 3);
	ft_bzero(ft2, (0));
	ft_bzero(ft3, 10);
	bzero(b1, 3);
	bzero(b2, (0));
	bzero(b3, 10);
	test("bzero", 
		results_to_void(3,
			ft1,
			ft2,
			ft3), 
		results_to_void(3,
			b1,
			b2,
			b3), 3);
	free(ft1);
	free(ft2);
	free(ft3);
	free(b1);
	free(b2);
	free(b3);
}

void memcpy_tester()
{
	char *ft1 = calloc(5, 0);
	char *ft2 = calloc(8, 1);
	char *ft3 = calloc(10, 1);
	char *b1 = calloc(5, 0);
	char *b2 = calloc(8, 1);
	char *b3 = calloc(10, 1);
	ft_memcpy(ft1, "AAA", 3);
	ft_memcpy(ft2, "yo la team", 0);
	ft_memcpy(ft3, "", 10);
	memcpy(b1, "AAA", 3);
	memcpy(b2, "yo la team", 0);
	memcpy(b3, "", 10);
	test("memcpy", 
		results_to_void(3,
			ft1,
			ft2,
			ft3), 
		results_to_void(3,
			b1,
			b2,
			b3), 3);
	free(ft1);
	free(ft2);
	free(ft3);
	free(b1);
	free(b2);
	free(b3);
}

void memmove_tester()
{
	char *ft1 = calloc(5, 0);
	char *ft2 = calloc(8, 1);
	char *ft3 = calloc(10, 1);
	char *ft4 = calloc(10, 150);
	char *ft5 = NULL;
	char *b1 = calloc(5, 0);
	char *b2 = calloc(8, 1);
	char *b3 = calloc(10, 1);
	char *b4 = calloc(10, 150);
	char *b5 = NULL;
	ft_memmove(ft1, "AAA", 3);
	ft_memmove(ft2, "yo la team", 0);
	ft_memmove(ft3, "", 10);
	ft_memmove(ft4, "SALUT A TOUS COMMENT CA VA OUI :OI CA VA NICKEL", 150);
	ft_memmove(ft5, "NULL", 0);
	memmove(b1, "AAA", 3);
	memmove(b2, "yo la team", 0);
	memmove(b3, "", 10);
	memmove(b4, "SALUT A TOUS COMMENT CA VA OUI :OI CA VA NICKEL", 150);
	memmove(b5, "NULL", 0);
	test("memmove", 
		results_to_void(5,
			ft1,
			ft2,
			ft3,
			ft4,
			ft5), 
		results_to_void(5,
			b1,
			b2,
			b3,
			b4,
			b5), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
}

void strlcpy_tester()
{
	char *ft1 = calloc(5, 50);
	char *ft2 = calloc(8, 1);
	char *ft3 = calloc(10, 1);
	char *ft4 = calloc(10, 150);
	char *b1 = calloc(5, 50);
	char *b2 = calloc(8, 1);
	char *b3 = calloc(10, 1);
	char *b4 = calloc(10, 150);
	ft_strlcpy(ft1, "AAA", 3);
	ft_strlcpy(ft2, "yo la team", 0);
	ft_strlcpy(ft3, "", 10);
	ft_strlcpy(ft4, "SALUT A TOUS COMMENT CA VA OUI :OI CA VA NICKEL", 150);
	strlcpy(b1, "AAA", 3);
	strlcpy(b2, "yo la team", 0);
	strlcpy(b3, "", 10);
	strlcpy(b4, "SALUT A TOUS COMMENT CA VA OUI :OI CA VA NICKEL", 150);
	test("strlcpy", 
		results_to_void(4,
			ft1,
			ft2,
			ft3,
			ft4), 
		results_to_void(4,
			b1,
			b2,
			b3,
			b4), 4);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
}

void strlcat_tester()
{
	char *ft1 = strdup("Yoo");
	char *ft2 = calloc(8, 1);
	char *ft3 = calloc(10, 1);
	char *ft4 = calloc(1, 1);
	char *ft5 = calloc(1, 1);
	char *b1 = strdup("Yoo");
	char *b2 = calloc(8, 1);
	char *b3 = calloc(10, 1);
	char *b4 = calloc(1, 1);
	char *b5 = calloc(1, 1);
	ft_strlcat(ft1, "AAA", 3);
	ft_strlcat(ft2, "yo la team", 0);
	ft_strlcat(ft3, "", 10);
	ft_strlcat(ft4, "aaaww42", 10);
	ft_strlcat(ft5, "\0", 100);
	strlcat(b1, "AAA", 3);
	strlcat(b2, "yo la team", 0);
	strlcat(b3, "", 10);
	strlcat(b4, "aaaww42", 10);
	strlcat(b5, "\0", 100);
	test("strlcat", 
		results_to_void(5,
			ft1,
			ft2,
			ft3,
			ft4,
			ft5), 
		results_to_void(5,
			b1,
			b2,
			b3,
			b4,
			b5), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
}

void toupper_tester()
{
	char	*ft1 = memset(calloc(2, 1), 0, 2);
	char	*ft2 = memset(calloc(2, 1), 0, 2);
	char	*ft3 = memset(calloc(2, 1), 0, 2);
	char	*ft4 = memset(calloc(2, 1), 0, 2);
	char	*ft5 = memset(calloc(2, 1), 0, 2);
	char	*b1 = memset(calloc(2, 1), 0, 2);
	char	*b2 = memset(calloc(2, 1), 0, 2);
	char	*b3 = memset(calloc(2, 1), 0, 2);
	char	*b4 = memset(calloc(2, 1), 0, 2);
	char	*b5 = memset(calloc(2, 1), 0, 2);
	ft1[0] = ft_toupper('0');
	ft2[0] = ft_toupper('a');
	ft3[0] = ft_toupper('Z' + 1);
	ft4[0] = ft_toupper(6541);
	ft5[0] = ft_toupper('o');
	b1[0] = toupper('0');
	b2[0] = toupper('a');
	b3[0] = toupper('Z' + 1);
	b4[0] = toupper(6541);
	b5[0] = toupper('o');
	test("toupper", 
		results_to_void(5,
			ft1,
			ft2,
			ft3,
			ft4,
			ft5), 
		results_to_void(5,
			b1,
			b2,
			b3,
			b4,
			b5), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void tolower_tester()
{
	char	*ft1 = memset(calloc(2, 1), 0, 2);
	char	*ft2 = memset(calloc(2, 1), 0, 2);
	char	*ft3 = memset(calloc(2, 1), 0, 2);
	char	*ft4 = memset(calloc(2, 1), 0, 2);
	char	*ft5 = memset(calloc(2, 1), 0, 2);
	char	*b1 = memset(calloc(2, 1), 0, 2);
	char	*b2 = memset(calloc(2, 1), 0, 2);
	char	*b3 = memset(calloc(2, 1), 0, 2);
	char	*b4 = memset(calloc(2, 1), 0, 2);
	char	*b5 = memset(calloc(2, 1), 0, 2);
	ft1[0] = ft_tolower('0');
	ft2[0] = ft_tolower('A');
	ft3[0] = ft_tolower('Z' + 1);
	ft4[0] = ft_tolower(6541);
	ft5[0] = ft_tolower('o');
	b1[0] = tolower('0');
	b2[0] = tolower('A');
	b3[0] = tolower('Z' + 1);
	b4[0] = tolower(6541);
	b5[0] = tolower('o');
	test("tolower", 
		results_to_void(5,
			ft1,
			ft2,
			ft3,
			ft4,
			ft5), 
		results_to_void(5,
			b1,
			b2,
			b3,
			b4,
			b5), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void strchr_tester()
{
	char	*ft1 = strdup("42 42 42 42");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("");
	char	*ft4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqsdq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	char	*b1 = strdup("42 42 42 42");
	char	*b2 = strdup("WW la team");
	char	*b3 = strdup("");
	char	*b4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*b5 = strdup("cc adqsdq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("strchr", 
		results_to_void(5,
			ft_strchr(ft1, ' '),
			ft_strchr(ft2, '\0'),
			ft_strchr(ft3, 'a'),
			ft_strchr(ft4, '/'),
			ft_strchr(ft5, '.')), 
		results_to_void(5,
			strchr(b1, ' '),
			strchr(b2, '\0'),
			strchr(b3, 'a'),
			strchr(b4, '/'),
			strchr(b5, '.')), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void strrchr_tester()
{
	char	*ft1 = strdup("42 42 42 42");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("");
	char	*ft4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqsdq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	char	*b1 = strdup("42 42 42 42");
	char	*b2 = strdup("WW la team");
	char	*b3 = strdup("");
	char	*b4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*b5 = strdup("cc adqsdq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("strrchr", 
		results_to_void(5,
			ft_strrchr(ft1, ' '),
			ft_strrchr(ft2, '\0'),
			ft_strrchr(ft3, 'a'),
			ft_strrchr(ft4, '/'),
			ft_strrchr(ft5, '.')), 
		results_to_void(5,
			strrchr(b1, ' '),
			strrchr(b2, '\0'),
			strrchr(b3, 'a'),
			strrchr(b4, '/'),
			strrchr(b5, '.')), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void strncmp_tester()
{
	char	*ft1 = strdup("42 42 42 42...");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("aaaaaaaaaaaaaaaaa");
	char	*ft4 = strdup("cc a /tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	char	*b1 = strdup("42 42 42 42");
	char	*b2 = strdup("WW la team");
	char	*b3 = strdup("");
	char	*b4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*b5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("strncmp", 
		results_to_void(5,
			tostr(ft_strncmp(ft1, b1, 3)),
			tostr(ft_strncmp(ft2, b2, 9)),
			tostr(ft_strncmp(ft3, b3, 0)),
			tostr(ft_strncmp(ft4, b4, 20)),
			tostr(ft_strncmp(ft5, b5, 1))), 
		results_to_void(5,
			tostr(strncmp(ft1, b1, 3)),
			tostr(strncmp(ft2, b2, 9)),
			tostr(strncmp(ft3, b3, 0)),
			tostr(strncmp(ft4, b4, 20)),
			tostr(strncmp(ft5, b5, 1))), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void memchr_tester()
{
	char	*ft1 = strdup("42 42 42 42...");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("aaaaaaaaaaaaaaaaa");
	char	*ft4 = strdup("cc a /tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("memchr", 
		results_to_void(5,
			ft_memchr(ft1, 0, 3),
			ft_memchr(ft2, 't', 9),
			ft_memchr(ft3, 'a', 0),
			ft_memchr(ft4, '/', 20),
			ft_memchr(ft5, '.', 1)), 
		results_to_void(5,
			memchr(ft1, 0, 3),
			memchr(ft2, 't', 9),
			memchr(ft3, 'a', 0),
			memchr(ft4, '/', 20),
			memchr(ft5, '.', 1)), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
}

void memcmp_tester()
{
	char	*ft1 = strdup("42 42 42 42...");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("aaaaaaaaaaaaaaaaa");
	char	*ft4 = strdup("cc a /tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	char	*b1 = strdup("42 42 42 42");
	char	*b2 = strdup("WW la team");
	char	*b3 = strdup("");
	char	*b4 = strdup("cc a tous // / / // / // // /qsd /// // sqdd");
	char	*b5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("memcmp", 
		results_to_void(5,
			tostr(ft_memcmp(ft1, b1, 3)),
			tostr(ft_memcmp(ft2, b2, 9)),
			tostr(ft_memcmp(ft3, b3, 0)),
			tostr(ft_memcmp(ft4, b4, 20)),
			tostr(ft_memcmp(ft5, b5, 1))), 
		results_to_void(5,
			tostr(memcmp(ft1, b1, 3)),
			tostr(memcmp(ft2, b2, 9)),
			tostr(memcmp(ft3, b3, 0)),
			tostr(memcmp(ft4, b4, 20)),
			tostr(memcmp(ft5, b5, 1))), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
	free(b1);
	free(b2);
	free(b3);
	free(b4);
	free(b5);
}

void strnstr_tester()
{
	char	*ft1 = strdup("42 42 42 42...");
	char	*ft2 = strdup("WW la team");
	char	*ft3 = strdup("aaaaaaaaaaaaaaaaa");
	char	*ft4 = strdup("cc a /tous // / / // / // // /qsd /// // sqdd");
	char	*ft5 = strdup("cc adqs    dq. tousqsdqs // / / qsdsqd// / // // /qsd /// // sqdd");
	test("strnstr", 
		results_to_void(5,
			ft_strnstr(ft1, "NULL", 3),
			ft_strnstr(ft2, " l", 9),
			ft_strnstr(ft3, "\0", 0),
			ft_strnstr(ft4, "/q", 20),
			ft_strnstr(ft5, ". ", 1)), 
		results_to_void(5,
			strnstr(ft1, "NULL", 3),
			strnstr(ft2, " l", 9),
			strnstr(ft3, "\0", 0),
			strnstr(ft4, "/q", 20),
			strnstr(ft5, ". ", 1)), 5);
	free(ft1);
	free(ft2);
	free(ft3);
	free(ft4);
	free(ft5);
}

void atoi_tester()
{
	test("atoi", 
		results_to_void(7,
			tostr(ft_atoi("     +6541")),
			tostr(ft_atoi("    ")),
			tostr(ft_atoi("")),
			tostr(ft_atoi("-659")),
			tostr(ft_atoi("+--+-\n654")),
			tostr(ft_atoi("  +-15")),
			tostr(ft_atoi("548"))), 
		results_to_void(7,
			tostr(atoi("     +6541")),
			tostr(atoi("    ")),
			tostr(atoi("")),
			tostr(atoi("-659")),
			tostr(atoi("+--+-\n654")),
			tostr(atoi("  +-14")),
			tostr(atoi("548"))), 7);
}

int main()
{
	printf("\e[1;1H\e[2J");
	printf("\n\n\n\n    > \e[2;32m Libft tester by jazema. \e[0mv0.1 <\n\n\n\n\n");
	setTimeout(1000);
	printf("\e[0;31m$> \e[0mWill test mandatory part\n");
	setTimeout(1200);
	printf("\n\n\e[0;31m$> \e[4;31m/!\\\e[0m Some tests may appear KO while being OK. Please double-check. \e[4;31m/!\\\e[0m\n");
	setTimeout(3000);
	printf("\n\n");
	test("is_alpha", 
		results_to_void(6,
			tostr(ft_isalpha('A') > 0),
			tostr(ft_isalpha('b') > 0),
			tostr(ft_isalpha('\0') > 0),
			tostr(ft_isalpha('9') > 0),
			tostr(ft_isalpha('e') > 0),
			tostr(ft_isalpha('.') > 0)),
		results_to_void(6,
			tostr(isalpha('A') > 0),
			tostr(isalpha('b') > 0),
			tostr(isalpha('\0') > 0),
			tostr(isalpha('9') > 0),
			tostr(isalpha('e') > 0),
			tostr(isalpha('.') > 0)), 6);
	setTimeout(500);
	test("is_digit", 
		results_to_void(5,
			tostr(ft_isdigit('A') > 0),
			tostr(ft_isdigit('b') > 0),
			tostr(ft_isdigit('\0') > 0),
			tostr(ft_isdigit('9') > 0),
			tostr(ft_isdigit('.') > 0)),
		results_to_void(5,
			tostr(isdigit('A') > 0),
			tostr(isdigit('b') > 0),
			tostr(isdigit('\0') > 0),
			tostr(isdigit('9') > 0),
			tostr(isdigit('.') > 0)), 5);
	setTimeout(500);
	test("is_alnum", 
		results_to_void(5,
			tostr(ft_isalnum('A') > 0),
			tostr(ft_isalnum('b') > 0),
			tostr(ft_isalnum('\0') > 0),
			tostr(ft_isalnum('9') > 0),
			tostr(ft_isalnum('.') > 0)),
		results_to_void(5,
			tostr(isalnum('A') > 0),
			tostr(isalnum('b') > 0),
			tostr(isalnum('\0') > 0),
			tostr(isalnum('9') > 0),
			tostr(isalnum('.') > 0)), 5);
	setTimeout(500);
	test("is_ascii", 
		results_to_void(7,
			tostr(ft_isascii('A') > 0),
			tostr(ft_isascii('b') > 0),
			tostr(ft_isascii('\0') > 0),
			tostr(ft_isascii('9') > 0),
			tostr(ft_isascii(129) > 0),
			tostr(ft_isascii(31) > 0),
			tostr(ft_isascii('.') > 0)),
		results_to_void(7,
			tostr(isascii('A') > 0),
			tostr(isascii('b') > 0),
			tostr(isascii('\0') > 0),
			tostr(isascii('9') > 0),
			tostr(isascii(129) > 0),
			tostr(isascii(31) > 0),
			tostr(isascii('.') > 0)), 7);
	setTimeout(500);
	test("is_print", 
		results_to_void(8,
			tostr(ft_isprint('A') > 0),
			tostr(ft_isprint('b') > 0),
			tostr(ft_isprint('\0') > 0),
			tostr(ft_isprint('9') > 0),
			tostr(ft_isprint(129) > 0),
			tostr(ft_isprint(31) > 0),
			tostr(ft_isprint(32) > 0),
			tostr(ft_isprint('.') > 0)),
		results_to_void(8,
			tostr(isprint('A') > 0),
			tostr(isprint('b') > 0),
			tostr(isprint('\0') > 0),
			tostr(isprint('9') > 0),
			tostr(isprint(129) > 0),
			tostr(isprint(31) > 0),
			tostr(isprint(32) > 0),
			tostr(isprint('.') > 0)), 8);
	setTimeout(500);
	test("strlen", 
		results_to_void(5,
			tostr(ft_strlen("42")),
			tostr(ft_strlen("WW la \0team")),
			tostr(ft_strlen("")),
			tostr(ft_strlen("NULL")),
			tostr(ft_strlen("."))),
		results_to_void(5,
			tostr(strlen("42")),
			tostr(strlen("WW la \0team")),
			tostr(strlen("")),
			tostr(strlen("NULL")),
			tostr(strlen("."))), 5);
	setTimeout(500);
	memset_tester();
	setTimeout(500);
	bzero_tester();
	setTimeout(500);
	memcpy_tester();
	setTimeout(500);
	memmove_tester();
	setTimeout(500);
	strlcpy_tester();
	setTimeout(500);
	strlcat_tester();
	setTimeout(500);
	toupper_tester();
	setTimeout(500);
	tolower_tester();
	setTimeout(500);
	strchr_tester();
	setTimeout(500);
	strrchr_tester();
	setTimeout(500);
	strncmp_tester();
	setTimeout(500);
	memchr_tester();
	setTimeout(500);
	memcmp_tester();
	setTimeout(500);
	strnstr_tester();
	setTimeout(500);
	atoi_tester();
	setTimeout(100);
	end_tester();
	return 0;
}
