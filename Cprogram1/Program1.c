#include <stdio.h>

/**
 * Returns month from the integer equivalent
*/
char * intToMonth(int month)
{
    switch (month)
    {
        case (1) : return "January";
        case (2) : return "February";
        case (3) : return "March";
        case (4) : return "April";
        case (5) : return "May";
        case (6) : return "June";
        case (7) : return "July";
        case (8) : return "August";
        case (9) : return "September";
        case (10) : return "October";
        case (11) : return "November";
        case (12) : return "December";
        default : return " ";
    }
}

/**
 * Returns the minimum, maximum, and average of the
 * 12 months' sales.
**/
void min_max_avg(double inputSales[])
{
    double min = inputSales[0];
    int minWhen = 0;
    double max = inputSales[0];
    int maxWhen = 0;
    double rollingSum = 0;
    for (int i = 0; i < 12; i++)
    {
        double temp = inputSales[i];

        rollingSum += temp;
        if (min > temp)
        {
            min = temp;
            minWhen = i;
        }
        if (max < temp)
        {
            max = temp;
            maxWhen = i;
        }
    }

    printf("Minimum sales:    $%.2f    (%s)\n", min, intToMonth(minWhen + 1));
    printf("Maximum sales:    $%.2f    (%s)\n", max, intToMonth(maxWhen + 1));
    printf("Average sales:    $%.2f\n\n", rollingSum / 12);
}

double calc_six_month_avg(double inputSales[], int startIndex)
{
    double rollingSum = 0;
    for (int i = startIndex; i < startIndex + 6; i++)
    {
        double temp = inputSales[i];
        rollingSum += temp;
    }

    printf("%s - %s: $%.2f\n", intToMonth(startIndex + 1), intToMonth(startIndex + 7), rollingSum / 6);
}

void six_month_moving_average(double inputSales[])
{
    printf("Six-Month Average Report:\n\n");

    calc_six_month_avg(inputSales, 0);
    calc_six_month_avg(inputSales, 1);
    calc_six_month_avg(inputSales, 2);
    calc_six_month_avg(inputSales, 3);
    calc_six_month_avg(inputSales, 4);
    calc_six_month_avg(inputSales, 5);
}

/**
 * In descending order
**/
void sort_sales_descending(double inputSales[])
{
    int sortedMonthIndex[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (int i = 0; i < 12; i++)
    {
        // iterates the array elements from index 1
        for (int j = i + 1; j < 12; j++)
        {
            // Comparing the array elements, to set array
            // elements in descending order
            if (inputSales[i] < inputSales[j])
            {
                int temp = inputSales[i];
                inputSales[i] = inputSales[j];
                inputSales[j] = temp;

                int tempIndex = sortedMonthIndex[i];
                sortedMonthIndex[i] = sortedMonthIndex[j];
                sortedMonthIndex[j] = tempIndex;
            }
        }
    }

    printf("Sales Report (Highest to Lowest)\n\n");
    printf("  Month    Sales  \n\n");
    for (int i = 0; i < 12; i++)
    {
        int monthIndex = 0;
        printf("%s  -  %.2f\n", intToMonth(sortedMonthIndex[i] + 1), inputSales[i]);
    }
}

int main()
{
    double sampleInput[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

    printf("Output:\n\n");
    min_max_avg(sampleInput);
    six_month_moving_average(sampleInput);
    sort_sales_descending(sampleInput);

    return 0;
}
