#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#define MAX_LIMIT 1e38

void CheckValues (int *k, float *x) {

    char enter;
    int power;
    float root;
    bool paired_number = 0, cond;

    do {
        printf("Enter the power of root\n");
        scanf("%d%c", &power, &enter);

        if (power % 2 == 0) {
            paired_number = 1;
        }

        if (power == 0 || enter != '\n') {
            fflush(stdin);
            printf("Enter the correct value\n");
        }
    } while (power == 0 || enter != '\n');

    do {
        printf("Enter the float number you want to get root from\n");

        if (scanf("%f%c", &root, &enter) != 2 || fabsf(root) > MAX_LIMIT)
            cond = 1;
        else
            cond = 0;

        if (cond == 1 || enter != '\n') {
            fflush(stdin);
            printf("Enter the correct value\n");
        }
    } while (cond == 1 || enter != '\n');

    while (power > 0 && paired_number == 1 && root < 0) {
        fflush(stdin);
        printf("Enter the correct value\n");
        printf("Enter the float number you want to get root from\n");
        scanf("%f", &root);
    }

    while (power < 0 && paired_number == 1 && root <= 0) {
        fflush(stdin);
        printf("Enter the correct value\n");
        printf("Enter the float number you want to get root from\n");
        scanf("%f", &root);
    }

    while (power < 0 && paired_number == 0 && root == 0) {
        fflush(stdin);
        printf("Enter the correct value\n");
        printf("Enter the float number you want to get root from\n");
        scanf("%f", &root);
    }

    if (power < 0) {
        power = -power;
        root = powf(root, -1);
    }
    *k = power;
    *x = root;
}

void Accuracy (double *e, unsigned *decimal_places) {
    char enter;
    unsigned n;
    bool cond;
    do {
        printf("Enter the accuracy of calculation in the format of numbers you want to get after point (1-15)\n");
        if (scanf("%u%c", &n, &enter) != 2 || n > 15 || n < 1)
            cond = 1;
        else
            cond = 0;
        if (cond == 1 || enter != '\n') {
            fflush(stdin);
            printf("Enter the valid number\n");
        }
    } while (cond == 1 || enter != '\n');
    *decimal_places = n;
    switch (n) {
        case 1: *e = 1e-1; break;
        case 2: *e = 1e-2; break;
        case 3: *e = 1e-3; break;
        case 4: *e = 1e-4; break;
        case 5: *e = 1e-5; break;
        case 6: *e = 1e-6; break;
        case 7: *e = 1e-7; break;
        case 8: *e = 1e-8; break;
        case 9: *e = 1e-9; break;
        case 10: *e = 1e-10; break;
        case 11: *e = 1e-11; break;
        case 12: *e = 1e-12; break;
        case 13: *e = 1e-13; break;
        case 14: *e = 1e-14; break;
        case 15: *e = 1e-15; break;
        default: break;
    }
}


int main() {
    int symbol;

    do {
        int k;
        unsigned precision;
        float x;
        double d = 1, e = 0, y = 1;
    CheckValues(&k, &x);
    Accuracy(&e, &precision);
    do {
        if (fabs(d) < e)
            break;
        else {
            d = powf(k, -1) * (x / pow(y, k - 1) - y);
            y = y + d;
        }
    } while (fabs(d) > e);
    printf("y = %.*lf", precision , y);
    printf("\nPress Enter if you want to continue or Esc if you want to quit\n");
    symbol = getch();
    while (symbol != 13 && symbol != 27) {
        printf("Please, press Enter if you want to continue or Esc if you want to quit\n");
        symbol = getch();
    }
} while (symbol != 27);
    return 0;
}
