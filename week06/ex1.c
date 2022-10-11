#include <stdio.h>

void sort(int a[], int b[], int n) {
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++ ){
            if(a[i] > a[j]){
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
                c = b[i];
                b[i] = b[j];
                b[j] = c;
            }
        }
    }
    
    
}

int main() {
    int n;
    scanf("%d", &n);

    int at[n], bt[n];
    for(int i = 0; i < n; i++){
        printf("Arrival time and Burst time for %d process\n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    sort(at, bt, n);

    int sum_completion = 0, completion = at[0] + bt[0];
    sum_completion += completion;
    printf("Completion time for 1 = %d\n", completion);
    printf("TAT for 1 = %d\n", completion - at[0]);
    int sum_tat = completion - at[0];
    printf("WT for 1 = %d\n", sum_tat - bt[0]);
    int sum_wt = sum_tat - bt[0];

    for(int i = 1; i < n; i++){
        completion = completion + bt[i];
        printf("Completion time for %d = %d\n", i + 1, completion);
        printf("TAT for %d = %d\n", i + 1, completion - at[i]);
        printf("WT for %d = %d\n", i + 1, completion - at[i] - bt[i]);
        sum_completion += completion;
        sum_tat += completion - at[i];
        sum_wt += completion - at[i] - bt[i];
    }

    printf("Average TAT = %f\n", (float)sum_tat / n);
    printf("Average WT = %f\n", (float)sum_wt / n);
    return 0;
}

