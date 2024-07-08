#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    float num[N][N];
    float c=0, v=1, p=0, s=0;
    int i,f;

    srand(time(NULL));

    for(i=0; i<N; i++)
    {
        printf("\n");
        for(f=0; f<N; f++)
        {
            num[i][f]= 0.01 * (rand()%101);
            printf(" %1.2f",num[i][f]);
            if (num[i][f]>c)
                c=num[i][f];

            if (num[i][f]<v)
                v=num[i][f];

            if (i==f)
                p=p+num[i][f];

            if ((i+f)==(N-1))
                s=s+num[i][f];
        }
    }

    printf("\n\nMayor numero: %1.2f\nMenor numero: %1.2f",c,v);
    p=p/N;
    printf("\n\nPromedio de la diagonal principal: %1.2f\nSumatoria de la diagonal secundaria: %1.2f",p,s);
    return 0;
}
