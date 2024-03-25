// A program to check a sample of text and out put a reading grade level.
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Set global variables.
int num_letters = 0;
int num_sentences = 0;
int num_words = 0;
int num_index = 0;

// Include prototypes for functions made.
int count_letters(string text, int textlen);
int count_sentences(string text, int textlen);
int count_words(string text, int textlen);
int colemanliau(float letters, float words, float sentences);

int main(void)
{
    // take an input of text from the user and measure string length.
    string text = get_string("Text : ");
    int textlen = strlen(text);
    // Call functions to find out number of words, sentenses and letters.
    count_words(text, textlen);
    count_sentences(text, textlen);
    count_letters(text, textlen);
    colemanliau(num_letters, num_words, num_sentences);

    // Conditionals to check what to print to user.
    if (num_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (num_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        for (int i = 1; i < 16; i++)
        {
            if (num_index == i)
            {
                printf("Grade %i\n", i);
            }
        }
    }
}

// Create a function to count sentences.
int count_sentences(string text, int textlen)
{
    int sentences = 0;
    // loop to count through length of text.
    for (int i = 0; i < textlen; i++)
    {
        // Check for ends of sentences, most common being . , ! , ?.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            // Add one to sentences variable.
            sentences = sentences + 1;
        }
    }
    return num_sentences = sentences;
}

// Create a function to count the number of words.
int count_words(string text, int textlen)
{
    int spaces = 0;
    // Create a loop to count through text length.
    for (int i = 0; i < textlen; i++)
    {
        // Check for spaces and add 1 to spaces variable if found during loop.
        if (text[i] == ' ')
        {
            spaces = spaces + 1;
        }
    }
    // Adds 1 to the number of spaces to give the number of words.
    spaces = spaces + 1;
    return num_words = spaces;
}

// Create a function to count the number of alphabetical letters regardless of case.
int count_letters(string text, int textlen)
{
    int letters = 0;
    // loop for text length.
    for (int i = 0; i < textlen; i++)
    {
        // Using isalpha function from ctype.h to check if char is alaphabetic, add 1 to letters variable if
        // so.
        if (isalpha(text[i]))
        {
            letters = letters + 1;
        }
    }
    return num_letters = letters;
}

// Function to compute the coleman-Liau index
int colemanliau(float letters, float words, float sentences)
{
    // compute L + S
    float letters_words = letters / words;
    float sentences_words = sentences / words;
    float l = letters_words * 100;
    float s = sentences_words * 100;
    // compute index value.
    float index = (0.0588 * l - 0.296 * s - 15.8);
    return num_index = round(index);
}
