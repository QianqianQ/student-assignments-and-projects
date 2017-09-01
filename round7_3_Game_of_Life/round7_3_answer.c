#include <stdio.h>
#include <stdlib.h>
#include "aaltogame.h"

Area *createArea(unsigned int xsize, unsigned int ysize)
{
    unsigned int i, j;
    Area *a = malloc(sizeof(Area));
    if (!a)
        return NULL;

    a->cells = malloc(sizeof(Status*) * ysize);
    if (!a->cells)
    {
        free(a);
        return NULL;
    }

    for (i = 0; i < ysize; i++)
    {
        a->cells[i] = malloc(sizeof(Status) * xsize);
        if (!a->cells[i])
        {
            for (j = 0; j < i; j++)
                free(a->cells[j]);
            free(a->cells);
            free(a);
            return NULL;
        }
        for (j = 0; j < xsize; j++)
        {
            a->cells[i][j] = DEAD;
        }
    }
    a->xsize = xsize;
    a->ysize = ysize;
    return a;
}

void releaseArea(Area *a)
{
    for (unsigned int i = 0; i < a->ysize; i++)
    {
        free(a->cells[i]);
    }
    free(a->cells);
    free(a);
}

void initArea(Area *a, unsigned int n)
{
    while(n)
    {
        // pick random locations within game area bounds
        unsigned int x = rand() % a->xsize;
        unsigned int y = rand() % a->ysize;
        if (a->cells[y][x] == DEAD)
        {
            a->cells[y][x] = ALIVE;
            n--;
        }
    }
}

void printArea(const Area *a)
{
    for (unsigned int y = 0; y < a->ysize; y++)
    {
        for (unsigned int x = 0; x < a->xsize; x++)
        {
            int c;
            if (a->cells[y][x] == DEAD)
                c = '.';
            else if (a->cells[y][x] == ALIVE)
                c = '*';
            else
                c = '?';
            fputc(c, stdout);
        }
        fputc('\n', stdout);
    }
}

unsigned int live_neighbours(const Area *a, unsigned int x, unsigned int y)
{
    unsigned int alive = 0;
    for (int yd = -1; yd <= 1; yd++)
    {
        for (int xd = -1; xd <= 1; xd++)
        {
	    // Do not calculate the location itself
            if (xd == 0 && yd == 0)
                continue;
            // Check that we do not access out of bounds
            if ((int)x + xd < 0 || (int)x + xd >= (int)a->xsize ||
                    (int)y + yd < 0 || (int)y + yd >= (int)a->ysize) {
                continue;
            }
            if (a->cells[y + yd][x + xd] == ALIVE)
                alive++;
        }
    }
    return alive;
}

void tick(Area *a)
{
    // Create a new gameArea where the next generation is written
    Status **newcells = malloc(sizeof(Status*) * a->ysize);
    if (!newcells)
    {
        return;
    }
    for (unsigned int i = 0; i < a->ysize; i++)
    {
        newcells[i] = malloc(sizeof(Status) * a->xsize);
        if (!newcells[i])
        {
            for (unsigned int j = 0; j < i; j++)
                free(newcells[j]);
            free(newcells);
            return;
        }
    }
    for (unsigned int y = 0; y < a->ysize; y++)
    {
        for (unsigned int x = 0; x < a->xsize; x++)
        {
            unsigned int nc = live_neighbours(a, x, y);
            newcells[y][x] = a->cells[y][x];
            if (a->cells[y][x] == ALIVE)
            {
                if (nc < 2)
                    newcells[y][x] = DEAD;
                else if (nc == 2 || nc == 3)
                    newcells[y][x] = ALIVE;
                else
                    newcells[y][x] = DEAD;
            } else {
                if (nc == 3)
                    newcells[y][x] = ALIVE;
            }
        }
    }
    // release the gameArea of previous generation
    for (unsigned int y = 0; y < a->ysize; y++)
    {
        free(a->cells[y]);
    }
    free(a->cells);
    // The newly allocated gameArea becomes the "main" gameArea
    a->cells = newcells;
}
