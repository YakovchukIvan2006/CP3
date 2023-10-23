#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#define MAX_LIMIT 1e51

void findCubicEquationCoefficients(double *a, double *b, double *c) {
    char enter;
    double first_cof, second_cof, third_cof;
    bool cond;
    printf("Enter the coefficients of the cubic equation in range from -1e51 to 1e51.\nx^3 + ax^2 + bx + c = 0\n");
         do {
             cond = 0;
             printf("Enter coefficient a for the cubic equation:\n");
             if (scanf("%lf%c", &first_cof, &enter) != 2 || fabs(first_cof) > MAX_LIMIT || enter != '\n') {
                 cond = 1;
                 fflush(stdin);
                 printf("Enter valid coefficient.\n");
             }
         } while (cond == 1);
         printf("Your cubic equation now looks like:\nx^3 + (%lf)x^2 + bx + c = 0\n", first_cof);
         do {
             cond = 0;
             printf("Enter coefficient b for the cubic equation:\n");
             if (scanf("%lf%c", &second_cof, &enter) != 2 || fabs(second_cof) > MAX_LIMIT || enter != '\n') {
                 cond = 1;
                 fflush(stdin);
                 printf("Enter valid coefficient.\n");
             }
         } while (cond == 1);
         printf("Your cubic equation now looks like:\nx^3 + (%lf)x^2 + (%lf)x + c = 0\n", first_cof, second_cof);
         do {
             cond = 0;
             printf("Enter coefficient c for the cubic equation:\n");
             if (scanf("%lf%c", &third_cof, &enter) != 2 || fabs(third_cof) > MAX_LIMIT || enter != '\n') {
                 cond = 1;
                 fflush(stdin);
                 printf("Enter valid coefficient.\n");
             }
         } while (cond == 1);
         printf("Your cubic equation now looks like:\nx^3 + (%lf)x^2 + (%lf)x + (%lf) = 0\n", first_cof, second_cof, third_cof);
         *a = first_cof;
         *b = second_cof;
         *c = third_cof;
    }
int main() {
    int symbol;
    bool cond1;
    do {
        do {
            double a, b, c, p, q, d;
            cond1 = 0;
            findCubicEquationCoefficients(&a, &b, &c);
            p = b - ((pow(a, 2)) / 3);
            q = ((2 * pow(a, 3)) / 27) - ((a * b) / 3) + c;
            d = ((pow(p, 3)) / 27) + ((pow(q, 2)) / 4);

            if (d > 0) {
                double u, v, y1, y2, y_complex;
                u = cbrt((-q / 2) + sqrt(d));
                if (u == 0) {
                    cond1 = 1;
                    printf("Enter valid coefficients. Entered coefficients do not exist.\n");
                    continue;
                }
                v = -p / (3 * u);
                y1 = (u + v) - a / 3;
                y2 = ((-1) * ((u + v) / 2)) - a / 3;
                y_complex = (sqrt(3) * (u - v)) / 2;
                printf("Roots of the equation are:\nx1 = %lf;\nx2 = %lf + %lfi;\nx3 = %lf - %lfi.\n", y1, y2, y_complex, y2, y_complex);
            }

            if (a == 0 && b == 0 && c == 0) {
                printf("Roots of the equations are:\nx = 0.\n");
                break;
            }

            if (d == 0) {
                double y1, y2;
                if (p == 0) {
                    cond1 = 1;
                    printf("Enter valid coefficients. Entered coefficients do not exist.\n");
                    continue;
                }
                y1 = ((3 * q) / p) - a / 3;
                y2 = ((-1) * ((3 * q) / 2 * p)) - a / 3;
                printf("Roots of the equation are:\nx1 = %f;\nx2 = x3 = %f.\n", y1, y2);
            }

            if (d < 0) {
                double r, f, y1, y2, y3;
                const double pi = 3.14159;
                if (((-1) * ((pow(p, 3))) / 27) < 0) {
                    cond1 = 1;
                    printf("Enter valid coefficients. Entered coefficients do not exist.\n");
                    continue;
                }
                r = sqrt((-1) * ((pow(p, 3)) / 27));
                if (r == 0) {
                    cond1 = 1;
                    printf("Enter valid coefficients. Entered coefficients do not exist.\n");
                    continue;
                }
                if (((-q) / (2 * r)) < -1 || ((-q) / (2 * r)) > 1) {
                    cond1 = 1;
                    printf("Enter valid coefficients. Entered coefficients do not exist.\n");
                    continue;
                }
                f = acos((-q) / (2 * r));
                y1 = (2 * fabs(cbrt(r)) * cos(f / 3)) - a / 3;
                y2 = (2 * fabs(cbrt(r)) * cos((f + 2 * pi) / 3)) - a / 3;
                y3 = (2 * fabs(cbrt(r)) * cos((f + 4 * pi) / 3)) - a / 3;
                printf("Roots of the equation are:\ny1 = %f;\ny2 = %f;\ny3 = %f.\n", y1, y2, y3);
            }
        } while (cond1 == 1);

        printf("Press Enter if you want to continue or Esc if you want to quit.\n");
        symbol = getch();
        while (symbol != 13 && symbol != 27) {
            printf("Please, press Enter if you want to continue or Esc if you want to quit!\n");
            symbol = getch();
        }
    } while (symbol != 27);

    return 0;
}

