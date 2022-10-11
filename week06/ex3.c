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
    int n, q;
    scanf("%d", &n);

    printf("Quantum for processes\n");
    scanf("%d", &q);

    int at[n], bt[n], copy_bt[n];
    for(int i = 0; i < n; i++){
        printf("Arrival time and Burst time for %d process\n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    sort(at, bt, n);

    int sum_comp[n], sum_tat = 0, sum_wt = 0, p = 0;
    for(int i = 0; i < n; i++){
        sum_comp[i] = 0;
        p += bt[i];
        copy_bt[i] = bt[i];
    }

    int i = 1, sum_prev = 0;
    if(q >= bt[0]){
        sum_comp[0] = at[0] + bt[0];
        sum_prev = sum_comp[0];
        p -= bt[0];
        bt[0] = 0;
    } else{
        sum_comp[0] = q + at[0];
        sum_prev = sum_comp[0];
        p -= q;
        bt[0] -= q;
    }
    while(p != 0){
        int k = i % n;
        if(q >= bt[k] && bt[k] > 0){
            sum_comp[k] = sum_prev + bt[k];
            sum_prev = sum_comp[k];
            p -= bt[k];
            i += 1;
            bt[k] = 0;
        }else if(q < bt[k] && bt[k] > 0){
            sum_comp[k] = sum_prev + q;
            sum_prev = sum_comp[k];
            p -= q;
            i += 1;
            bt[k] -= q;
        } else{
            i += 1;
        }
    }

    for(int i = 0; i < n; i++){
        printf("CT %d = %d\n", i + 1, sum_comp[i]);
        printf("TAT %d = %d\n", i + 1, sum_comp[i] - at[i]);
        printf("WT %d = %d\n", i + 1, sum_comp[i] - at[i] - copy_bt[i]);
        sum_tat = sum_tat + sum_comp[i] - at[i];
        sum_wt = sum_wt + sum_comp[i] - at[i] - copy_bt[i];
    }
    printf("Average TAT = %f\n", (float)sum_tat / n);
    printf("Average WT = %f\n", (float)sum_wt / n);
    return 0;
}


