#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, k, l;
    float p[MAX], q[MAX], e[MAX][MAX], w[MAX][MAX], root[MAX][MAX], temp;

    printf("Enter the number of keys (n): ");
    scanf("%d", &n);

    int keys[MAX];
    printf("Enter the keys:\n");
    for(i = 1; i <= n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the probabilities p[i] for each key:\n");
    for(i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }

    printf("Enter the probabilities q[i] for dummy keys:\n");
    for(i = 0; i <= n; i++) {
        scanf("%f", &q[i]);
    }

    for(i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for(l = 1; l <= n; l++) {
        for(i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            e[i][j] = 999999.0;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for(k = i; k <= j; k++) {
                temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if(temp < e[i][j]) {
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }

    printf("\nOptimal BST cost: %.4f\n", e[1][n]);

    return 0;
}
