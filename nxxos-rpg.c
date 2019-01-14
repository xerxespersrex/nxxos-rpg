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
	    for (temp2 = 0; temp2 < MAP_MAX && map[temp1][temp2] != '\0'; temp2++)
	    {
	        fscanf(fp, "%c", &map[temp1][temp2]);
			if (map[temp1][temp2] == '\n')
			{
				map[temp1][temp2] = 0;
				break;
			}
			else if (map[temp1][temp2] == '\0')
			{
				break;
			}
	    }
	}
	
	//todo: check map size is at least 5x5 and has a starting "o" spot
	
	return 0;
}

int printmap()
{
	int temp1, temp2;
	for (temp1 = 0; temp1 < MAP_MAX; temp1++)
	{
	    for (temp2 = 0; temp2 < MAP_MAX && map[temp1][temp2] != '0' 
			&& map[temp1][temp2] != '\0'; temp2++)
	    {
	        printf("%c", map[temp1][temp2]);
	    }
		if (map[temp1][temp2] == '\0')
		{
			break;
		}
	}
}

int getkey()
{
  int key = getch();

  if ( key == 0 || key == 224 )
    key = 256 + getch();

  return key;
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
