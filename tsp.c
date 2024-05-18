#include <stdio.h>
#define MAX_N 10 // Maximum number of cities

int tsp(int n, int dist[MAX_N][MAX_N], int dp[MAX_N][1 << MAX_N], int mask, int pos) {
    // Base case: If all cities have been visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to starting city
    }
    
    // If solution for current state has already been computed
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int min_cost = 1000; // Initialize with a large number
    
    // Explore all possible next cities to visit
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) { // Check if city 'city' has not been visited
            int new_cost = dist[pos][city] + tsp(n, dist, dp, mask | (1 << city), city);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    
    // Store the computed minimum cost in dp table
    return dp[pos][mask] = min_cost;
}

int main() {
    int n = 4; // Number of cities
    int dist[MAX_N][MAX_N] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };
    int dp[MAX_N][1 << MAX_N]; // DP table
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < (1 << MAX_N); j++) {
            dp[i][j] = -1; // Initialize dp table with -1
        }
    }
    int min_cost = tsp(n, dist, dp, 1, 0); // Start with city 0 as initial city and mark it as visited
    printf("Minimum cost: %d\n", min_cost);
    return 0;
}
