//
// Created by traceback on 9/3/19.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int l, w;
	scanf("%d %d", &l, &w);
	int *data = (int *)malloc(l * w * sizeof(int));
	int i, j, k;
	for (i = 0; i < l * w; i++)
	{
		scanf("%d", data + i);
	}
	int a, b;
	scanf("%d %d", &a, &b);
	int m = 0;
	int tmp;
	int *l_pre_sum = (int *)malloc((l - a + 1) * w * sizeof(int));
	for (j = 0; j < w; j++)
	{
		tmp = 0;
		for (k = 0; k < a; k++)
		{
			tmp += data[k * w + j];
		}
		for (i = 0; i < l - a + 1; i++)
		{
			l_pre_sum[i * w + j] = tmp;
			if (i != l - a)
			{
				tmp -= data[i * w + j];
				tmp += data[(i + a) * w + j];
			}
		}
	}
	for (i = 0; i < l - a + 1; i++)
	{
		tmp = 0;
		for (k = 0; k < b; k++)
		{
			tmp += l_pre_sum[i * w + k];
		}
		for (j = 0; j < w - b + 1; j++)
		{
			if (tmp > m)
			{
				m = tmp;
			}
			if (j != w - b)
			{
				tmp -= l_pre_sum[i * w + j];
				tmp += l_pre_sum[i * w + j + b];
			}
		}
	}
	printf("%d\n", m);
	return 0;
}
