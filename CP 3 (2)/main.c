#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

void DayFromDate(int year, int month, int date) {
    int n, day;
    bool leap_year = 0, cond;
    char enter = 0;

    do {
        printf("Enter the date (Format: date.month.year). The program only works for years between 1900 and 2999\n");
        scanf_s("%u.%u.%u%c", &date, &month, &year, &enter);

        if ((year % 100 != 0) && (year % 4 == 0) || (year % 100 == 0) && (year % 400 == 0)) {
            leap_year = 1;
        }

        if (year <= 0 || year >= 3000 || enter != '\n') {
            cond = 1;
            fflush(stdin);
            printf("Wrong year entered!\n");
        }

        else if (month <= 0 || month >= 13 || enter != '\n') {
            cond = 1;
            fflush(stdin);
            printf("Wrong month entered!\n");
        }

        else if (leap_year == 0 && month == 2 && ((date <= 0 || date >= 29) || enter != '\n')) {
            cond = 1;
            fflush(stdin);
            printf("Wrong date entered!\n");
        }

        else if (leap_year == 1 && month == 2 && (date <= 0 || date >= 30 || enter != '\n')) {
            cond = 1;
            fflush(stdin);
            printf("Wrong date entered!\n");
        }

        else if ((month == 4 || month == 6 || month == 9 || month == 11) && (date <= 0 || date >= 31 || enter != '\n')) {
            cond = 1;
            fflush(stdin);
            printf("Wrong date entered!\n");
        }

        else if ((month != 4 && month != 6 && month != 9 && month != 11) && (date <= 0 || date >= 32 || enter != '\n')) {
            cond = 1;
            fflush(stdin);
            printf("Wrong date entered!\n");
        }

        else {
            cond = 0;
        }

    } while (cond == 1);

    if (month > 2)
        n = 0;
    else if (((year % 100 != 0) && (year % 4 == 0) || (year % 100 == 0) && (year % 400 == 0)) && month <= 2)
        n = 1;
    else
        n = 2;

    int a = 365.25 * year;
    int b = 30.56 * month;

    day = (a + b + date + n) % 7;

    switch (day) {
        case 0:  printf("Monday"); break;
        case 1: printf("Tuesday"); break;
        case 2: printf("Wednesday"); break;
        case 3: printf("Thursday"); break;
        case 4: printf("Friday"); break;
        case 5: printf("Saturday"); break;
        case 6:  printf("Sunday"); break;
        default: break;
    }
}

int main() {
    int year = 0, month = 0, date = 0, symbol;

    do {
        DayFromDate(year, month, date);
        printf("\nPress Enter if you want to continue or Esc if you want to quit\n");
        symbol = getch();
        while (symbol != 13 && symbol != 27) {
            printf("Please, press Enter if you want to continue or Esc if you want to quit\n");
            symbol = getch();
        }
    } while (symbol != 27);

    return (0);
}