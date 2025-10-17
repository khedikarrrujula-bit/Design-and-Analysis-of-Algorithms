#include <stdio.h>

int main() {
    int n, constraint;

    printf("Enter the number of values:- ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Empty input");
    } else {
        int res[n];

        printf("Enter resource requirements:- ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &res[i]);
        }

        printf("Enter resource constraint:- ");
        scanf("%d", &constraint);

        int max_sum = 0;
        int best_start = -1;
        int best_end = -1;

        for (int mid = 0; mid < n; mid++) {
            int left_sum = 0;
            int left_max = 0;
            int left_index = mid;

            for (int i = mid; i >= 0; i--) {
                left_sum += res[i];
                if (left_sum <= constraint && left_sum > left_max) {
                    left_max = left_sum;
                    left_index = i;
                }
            }

            int right_sum = 0;
            int right_max = 0;
            int right_index = mid;

            for (int j = mid + 1; j < n; j++) {
                right_sum += res[j];
                if (left_max + right_sum <= constraint && left_max + right_sum > max_sum) {
                    right_max = right_sum;
                    right_index = j;
                    max_sum = left_max + right_max;
                    best_start = left_index;
                    best_end = right_index;
                }
            }

            int sum = 0;
            for (int i = 0; i <= mid; i++) {
                sum = 0;
                for (int j = i; j <= mid; j++) {
                    sum += res[j];
                    if (sum <= constraint && sum > max_sum) {
                        max_sum = sum;
                        best_start = i;
                        best_end = j;
                    }
                }
            }

            for (int i = mid + 1; i < n; i++) {
                sum = 0;
                for (int j = i; j < n; j++) {
                    sum += res[j];
                    if (sum <= constraint && sum > max_sum) {
                        max_sum = sum;
                        best_start = i;
                        best_end = j;
                    }
                }
            }
        }

        if (max_sum == 0) {
            printf("No feasible subarray.\n");
        } else {
            printf("Max:- %d\n", max_sum);
            printf("Best subarray:- ");
            for (int i = best_start; i <= best_end; i++) {
                printf("%d ", res[i]);
            }
            printf("\n");
        }
    }

    return 0;
}