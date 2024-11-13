#include <stdio.h>
#include <ctype.h>

void CharacterCounter(FILE* checking, int* character);
void lineCounter(FILE* multiple, int* line);
void wordCounter(FILE* multiple, int* word);
void sentenceCounter(FILE* multiple, int* sentence);
void PrintCounts(int character, int line, int word, int sentence);

int main()
{
    FILE* multiple;
    int characterCount = 0, lineCount = 1, wordCount = 0, sentenceCount = 0, type; 

    multiple = fopen("C:\\Users\\Daiki\\OneDrive\\Documents\\comprog folder 2\\text files\\multiple check.txt", "r");

    if (multiple == NULL)
    {
        printf("ERROR OPENING CHECKING FILE!!");
        return 1;
    }

    // Count all types
    CharacterCounter(multiple, &characterCount);
    rewind(multiple);
    lineCounter(multiple, &lineCount);
    rewind(multiple);
    wordCounter(multiple, &wordCount);
    rewind(multiple);
    sentenceCounter(multiple, &sentenceCount);
    rewind(multiple);

    printf("1 - character\n");
    printf("2 - line\n");
    printf("3 - word\n");
    printf("4 - sentence\n");
    printf("Enter what to count: ");
    scanf("%d", &type);

    // Display the selected count
    if (type == 1)
    {
        printf("\nCHARACTERS: %d\n\n", characterCount);
    }
    else if (type == 2)
    {
        printf("\nLINES: %d\n\n", lineCount);
    }
    else if (type == 3)
    {
        printf("\nWORDS: %d\n\n", wordCount);
    }
    else if (type == 4)
    {
        printf("\nSENTENCES: %d\n\n", sentenceCount);
    }
    else
    {
        printf("\nINVALID TYPE!!\n\n");
    }

    if( type <= 4)
    {
    PrintCounts(characterCount, lineCount, wordCount, sentenceCount);
    }

    fclose(multiple);

    return 0;
}

void CharacterCounter(FILE* checking, int* character)
{
    int ioResult;

    while ((ioResult = fgetc(checking)) != EOF)
    {
        if (isalpha(ioResult)) {
            (*character)++;
        } else if (isdigit(ioResult)) {
            (*character)++;
        } else if (ispunct(ioResult)) {
            (*character)++;
        }   
    }
}

void lineCounter(FILE* multiple, int* line)
{
    int ioResult;

    while ((ioResult = fgetc(multiple)) != EOF)
    {
        if(ioResult == '\n')
        {
            (*line)++;
        }
    }
}

void wordCounter(FILE* multiple, int* word)
{
    int ioResult;
    int inWord = 0; // Initialize inWord to 0

    while ((ioResult = fgetc(multiple)) != EOF)
    {
        if (isspace(ioResult))
        {
            if (inWord) 
            {
                (*word)++; 
                inWord = 0; 
            }
        }
        else 
        {
            inWord = 1; // if it encounter a non space it will be pass 
        }
    }
    if (inWord) //for 1 word
    {
        (*word)++;
    }
}

void sentenceCounter(FILE* multiple, int* sentence)
{
    int ioResult;

    while ((ioResult = fgetc(multiple)) != EOF)
    {
        if (ioResult == '.' || ioResult == '!' || ioResult == '?' )
        {
            (*sentence)++;
        }
    }
}

void PrintCounts(int character, int line, int word, int sentence)
{
    printf("Total Characters: %d\n", character);
    printf("Total Lines: %d\n", line);
    printf("Total Words: %d\n", word);
    printf("Total Sentences: %d\n", sentence);
}