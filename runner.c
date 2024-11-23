/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazema <jazema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:32:08 by jazema            #+#    #+#             */
/*   Updated: 2024/11/09 22:34:49 by jazema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <time.h>

static int psd = 0;
static int fld = 0;

void start_test(char *test_name)
{
	printf("\e[1;34mStarting test on \e[0m'%s' \e[1;34m:\n", test_name);
}
void end_test(char *test_name, int validated, int failed)
{
	printf("\e[1;33mTest ended | Passed \e[1;32m%i \e[1;33mtests </\\> Failed \e[0;31m%i\e[0m.", validated, failed);
	printf("  %s\e[0m\n\n", failed == 0 ? "\e[1;32mSUCCESS" : "\e[0;31mKO");
}

void test_passed(int test_number)
{
	printf("\e[1;32m    ->  Test %i OK.\e[0m\n", test_number);
}

void test_failed(int test_number, char *v1, char *v2)
{
	printf("\e[1;31m    ->  Test %i KO.\e[0m (Expected \e[1;32m%s\e[0m but got \e[1;31m%s\e[0m)\n", test_number, (char *) v2, (char *) v1);
}

int test(char *test_name, char **v1, char **v2, int count)
{
	int i = 0;
	int passed = 0;
	int failed = 0;

	start_test(test_name);
	while (i < count)
	{
		if ((v1[i] == NULL && v2[i] == NULL) || 
			(strcmp(v1[i], v2[i]) == 0))
		{
			test_passed(i);
			passed++;
		}
		else
		{
			test_failed(i, v1[i], v2[i]);
			failed++;
		}
		i++;
	}
	end_test(test_name, passed, failed);
	psd += passed;
	fld += failed;
	return (passed);
}

void end_tester(void)
{
	printf("\n\e[9m                                           \e[29m\n\n\e[35m   Libft tested! Tests passed: \e[1;32m%i\e[1;33m/%i.\e[0m\n   ->  \e[1;35mFinal Result : \e[36m%.2f%% %s\e[0m\n\n\e[9m                                           \e[29m\n\n\n", psd, psd + fld, (double) ((double) psd / (psd + fld)) * 100.0, fld == 0 ? "\e[1;32m(SUCCESS)" : "\e[0;31m(FAILED)");
}

void setTimeout(int milliseconds)
{
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    int end = milliseconds_since + milliseconds;

    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}