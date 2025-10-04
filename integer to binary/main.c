#include <stdio.h>

void dec_to_Binary(int n) {
    int Num[32];

    int i = 0;
    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        Num[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", Num[j]);
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Binary equivalent of %d is: ", num);
    dec_to_Binary(num);
    printf("\n");

    return 0;
}
