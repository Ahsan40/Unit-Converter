#include <stdio.h>
#include <string.h>

void inst();
void wrongInp();
long multiply(long a, int x, int y);
long divide(long a, int x, int y);
int numbering(char x[]);

typedef struct
{
    long num;
    char type[7];
} time;

int main()
{
    inst();
    time time;
    int x = 0, y = 0;
    printf("Input: ");
    scanf("%ld %s", &time.num, &time.type);
    strlwr(time.type);
    char temp[4];

    strncpy(temp, time.type, 3);
    x = numbering(temp);
    if (x == -500)
    {
        wrongInp();
        return -1;
    }
    strcpy(temp, &time.type[4]);
    y = numbering(temp);
    if (y == -500)
    {
        wrongInp();
        return -1;
    }
    if (x - y > 0)
        printf("Output: %ld %s\n", multiply(time.num, x, y), temp);
    else if (x - y < 0)
        printf("Output: %ld %s\n", divide(time.num, x, y), temp);
    else
        printf("Output: %ld %s\n", time.num, temp);
    return 0;
}

long multiply(long a, int x, int y)
{
    int mul[] = {1000, 60, 60, 24, 7};
    long result = a;
    for (int i = y; i < x; i++)
        result *= mul[i];
    return result;
}

long divide(long a, int x, int y)
{
    int mul[] = {1000, 60, 60, 24, 7};
    long result = a;
    for (int i = x; i < y; i++)
        result /= mul[i];
    return result;
}

int numbering(char x[])
{
    if (strcmp(x, "mil") == 0)
        return 0;
    else if (strcmp(x, "sec") == 0)
        return 1;
    else if (strcmp(x, "min") == 0)
        return 2;
    else if (strcmp(x, "hrs") == 0)
        return 3;
    else if (strcmp(x, "day") == 0)
        return 4;
    else if (strcmp(x, "wek") == 0)
        return 5;
    else
        return -500;
}

void wrongInp()
{
    printf("\nWRONG INPUT! PLEASE TRY AGAIN!\n");
}

void inst()
{
    printf("\n            ***********************\n");
    printf("            **  Time Conversion  **\n");
    printf("            ***********************\n");
    printf("  -> Millisecond = mil      -> Second = sec\n  -> Minute = min           -> Hour = hrs\n");
    printf("  -> Day = day              -> Week = wek\n\n");
    printf("  USES: [AMOUNT] [CURRENT UNIT]-[CONVERT UNIT]\n  EXAMPLE: 1 day-hrs    ('-' is used as 'to')\n\n");
}