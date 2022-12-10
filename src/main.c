#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vec2
{
	int x;
	int y;
} vec2;

typedef struct cam
{
	int xRange;
	int yRange;
	struct vec2 pos;
} cam;

vec2 *camPos;
vec2 *world;

cam *camera;

int render()
{
	for(int i = (camera->pos.y) - world->y; i < (world->y + camera->pos.y); i++)
	{
		for(int j = (camera->pos.x) - world->x; j < world->x; j++)
		{
			if(j == 0 && i == 0)
			{
				printf("#");
			}
			else if(-i == round((j*j)-(2*j)+3))
			{
				printf("*");
			}
			else if(j == 0)
			{
				printf("|");
			}
			else if(i == 0)
			{
				printf("-");
			}else
			{
				printf(" ");
			}

		}
		printf("\n");
	}
	return 0;
}

int main()
{
	camPos = malloc(sizeof(vec2));
	camPos->x = 0;	// No current use
	camPos->y = 0;	// No current use

	world = malloc(sizeof(vec2));
	world->x = 60;
	world->y = 30;

	camera = malloc(sizeof(cam));
	camera->xRange = 60;	// No current use
	camera->yRange = 30;	// No current use

	vec2 *p = malloc(sizeof(vec2));
	p->x = 0;	// Adjusts camera position on the X axis
	p->y = -30;	// Adjusts camera position on the Y axis
	camera->pos = *p;

	render();

	return 0;
}
