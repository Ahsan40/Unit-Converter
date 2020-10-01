#include <stdio.h>
#include <string.h>

void tHeader();
void tWrongInp();
long tBigToSmall(long a, int x, int y);
int tNumbering(char x[]);

typedef struct
{
    long num;
    char type[7];
} time;

typedef struct
{
    long big;
    int small[7];
} tSmallToBigReturn;

tSmallToBigReturn tSmallToBig(long a, int x, int y);

int main()
{
    tHeader();
    time time;
    tSmallToBigReturn result;
    int x = 0, y = 0;
    printf("Input: ");
    scanf("%ld %s", &time.num, &time.type);
    strlwr(time.type);
    char temp[4];

    strncpy(temp, time.type, 3);
    x = tNumbering(temp);
    if (x == -500)
    {
        tWrongInp();
        return -1;
    }
    strcpy(temp, &time.type[4]);
    y = tNumbering(temp);
    if (y == -500)
    {
        tWrongInp();
        return -1;
    }
    result = tSmallToBig(time.num, x, y);
    strupr(temp);
    if (x - y > 0)
        printf("Output: %ld %s\n", tBigToSmall(time.num, x, y), temp);
    else if (x - y < 0)
    {
        if ((result.small[x] > 0) || (result.small[x+1] > 0) || (result.small[y] > 0) || (result.small[y-1] > 0))
        {
            printf("Output: %ld %s ", result.big, temp);
            switch (y)
            {
            case 5:
                if (result.small[5] != 0)
                    printf("%d WEEK ", result.small[5]);
            case 4:
                if (result.small[4] != 0)
                    printf("%d DAY ", result.small[4]);
            case 3:
                if (result.small[3] != 0)
                    printf("%d HOUR ", result.small[3]);
            case 2:
                if (result.small[2] != 0)
                    printf("%d MIN ", result.small[2]);
            case 1:
                if (result.small[1] != 0)
                    printf("%d SEC ", result.small[1]);
            case 0:
                if (result.small[0] != 0)
                    printf("%d MIL ", result.small[0]);
                break;
            }
            printf("\n");
        }
        else
            printf("Output: %ld %s\n", result.big, temp);
    }
    else
        printf("Output: %ld %s\n", time.num, temp);
    return 0;
}

long tBigToSmall(long a, int x, int y)
{
    int mul[] = {1000, 60, 60, 24, 7};
    long result = a;
    for (int i = y; i < x; i++)
        result *= mul[i];
    return result;
}

tSmallToBigReturn tSmallToBig(long a, int x, int y)
{
    tSmallToBigReturn result = {a, 0, 0, 0, 0, 0, 0};
    result.small[7];
    int mul[] = {1000, 60, 60, 24, 7};
    for (int i = x; i < y; i++)
    {
        result.small[i] = result.big % mul[i];
        result.big /= mul[i];
    }
    return result;
}

int tNumbering(char x[])
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

void tWrongInp()
{
    printf("\nWRONG INPUT! PLEASE TRY AGAIN!\n");
}

void tHeader()
{
    printf("\n            ***********************\n");
    printf("            **  Time Conversion  **\n");
    printf("            ***********************\n");
    printf("  -> Millisecond = mil      -> Second = sec\n  -> Minute = min           -> Hour = hrs\n");
    printf("  -> Day = day              -> Week = wek\n\n");
    printf("  USES: [AMOUNT] [CURRENT UNIT]-[CONVERT UNIT]\n  EXAMPLE: 1 day-hrs    ('-' is used as 'to')\n\n");
}
