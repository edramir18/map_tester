/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:09:27 by edramire          #+#    #+#             */
/*   Updated: 2020/03/12 01:51:32 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 7
#define COLUMNS 5

int		check_map(char map[ROWS][COLUMNS + 1], int row, int col)
{
	char	c;
	int		ok;

	c = map[row][col];
	if (row < 0 || col < 0 || row >= ROWS || col >= COLUMNS)
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col -1);
	ok = ok == 0 ? check_map(map, row, col + 1) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col) : ok;
	return (ok);
}


int		main(void)
{
	char map[ROWS][COLUMNS + 1] = {
		"11100",
		"10100",
		"12111",
		"101 1",
		"10011",
		"10E01",
		"11111"
		};
	int row;
	int col;
	int ok;

	row = -1;
	while (++row < 7)
	{
		col = -1;
		while (++col < 5)
		{
			if (strchr("NESW", map[row][col]) != NULL)
			{
				map[row][col] = '0';
				ok = check_map(map, row, col);
				printf("%d\n", ok);
				exit(0);
			}
		}
	}
}