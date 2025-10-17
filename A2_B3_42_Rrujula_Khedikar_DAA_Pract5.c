#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char X[MAX], Y[MAX], S[MAX];
    int choice;

    printf("Choose task:\n1. Longest Common Subsequence(LCS)\n2. Longest Repeating Subsequence (LRS)\n");
    printf("Enter choice (1/2):");
    scanf("%d", &choice);

    if (choice==1) {
        printf("Enter first DNA sequence (X):");
        scanf("%s", X);
        printf("Enter first DNA sequence (Y):");
        scanf("%s", Y);

        int m = strlen(X);
        int n = strlen(Y);
        int mat[MAX][MAX];
        char lcs[MAX];
        int i, j;

        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    mat[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                else if (mat[i - 1][j] > mat[i][j - 1])
                    mat[i][j] = mat[i - 1][j];
                else
                    mat[i][j] = mat[i][j - 1];
            }
        }

        i = m;
        j = n;
        int index = mat[m][n];
        lcs[index] = '\0';

        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs[index - 1] = X[i - 1];
                i--;
                j--;
                index--;
            } else if (mat[i - 1][j] > mat[i][j - 1])
                i--;
            else
                j--;
        }

        printf("\n———— TASK 1: LCS ————\n");
        printf("Length of LCS: %d\n", mat[m][n]);
        printf("LCS: %s\n", lcs);
    }
    else if (choice == 2) {
        printf("Enter string to find LRS:");
        scanf("%s", S);

        int n = strlen(S);
        int mat[MAX][MAX];
        char lrs[MAX];
        int i, j;

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    mat[i][j] = 0;
                else if (S[i - 1] == S[j - 1] && i != j)
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                else if (mat[i - 1][j] > mat[i][j - 1])
                    mat[i][j] = mat[i - 1][j];
                else
                    mat[i][j] = mat[i][j - 1];
            }
        }

        i = n;
        j = n;
        int index = mat[n][n];
        lrs[index] = '\0';

        while (i > 0 && j > 0) {
            if (S[i - 1] == S[j - 1] && i != j) {
                lrs[index - 1] = S[i - 1];
                i--;
                j--;
                index--;
            } else if (mat[i - 1][j] > mat[i][j - 1])
                i--;
            else
                j--;
        }


        printf("\n———— TASK 2: LRS ————\n");
        printf("Length of LRS: %d\n", mat[n][n]);
        printf("LCS: %s\n", lrs);
    }
    else {
        printf("Invalid choice!!!");
    }
    return 0;
}