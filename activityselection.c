#include <stdio.h>

struct Activity {
    int start, finish;
};

void selectActivities(struct Activity activities[], int n) {
    // Sort activities by finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (activities[i].finish > activities[j].finish) {
                struct Activity temp = activities[i];
                activities[i] = activities[j];
                activities[j] = temp;
            }
        }
    }

    printf("Selected activities: ");
    int prevFinish = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= prevFinish) {
            printf("A%d ", i + 1);
            prevFinish = activities[i].finish;
        }
    }
    printf("\n");
}

int main() {
    int start[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int finish[] = {4, 3, 7, 5, 6, 8, 10, 9};
    int n = sizeof(start) / sizeof(start[0]);
    struct Activity activities[n];

    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    selectActivities(activities, n);

    return 0;
}
