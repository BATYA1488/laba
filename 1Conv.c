#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change(double number, char des)
{
    if (des == 'C')
    {
        if(number < -273.15)
        {
            printf("Absolute zero for Celsius\n");
            return;
        }
        printf("%.2f C\n", number);
        printf("%.2f F\n", number * (9.0 / 5.0) + 32.0);
        printf("%.2f K\n", number + 273.15);
    }
    if (des == 'F')
    {
        if(number < -459.00)
        {
            printf("Absolute zero for Fahrenheit\n");
            return;
        }
        printf("%.2f F\n", number);
        printf("%.2f C\n", (number - 32.0) * 5.0 / 9.0);
        printf("%.2f K\n", (number - 32.0) * 5.0 / 9.0 + 273.15);
    }
    if (des == 'K')
    {
        if(number < 0.00)
        {
            printf("Absolute zero for Calvin\n");
            return;
        }
        printf("%.2f K\n", number);
        printf("%.2f C\n", number - 273.15);
        printf("%.2f F\n", (number - 273.15) * (9.0 / 5.0) + 32.0);
    }
}

int main(int argc, char *argv[])
{

    double grad;
    char design;

    if(argc == 1 || argc>3){
        printf("Error! Enter arguments.");
        return 0;
    }

    grad = atof(argv[1]);

    if (argc == 2)
    {
        design = 'C';
        change(grad, design);
        printf("\n");

        design = 'F';
        change(grad, design);
        printf("\n");

        design = 'K';
        change(grad, design);
        printf("\n");
    }
    else
    {
        design = *argv[2];
        change(grad, design);
    }
    return 0;
}
