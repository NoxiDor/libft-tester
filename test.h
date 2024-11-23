/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazema <jazema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:34:54 by jazema            #+#    #+#             */
/*   Updated: 2024/11/09 22:34:56 by jazema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void start_test(char *test_name);
void end_test(char *test_name, int validated, int failed);
int test(char *test_name, char **v1, char **v2, int count);
void end_tester(void);
void setTimeout(int milliseconds);