//
// Created by traceback on 9/3/19.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int l;
	scanf("%d", &l);
	int *data = (int *)malloc(l * l * sizeof(int));
	int i, j;
	for (i = 0; i < l * l; i++)
	{
		scanf("%d", data + i);
	}
	int m = 0;
	int finish = 0;
	while (!finish)
	{
		finish = 1;
		for (i = 0; i < l; i++)
		{
			for (j = 0; j < l; j++)
			{
				if (data[i * l + j] == 0)
				{
					if ((i != 0 && data[(i - 1) * l + j] == 1) || (i != l - 1 && data[(i + 1) * l + j] == 1) ||
						(j != 0 && data[i * l + j - 1] == 1) || (j != l - 1 && data[i * l + j + 1] == 1))
					{
						data[i * l + j] = 3;
					}
					else
					{
						finish = 0;
					}
				}
			}
		}
		for (i = 0; i < l * l; i++)
		{
			data[i] = data[i] == 3 ? 1 : data[i];
		}
		m++;
	}
	printf("%d\n", m);
	return 0;
}