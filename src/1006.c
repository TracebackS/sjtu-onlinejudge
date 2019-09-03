//
// Created by traceback on 9/3/19.
//

#include <stdio.h>
#include <stdlib.h>

int find_max(int *data, int n);
int find_min(int *data, int n);

int main()
{
	int n;
	scanf("%d", &n);
	int *sum_from_head = (int *)malloc(n * sizeof(int));
	int sum = 0;
	int tmp;
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		sum += tmp;
		sum_from_head[i] = sum;
	}
	int max_distance = 0;
	int split_point = 0;

	while (split_point < n - 1)
	{
		int pos_max = find_max(sum_from_head + split_point, n - split_point);
		if (pos_max != 0)
		{
			int pos_min = find_min(sum_from_head + split_point, pos_max);
			if (sum_from_head[pos_max + split_point] - sum_from_head[pos_min + split_point] > max_distance)
			{
				max_distance = sum_from_head[pos_max + split_point] - sum_from_head[pos_min + split_point];
			}
		}
		split_point += pos_max + 1;
	}
	if (max_distance > 0)
	{
		printf("%d\n", max_distance);
	}
	else
	{
		printf("Game Over\n");
	}
	return 0;
}

int find_max(int *data, int n)
{
	int max = data[0];
	int r = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
			r = i;
		}
	}
	return r;
}

int find_min(int *data, int n)
{
	int min = data[0];
	int r = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
			r = i;
		}
	}
	return r;
}
