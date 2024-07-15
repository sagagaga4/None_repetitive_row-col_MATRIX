#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 4

int perfectmat(int** mat)
{
    for (int i = 0; i < M; i++)
    {
        mat[i] = malloc(sizeof(int) * N);
        if (mat[i] == NULL)
        {
            printf("COL ALLOCATION FAILED\n");
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            return -1;
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("ENTER A NUMBER MAT[%d][%d]: ", i , j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if((j < N-1 && mat[i][j] == mat[i][j+1]) || (i < M-1 && mat[i][j] == mat[i+1][j]))
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    return 1;
}
