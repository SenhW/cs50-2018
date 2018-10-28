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
    // Number of spaces per row on left side of half-pyramid: Height - 1 - row number (0-indexed)
    // Number of # per row for a half-pyramid: Row number (0-indexed) + 1
    for (int i = 0; i < height; i++) {
        for (int j = i; j < height - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf(" ");
        printf(" ");
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
}