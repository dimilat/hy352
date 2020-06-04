#include <stdio.h>

int myfunction(int a) {
    if (a % 2 == 0) {
        return 1;
        a++;
    } else {
        return 0;
    }
}

int main() {
    int i, j = 0;
    int return_value;
    int A[2][3] = {{0}, {0}};
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d", A[i][j]);
        }
        printf("\n");
    }
    myfunction(i);  // klisi
}