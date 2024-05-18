#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char X[], char Y[], int m, int n)
{
    int dp[m + 1][n + 1];

    // Build the dp table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Length of LCS is dp[m][n]
    return dp[m][n];
}

int main()
{
    char X[MAX_LEN], Y[MAX_LEN];

    printf("Enter string X: ");
    scanf("%s", X);

    printf("Enter string Y: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs(X, Y, m, n);

    printf("Length of Longest Common Subsequence: %d\n", length);

    return 0;
}
