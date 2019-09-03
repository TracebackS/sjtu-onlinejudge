//
// Created by traceback on 9/3/19.
//

#include <stdio.h>

int main()
{
	int h_brother, h_chair, h_brother_on_chair, h_apple, n, m, i;
	scanf("%d %d %d", &h_brother, &h_chair, &n);
	m = 0;
	h_brother_on_chair = h_brother + h_chair;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h_apple);
		if (h_brother_on_chair >= h_apple)
		{
			m++;
		}
	}
	printf("%d\n", m);
	return 0;
}
