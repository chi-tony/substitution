// By inputting a key and plaintext, a ciphertext is created

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool valid_key(char *key);
char substitute(char letter, char *key);

int main(int argc, char *argv[])
{
    // Check if key provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Initialize input key as string
    char *key = argv[1];

    // Check if key has 26 characters
    if (strlen(key) != 26 && argc == 2)
    {
        // Print error message to user
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check if correct number of arguments and if each character is a digit
    if (argc == 2 && valid_key(key) == true)
    {
        // Get plaintext as user input
        char *plain_text = get_string("plaintext:  ");
        char *cipher_text = plain_text;

        // Loop through plaintext, substituting each character to get cipher text
        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            cipher_text[i] = substitute(plain_text[i], key);
        }

        // Print ciphertext
        printf("ciphertext: %s\n", cipher_text);
        return 0;
    }

    else
    {
        // Return false if input does not follow requirements
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool valid_key(char *key)
{
    // Initialize alphabet strings for lower case
    const char ALPHABET[27] = "abcdefghijklmnopqrstuvwxyz";

    // Allocate memory for string
    char sorted_key[27] = "";

    // Copy key to sorted_key
    strcpy(sorted_key, key);

    // Initialize temporary letter
    char tmp;

    // Define string length of key
    int n = strlen(sorted_key);

    // Loop through each letter of the input key
    for (int i = 0; i < n - 1; i++)
    {
        // Check subsequent character
        for (int j = i + 1; j < n; j++)
        {
            //
            // Continue looping if the current character is a letter
            if (isalpha(sorted_key[i]))
            {
                // If letter, convert letter and subsequent letter to uppercase
                sorted_key[i] = toupper(sorted_key[i]);
                sorted_key[j] = toupper(sorted_key[j]);

                // If current letter comes after subsequent letter in alphabet, swap letters
                if (sorted_key[i] > sorted_key[j])
                {
                    tmp = sorted_key[i];
                    sorted_key[i] = sorted_key[j];
                    sorted_key[j] = tmp;
                }
            }

            // Stop the loop if any character is not a letter
            else
            {
                return false;
            }
        }
    }

    // Check if sorted_key has all letters in alphabet (ignoring case)
    if (strcasecmp(sorted_key, ALPHABET) == 0)
    {
        // Return true if no duplicates
        return true;
    }

    // Return false if duplicates
    else
    {
        return false;
    }
}

char substitute(char letter, char *key)
{
    // Check if character is alphanumeric
    if (isalpha(letter))
    {
        // Check if character is lowercase
        if (islower(letter))
        {
            // Get position of letter
            int position = letter - 'a';

            // Get letter at same index and change to lowercase
            char sub_letter = tolower(key[position]);

            return sub_letter;
        }

        // If character is uppercase
        else
        {
            // Change character to lowercase and find index of new letter
            letter = tolower(letter);
            int position = letter - 'a';

            // Change character back to uppercase
            char sub_letter = toupper(key[position]);

            return sub_letter;
        }
    }

    // If character is not alphanumeric, return original letter
    else
    {
        return letter;
    }
}
