#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 50

int set[MAX_SIZE];
bool chosen[MAX_SIZE];
int target, n;
bool found = false;

void printSubset(int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (chosen[i]) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

void subsets(int current_index, int current_sum) {
    if (current_index == n) {
        if (current_sum == target) {
            printSubset(n);
            found = true;
        }
        return ;
    }
    
    // include
    chosen[current_index] = true;
    subsets(current_index + 1, current_sum + set[current_index]);
    
    // exclude
    chosen[current_index] = false;
    subsets(current_index + 1, current_sum);
}

int main() {
    printf("Enter number of elements in set: ");
    scanf("%d", &n);
    printf("Enter elements of set\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &set[i]);
    }
    printf("Enter Sum: ");
    scanf("%d", &target);
    
    subsets(0, 0);
    
    if (!found) {
        printf("No possible solutions\n");
    }

    return 0;
}
