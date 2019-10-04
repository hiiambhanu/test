#include <stdio.h>
void main()
{
    char a[100];
    int i = 0;
    int choice;
    printf("Enter the string \n");
    scanf("%s", a);
    printf("Enter 1 for uppercase and 2 for lowercase \n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (i = 0; a[i] != '\0'; i++)
            if ((int)a[i] >= 97 && (int)a[i] <= 137)
                a[i] = (int)a[i] - 32;
    }

    else if (choice == 2)
        for (i = 0; a[i] != '\0'; i++)
            if ((int)a[i] >= 'A' && (int)a[i] <= 'Z')
                a[i] = (int)a[i] + 32;
    printf("The string is %s \n", a);
}