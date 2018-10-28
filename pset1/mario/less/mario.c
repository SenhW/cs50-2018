#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do {
        // Prompt user for height
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);
    // Number of spaces per row = Height - 1 - row number (0-indexed)
    // Number of # per row = Row number (0-indexed) + 2
    for (int i = 0; i < height; i++) {
        for (int j = i; j < height - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < i + 2; k++) {
            printf("#");
        }
        printf("\n");
    }
}