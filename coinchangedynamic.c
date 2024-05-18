#include <stdio.h>
#define N 11

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int denom[], int n, int amount) {
    int dp[n][N + 1];

    // Initialize dp array
    for (int j = 0; j <= N; j++) {
        dp[0][j] = j; // Using only the first denomination (denom[0])
    }

    // Populate dp array using dynamic programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= N; j++) {
            if (j < denom[i]) {
                dp[i][j] = dp[i - 1][j]; // Cannot use current denomination
            } else {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - denom[i]]); // Choose minimum coins
            }
        }
    }

    // Print the actual denominations used
    printf("The actual denominations of coins required are = ");
    int j = amount;
    for (int i = n - 1; i >= 0; i--) {
        while (j >= denom[i] && dp[i][j] == 1 + dp[i][j - denom[i]]) {
            printf("%d ", denom[i]);
            j -= denom[i];
        }
    }
    printf("\n");

    return dp[n - 1][amount]; // Return the minimum number of coins
}

int main() {
    int n = 4;
    int denom[] = {1, 5, 6,9};
    int amount = N;
    int minCoins = coinChange(denom, n, amount);
    printf("Minimum number of coins required = %d\n", minCoins);
    return 0;
}

