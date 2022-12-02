#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string text);
char substitute(char letter, int key);

int main(int argc, string argv[])
{
    // Initialize input key as string
    string text = argv[1];

    // Check if correct number of arguments and if each character is a digit
    if (argc == 2 && only_digits(text) == true)
    {
        // Convert input key from string to integer
        int key = atoi(text);

        // Get plaintext as user input
        string plain_text = get_string("plaintext:  ");
        string cipher_text = plain_text;

        // Loop through plaintext, rotating each character to get cipher text
        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            cipher_text[i] = rotate(plain_text[i], key);
        }

        printf("ciphertext: %s\n", cipher_text);
        return 0;
    }

    else
    {
        // Return false if input does not follow requirements
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string text)
{
    // Loop through each letter of the input key
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Continue looping if the current character is a letter
        if (isdigit(text[i]))
        {
            continue;
        }

        // Stop the loop if any character is not a letter
        else
        {
            return false;
        }
    }

    return true;
}

char substitute(char letter, int key)
{
    // Check if character is lowercase
    bool lowercase = islower(letter);

    // Initialize alphabet string
    const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

    // Check if character is alphanumeric
    if (isalpha(letter))
    {
        // Check if character is lowercase
        if (lowercase)
        {
            // Calculate index of new letter after shifting with key value
            int position = letter - 'a';
            int rotated_position = (position + key) % 26;
            char rotated_letter = ALPHABET[rotated_position];

            return rotated_letter;
        }

        // If character is uppercase
        else
        {
            // Change character to lowercase and find index of new letter
            // after shifting with key value
            letter = tolower(letter);
            int position = letter - 'a';
            int rotated_position = (position + key) % 26;
            letter = ALPHABET[rotated_position];

            // Change character back to uppercase
            char rotated_letter = toupper(letter);

            return rotated_letter;
        }
    }

    // If character is not alphanumeric, return original letter
    else
    {
        return letter;
    }
}
