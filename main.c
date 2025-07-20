#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;
    char c = 'B';
    char *str = "World";

    printf("--- Simple String ---\n");
    len1 = _printf("Hello, Holberton!\n");
    len2 = printf("Hello, Holberton!\n");
    printf("Custom printf length: %d\n", len1);
    printf("Standard printf length: %d\n\n", len2);

    printf("--- Character ---\n");
    len1 = _printf("Character: %c\n", 'A');
    len2 = printf("Character: %c\n", 'A');
    printf("Lengths -> Custom: %d, Standard: %d\n\n", len1, len2);

    printf("--- String ---\n");
    len1 = _printf("String: %s\n", "I am a string!");
    len2 = printf("String: %s\n", "I am a string!");
    printf("Lengths -> Custom: %d, Standard: %d\n\n", len1, len2);

    printf("--- Percent Sign ---\n");
    len1 = _printf("Percent: %%\n");
    len2 = printf("Percent: %%\n");
    printf("Lengths -> Custom: %d, Standard: %d\n\n", len1, len2);

    printf("--- Multiple Specifiers ---\n");
    len1 = _printf("Hello %s! The first letter is %c. This is 100%% correct.\n", str, c);
    len2 = printf("Hello %s! The first letter is %c. This is 100%% correct.\n", str, c);
    printf("Lengths -> Custom: %d, Standard: %d\n\n", len1, len2);

    printf("--- Edge Case: NULL String ---\n");
    len1 = _printf("This is a %s.\n", NULL);
    printf("Custom printf printed %d chars for NULL string.\n", len1);
    len2 = printf("This is a %s.\n", "(null)");
    printf("Standard printf printed %d chars for \"(null)\".\n\n", len2);


    printf("--- Edge Case: Empty String ---\n");
    len1 = _printf("This is an empty string: [%s]\n", "");
    len2 = printf("This is an empty string: [%s]\n", "");
    printf("Lengths -> Custom: %d, Standard: %d\n\n", len1, len2);
    
    printf("--- Edge Case: Unknown Specifier ---\n");
    len1 = _printf("Unknown specifier: %r\n");
    printf("Custom printf printed %d chars for unknown specifier.\n\n", len1);

    return (0);
}
