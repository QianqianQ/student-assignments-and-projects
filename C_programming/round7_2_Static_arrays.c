#include <stdio.h>

int main(void)
{
    int taulu[6][6];
    for(int x=0;x<6;x++)
    {
        for(int y=0;y<6;y++)
            taulu[x][y]=x*y;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", taulu[j][i]);
        }
        printf("\n");
    }
}
