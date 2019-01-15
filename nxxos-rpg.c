#include <stdio.h>

#define MAP_MAX 2000000

enum
{
	KEY_UP = 256 + 72,
	KEY_DOWN = 256 + 80,
	KEY_LEFT = 256 + 75,
	KEY_RIGHT = 256 + 77,
	KEY_ESC = 27,
	KEY_ENTER = 13,
	KEY_BACKSPACE = 8,
	KEY_B = 98,
	KEY_C = 99
};

int map[MAP_MAX][MAP_MAX];

int getmap()
{
	FILE *fp;
	fp = fopen("map.txt", "r");
	
	int temp1, temp2;
	
	if (!fp)
	{
		return 1;
	}
	
	for (temp1 = 0; temp1 < MAP_MAX; temp1++)
	{
	    for (temp2 = 0; temp2 < MAP_MAX; temp2++)
	    {
	        fscanf(fp, "%c", &map[temp1][temp2]);
			 if (map[temp1][temp2] == '\n')
			{
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				break;
			}
	    }
		if (map[temp1][temp2] == '\0')
		{
			break;
		}
	}

	//todo: check map size is at least 5x5 and has a starting "o" spot
	
	return 0;
}

int printmap()
{
	int temp1, temp2;
	printf("\n");
	for (temp1 = 0; temp1 < MAP_MAX; temp1++)
	{
		for (temp2 = 0; temp2 < MAP_MAX; temp2++)
		{
			printf("%c", map[temp1][temp2]);
			if (map[temp1][temp2] == '\n')
			{
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				break;
			}
	    }
		if (map[temp1][temp2] == '\0')
		{
			break;
		}
	}
	printf("\n");
}

int scanmapforstartx()
{
	int temp1, temp2; 
	for (temp1 = 0; temp1 < MAP_MAX; temp1++)
	{
		for (temp2 = 0; temp2 < MAP_MAX; temp2++)
	    {
			if (map[temp1][temp2] == '\n')
			{
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				break;
			}
			else if (map[temp1][temp2] == 'o')
			{
				return temp2;
			}
	    }
		if (map[temp1][temp2] == '\0')
		{
			break;
		}
	}
	return -1;
}

int scanmapforstarty()
{
	int temp1, temp2; 
	for (temp1 = 0; temp1 < MAP_MAX; temp1++)
	{
		for (temp2 = 0; temp2 < MAP_MAX; temp2++)
	    {
			if (map[temp1][temp2] == '\n')
			{
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				break;
			}
			else if (map[temp1][temp2] == 'o')
			{
				return temp1;
			}
	    }
		if (map[temp1][temp2] == '\0')
		{
			break;
		}
	}
	return -1;
}

int drawmap(int x, int y)
{
	int temp1, temp2;
	
	printf("\n");
	for (temp1 = y - 2; temp1 < y + 3; temp1++)
	{
		for (temp2 = x - 2; temp2 < x + 3 ; temp2++)
		{
			if (temp1 == y && temp2 == x)
			{
				printf("P");
			}
			else
			{
				printf("%c", map[temp1][temp2]);
			}
			if (map[temp1][temp2 + 1] == '\n')
			{
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				return -1;
			}
	    }
		printf("\n");
		if (map[temp1][temp2] == '\0')
		{
			return -1;
		}
	}

	printf("\n");
	return 0;
}

int getkey()
{
	int key = getch();

	if (key == 0 || key == 224)
	{
		key = 256 + getch();
	}
	
	return key;
}


int main()
{
	getmap();
	
	int playerx = scanmapforstartx();
	int playery = scanmapforstarty();
	int key;
	
	for (;;)
	{
		drawmap(playerx, playery);
		key = getkey();
		if (key == KEY_UP && map[playery - 1][playerx] != 'x')
		{
			playery--;
		}
		else if (key == KEY_DOWN && map[playery + 1][playerx] != 'x')
		{
			playery++;
		}
		else if (key == KEY_LEFT && map[playery][playerx - 1] != 'x')
		{
			playerx--;
		}
		else if (key == KEY_RIGHT && map[playery][playerx + 1] != 'x')
		{
			playerx++;
		}
	}
	printmap();
	return 0;
}

/*
int main()
{
	FILE *fp;
	fp = fopen("map.txt", "r");
	if (fp == NULL)
	{
		return 1;
	}

	fscanf(fp, "%c", &map[0][0]);
	printf("%c", map[0][0]);
	fscanf(fp, "%c", &map[0][1]);
	printf("%c", map[0][1]);
	return 0;
}
*/

/*
int main()
{
	int c;
	getmap();
	for (;;)
	{
		c = getkey();
		if (c > 256)
		{
			printf("256+%d\n", (c - 256));
		}
		else
		{
			printf("%d\n", c);
		}
		printmap();
	}
	return 0;
}
*/
