#include <stdio.h>

void allPossiblePlays(int points)
{
    if (points <= 1) return;

    int amtTD2PT = 0; // 8 pts
    int amtTDFG = 0; // 7 pts
    int amtTD = 0; // 6 pts
    int amt3PTFG = 0; // 3 pts
    int amtSafety = 0; // 2 pts

    for(int amtTD2PT = 0; amtTD2PT <= (points / 8); amtTD2PT++)
    {
        for(int amtTDFG = 0; amtTDFG <= ((points - (8 * amtTD2PT)) / 7); amtTDFG++)
        {
            for(int amtTD = 0; amtTD <= ((points - (7 * amtTD2PT)) / 6); amtTD++)
            {
                for(int amt3PTFG = 0; amt3PTFG <= ((points - (6 * amtTD2PT)) / 3); amt3PTFG++)
                {
                    for(int amtSafety = 0; amtSafety <= ((points - (3 * amtTD2PT)) / 2); amtSafety++)
                    {
                        if((amtTD2PT * 8) + (amtTDFG * 7) + (amtTD * 6) + (amt3PTFG * 3) + (amtSafety * 2) == points)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", amtTD2PT, amtTDFG, amtTD, amt3PTFG, amtSafety);
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(void)
{
    // Initialize user input to 2, and make the while loop condition
    // to break on any number not greater than one.
    int userInput = 2;
    while (userInput > 1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: "); // Print lines
        scanf("%d", &userInput); // Get user input
        allPossiblePlays(userInput); // Function does not return anything for input <= 1
    }
    return 0; // exit
}
