#include <stdio.h>

int main() {
    int num1, num2;
    char operation;
    float result;

    while (1) {
        printf(" >> ");
        scanf("%d %c %d", &num1, &operation, &num2);
        printf("\n");
        
        switch(operation) {
            case '+':
                result = num1 + num2;
                printf("%d %c %d = %.2f\n", num1, operation, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%d %c %d = %.2f\n", num1, operation, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%d %c %d = %.2f\n", num1, operation, num2, result);
                break;
            case '/':
                if (num2 != 0) {
                    result = (float)num1 / num2;
                    printf("%d %c %d = %.2f\n", num1, operation, num2, result);
                    break;
                }
                else {
                    printf("Zero Error\n");
                    break;
            }
        }
    }
}