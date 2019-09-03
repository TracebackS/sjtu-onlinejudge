//
// Created by traceback on 9/3/19.
//

#include <stdio.h>
#include <stdlib.h>

int chk_sudoku_valid(int *sudoku);
int chk_line_valid(int *line);

int main()
{
	int n;
	scanf("%d", &n);
	int *data = (int *)malloc(n * 81 * sizeof(int));
	int i;
	for (i = 0; i < 81 * n; i++)
	{
		scanf("%d", data + i);
	}
	int *sudoku = data;
	while (n)
	{
		int r = chk_sudoku_valid(sudoku);
		if (r)
		{
			printf("Right\n");
		}
		else
		{
			printf("Wrong\n");
		}
		n--;
		sudoku += 81;
	}
	return 0;
}

int chk_sudoku_valid(int *sudoku)
{
	int line[9];
	int r;
	int i;
	for (i = 0; i < 9; i++)
	{
		int line_base = i * 9;
		line[0] = sudoku[line_base];
		line[1] = sudoku[line_base + 1];
		line[2] = sudoku[line_base + 2];
		line[3] = sudoku[line_base + 3];
		line[4] = sudoku[line_base + 4];
		line[5] = sudoku[line_base + 5];
		line[6] = sudoku[line_base + 6];
		line[7] = sudoku[line_base + 7];
		line[8] = sudoku[line_base + 8];
		r = chk_line_valid(line);
		if (!r)
		{
			return 0;
		}
	}
	for (i = 0; i < 9; i++)
	{
		line[0] = sudoku[i];
		line[1] = sudoku[i + 9];
		line[2] = sudoku[i + 18];
		line[3] = sudoku[i + 27];
		line[4] = sudoku[i + 36];
		line[5] = sudoku[i + 45];
		line[6] = sudoku[i + 54];
		line[7] = sudoku[i + 63];
		line[8] = sudoku[i + 72];
		r = chk_line_valid(line);
		if (!r)
		{
			return 0;
		}
	}
	for (i = 0; i < 9; i++)
	{
		int line_base = (i / 3) * 27 + (i % 3) * 3;
		line[0] = sudoku[line_base];
		line[1] = sudoku[line_base + 1];
		line[2] = sudoku[line_base + 2];
		line[3] = sudoku[line_base + 9];
		line[4] = sudoku[line_base + 10];
		line[5] = sudoku[line_base + 11];
		line[6] = sudoku[line_base + 18];
		line[7] = sudoku[line_base + 19];
		line[8] = sudoku[line_base + 20];
		r = chk_line_valid(line);
		if (!r)
		{
			return 0;
		}
	}
	return 1;
}

int chk_line_valid(int *line)
{
	unsigned int mask = 0x1ff;
	int i;
	for (i = 0; i < 9; i++)
	{
		mask &= ~(0x1u << (line[i] - 1u));
	}
	return !mask;
}