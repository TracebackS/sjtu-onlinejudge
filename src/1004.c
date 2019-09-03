//
// Created by traceback on 9/3/19.
//

#include <stdio.h>

int main()
{
	int m, t, u, f, d;
	scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);
	int ans = 0;
	int current_time = 0;
	int ud = u + d;
	int ff = f + f;
	char tmp;
	int i;
	for (i = 0; i < t; i++)
	{
		scanf(" %c", &tmp);
		switch (tmp)
		{
		case 'u':
			current_time += ud;
			break;
		case 'f':
			current_time += ff;
			break;
		case 'd':
			current_time += ud;
			break;
		default:
			break;
		}
		if (current_time <= m)
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}