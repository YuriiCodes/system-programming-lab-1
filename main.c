#include <stdio.h>
#include <stdbool.h>
#include <malloc/_malloc.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "DynamicWordArray.c"

/* TASK:
 * Let's have a text file that is not subject to any restrictions on its size.
 * We also do not impose restrictions on the length of a line in this file.
 * The text consists of words, for example, English language identifiers.
 * Words are separated by spaces, brackets, operation codes, or any characters
 * that naturally separate words from each other. We will also not address the issue
 * of the spelling of such words. Let's set a limit on the length of a word - 30 letters.
 * In the result field, we need to display unique words that satisfy a certain condition.
 * Find the words that have the highest number of different letters,
 * i.e., the letters that are repeated in the word should not be considered
 * */




// function to take in a word and return the word but with all letters in lowercase:
char *toLowerCase(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        // check if the character is uppercase and not some other character
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
        i++;
    }
    return word;
}

//function to find the number of different letters in a word
int findUniqueCharsInWord(char *word) {
    //convert the word to lowercase:
    word = toLowerCase(word);

    bool letters[26] = {false}; // Initialize an array to keep track of seen letters
    // (26 letters in the English alphabet)
    int diffCount = 0; // Initialize a counter for different letters

    // Iterate through each character in the word
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i];
        // only check for lowercase letters as we have converted the word to lowercase
        if (ch >= 'a' && ch <= 'z') {
            // If the character is a lowercase letter
            if (!letters[ch - 'a']) {
                // If the letter hasn't been seen before in the word
                letters[ch - 'a'] = true; // Mark the letter as seen
                diffCount++; // Increment the count of different letters
            }
        }
    }

    return diffCount; // Return the count of different letters in the word
}


int main() {
    // dynamically allocated array to store the words(max word size is INITIAL_CAPACITY), can be unlimited size, e.g. ["hello", "world", "this", "is", "a", "test"]
    DynamicWordArray *wordArray = createDynamicWordArray();

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("example.txt", "r");
    if (fp == NULL) { exit(EXIT_FAILURE); }


    char pattern[] = "[a-zA-Z]+";

    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regex pattern\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);

        // Use regex to split the line into words
        regmatch_t match;
        char *str = line;

        while (regexec(&regex, str, 1, &match, 0) == 0) {
            if (match.rm_so == -1) {
                break;
            }
            char *word = strndup(str + match.rm_so, match.rm_eo - match.rm_so);
            printf("\t Word: %s\n", word);
            addWord(wordArray, word);

            free(word);
            str += match.rm_eo;
        }
    }

    regfree(&regex);


    fclose(fp);
    if (line) { free(line); }


    // print the words in the array

    int maxUniqueLetters = 0;
    for (size_t i = 0; i < wordArray->size; i++) {
        int uniqueLetters = findUniqueCharsInWord(wordArray->words[i]);
        printf("word\t#%zu: %s\t|\tunique letters: %d\n", i + 1, wordArray->words[i], uniqueLetters);
        if (uniqueLetters > maxUniqueLetters) {
            maxUniqueLetters = uniqueLetters;
        }
    }

    printf("\n\n");
    printf("The words with the highest number of different letters are:\n");
    for (size_t i = 0; i < wordArray->size; i++) {
        int uniqueLetters = findUniqueCharsInWord(wordArray->words[i]);
        if (uniqueLetters == maxUniqueLetters) {
            printf("word\t#%zu: %s\t|\tunique letters: %d\n", i + 1, wordArray->words[i], uniqueLetters);
        }
    }
    freeDynamicWordArray(wordArray);
    return 0;
}