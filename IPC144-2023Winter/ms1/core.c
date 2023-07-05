#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
    char choice = 0;
    printf("enter something: ");
    choice = getchar();

    printf("%c", choice);

    if (choice == 'n')
    {
        printf("see its working wtf\n");
    }

    return 0;
}