#include<stdio.h>
#define N 11
int main(){
    int i,j;
    int coins[] = {1,6,5,9};
    int n = 4;
    int amount = N;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(coins[i]<coins[j]){
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
    int selected[N];
    int sel_count = 0;
    for (i = 0; i < n; i++) {
        while (coins[i] <= amount) {
            amount = amount - coins[i];
            selected[sel_count] = coins[i];
            sel_count++;
        }
    }
    printf("Minimum number of coins required =  %d\n",sel_count);
    printf("The actual denominations of coins required are = ");
    for(i=0;i<sel_count;i++){
        printf("%d ",selected[i]);
    }
    return 0;
}



