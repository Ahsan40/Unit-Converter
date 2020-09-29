#include <stdio.h>
#include <string.h>

void inst();

typedef struct
{
    double num;
    char type[7];
} currency;

int main()
{
    inst();
    currency input;
    double final = 0, saving = 0, discount = 0;
    printf("Original Price: ");
    scanf("%lf %s", &input.num, &input.type);
    strupr(input.type);
    printf("Discount (%% OFF): ");
    scanf("%lf", &discount);
    final = input.num * ((100 - discount) / 100);
    saving = input.num - final;
    printf("Final Price: %.2lf %s\n", final, input.type);
    printf("You save %.2lf %s\n", saving, input.type);
    return 0;
}

void inst()
{
    printf("\n            ***************************\n");
    printf("            **  Discount Calculator  **\n");
    printf("            ***************************\n\n");
    printf("  USES: [AMOUNT] [CURRENCY]\n        [DISCOUNT]\n");
    printf("  EXAMPLE: 100 bdt\n           25\n\n");
}