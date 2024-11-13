#include <stdio.h>
#include <ctype.h>

void CharacterCounts(FILE* checking, int* AlphaCount, int* digitCount, int* punctCount, int* spaceCount);
void PrintCounts(int AlphaCount, int digitCount, int punctCount, int spaceCount);

int main()
{
    FILE* checking;
    int AlphaCount = 0, digitCount = 0, punctCount = 0, spaceCount = 0;

    checking = fopen("C:\\Users\\Daiki\\OneDrive\\Documents\\comprog folder 2\\text files\\checking.txt", "r");

    if (checking == NULL)
    {
        printf("ERROR OPENING CHECKING FILE!!");
        return 1;
    }

    CharacterCounts( checking, &AlphaCount, &digitCount, &punctCount, &spaceCount);

    PrintCounts(AlphaCount, digitCount, punctCount, spaceCount);

    fclose(checking);

    return 0;
}

void CharacterCounts(FILE* checking, int* AlphaCount, int* digitCount, int* punctCount, int* spaceCount)
{
    int ioResult;

    while ((ioResult = fgetc(checking)) != EOF)
    {
        if (isalpha(ioResult)) {
            (*AlphaCount)++;
        } else if (isdigit(ioResult)) {
            (*digitCount)++;
        } else if (ispunct(ioResult)) {
            (*punctCount)++;
        } else if (isspace(ioResult)) {
            (*spaceCount)++;
        }
    }
}

void PrintCounts(int AlphaCount, int digitCount, int punctCount, int spaceCount)
{
    printf("The Alphabet characters: %d\n", AlphaCount);
    printf("The Digit characters: %d\n", digitCount);
    printf("The Punctuation characters: %d\n", punctCount);
    printf("The space characters: %d\n", spaceCount);
}
