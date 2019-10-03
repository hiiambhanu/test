#include <stdio.h>
int strlen(char a[100])
{
    int len;
    for (len = 0; a[len] != '\0'; len++);
    return len;
}

void main()
{
    char m[100], sub[100];
    int count = 0, j, i;
    printf("Enter main and sub:  ");
    scanf("%s%s", m, sub);
    for (i = 0; i < strlen(m); i++)
    {
        if (m[i] == sub[0])
        {
            for (j = i; j < i + strlen(sub); j++)
            {
                if (sub[j - i] != m[j])
                    break;
            }
            if (j == i + strlen(sub))
                count++;
        }
    }
    printf("The number of occurences are %d\n", count);
}