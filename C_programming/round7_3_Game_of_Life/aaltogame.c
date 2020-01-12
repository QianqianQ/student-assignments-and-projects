#include"aaltogame.h"
#include<stdlib.h>
#include<stdio.h>
Area *createArea(unsigned int xsize, unsigned int ysize)
{
    Area *create=malloc(sizeof(Area));
    create->xsize=xsize;
    create->ysize=ysize;
    create->cells=malloc(ysize*sizeof(int*));
    if(!create->cells)
        return NULL;
    for(int j=0;j<ysize;j++)
    {
        create->cells[j]=malloc(xsize*sizeof(int));
        if(!create->cells[j])
        {
            for(int i=0;i<j;i++)
            {
                free(create->cells[i]);
            }
            free(create->cells);
            return NULL;
        }
        for(int i=0;i<xsize;i++)
        {
            create->cells[j][i]=DEAD;
        }
    }
    return create;
}
void releaseArea(Area *a)
{
    for(int i=0;i<(a->ysize);i++)
    {
        free(a->cells[i]);
    }
    free(a->cells);
    free(a);
}
void initArea(Area *a, unsigned int n)
{
    int i=0;
    while(i!=n)
    {
        int randy=rand()%(a->ysize);
        int randx=rand()%(a->xsize);
        if(a->cells[randy][randx]==ALIVE)
        {
            continue;
        }
        else
        {
            a->cells[randy][randx]=ALIVE;
            i++;
        }
    }


}
void printArea(const Area *a)
{
    int t=0;
    for(int y=0;y<a->ysize;y++)
        for(int x=0;x<a->xsize;x++)
    {
        if(a->cells[y][x]==ALIVE)
        {
             printf("*");
             t++;
        }

        if(a->cells[y][x]==DEAD)
        {
            printf(".");
            t++;
        }

        if(t==(a->xsize))
        {
             printf("\n");
             t=0;
        }


    }
}

void tick(Area *a)
{
   Area *next=malloc(sizeof(Area));
   next->xsize=a->xsize;
   next->ysize=a->ysize;
   next->cells=malloc((next->ysize)*sizeof(int*));
   for(int i=0;i<next->ysize;i++)
   {
       next->cells[i]=malloc((next->xsize)*sizeof(int));
   }
    for(int y=0;y<a->ysize;y++)
    for(int x=0;x<a->xsize;x++)
    {
        int num=0;
        if(y==0)
        {
            if(x==0)
            {
                for(int j=0;j<=1;j++)
                    for(int k=0;k<=1;k++)
                {
                    if(j||k)
                    if(a->cells[y+j][x+k]==ALIVE)
                        num++;
                }
            }

           else if(x==(a->xsize-1))
            {
                for(int j=0;j<=1;j++)
                    for(int k=-1;k<=0;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }
            }
            else
            {
                for(int j=0;j<=1;j++)
                    for(int k=-1;k<=1;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }
            }
        }
        else if(y==(a->ysize-1))
        {
            if(x==0)
            {
                for(int j=-1;j<=0;j++)
                    for(int k=0;k<=1;k++)
                {
                    if(j||k)
                    if(a->cells[y+j][x+k]==ALIVE)
                        num++;
                }
            }
            else if(x==(a->xsize-1))
            {
                for(int j=-1;j<=0;j++)
                    for(int k=-1;k<=0;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }
            }
            else
            {
                for(int j=-1;j<=0;j++)
                    for(int k=-1;k<=1;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }
            }
        }
        else if(x==0 &&((y!=0)||(y!=(a->ysize-1))))
        {
                for(int j=-1;j<=1;j++)
                    for(int k=0;k<=1;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }
        }
        else if(x==(a->xsize-1) && ((y!=0)||(y!=(a->ysize-1))))
        {
               for(int j=-1;j<=1;j++)
                    for(int k=-1;k<=0;k++)
                {
                    if(j||k)
                        if(a->cells[y+j][x+k]==ALIVE)
                            num++;
                }

        }
        else
        {
            for(int j=-1;j<=1;j++)
                for(int k=-1;k<=1;k++)
            {
                if(j||k)
                if(a->cells[y+j][x+k]==ALIVE)
                    num++;
            }
        }
        if(a->cells[y][x]==DEAD)
        {
            if(num==3)
                next->cells[y][x]=ALIVE;
            else
                next->cells[y][x]=DEAD;
        }
        else
        {
            if(num>3)
                next->cells[y][x]=DEAD;
            else if(num<2)
                next->cells[y][x]=DEAD;
            else
            {
                next->cells[y][x]=ALIVE;
            }
        }
    }

    for(int p=0;p<a->ysize;p++)
        for(int q=0;q<a->xsize;q++)
    {
        a->cells[p][q]=next->cells[p][q];
    }
    releaseArea(next);



}
