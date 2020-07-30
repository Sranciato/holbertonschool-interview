#include "menger.h"
#include <math.h>
/**
 * menger - Function that draws a 2d menger sponge
 * @level: the level of the menger sponge
 */
void menger(int level)
{
	int power, i, j, x, y;
	char hash = '#';

	power = pow(3, level);

	for (i = 0; i < power; i++)
	{
		for (j = 0; j < power; j++)
		{
			x = i;
			y = j;
			hash = '#';
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					hash = ' ';
				x = x / 3;
				y = y / 3;
			}
			printf("%c", hash);
		}
		printf("\n");
	}
}
