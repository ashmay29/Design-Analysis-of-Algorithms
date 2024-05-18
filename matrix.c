#include <stdio.h>
#include <limits.h>

int MatrixChainMult(int* dim, int i, int j)
{
    int minCost = INT_MAX;
    int cost, k;
    if (i == j)
        return 0;
    else
    {
        for (k = i; k < j; k++)
        {
            cost = MatrixChainMult(dim, i, k) + MatrixChainMult(dim, k + 1, j) + dim[i - 1] * dim[k] * dim[j];
            if (cost < minCost)
            {
                minCost = cost;
            }
        }
        return minCost;
    }
}

int main()
{
    int i, j;
    int dim[] = {5, 4, 6, 2, 7};
    int n = sizeof(dim) / sizeof(dim[0]) - 1;
    int d[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {
                d[i][j] = MatrixChainMult(dim, i + 1, j + 1);
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (j < i)
                printf("\t");
            else
                printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    printf("Minimum number of ways of multiplying: %d\n", d[0][n - 1]);
    return 0;
}
