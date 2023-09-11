#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicWordArray.h"

#define INITIAL_CAPACITY 32
#define MAX_WORD_LENGTH 30

struct DynamicWordArray {
    char **words;
    size_t size;
    size_t capacity;
};

DynamicWordArray* createDynamicWordArray() {
    DynamicWordArray *array = (DynamicWordArray*)malloc(sizeof(DynamicWordArray));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    array->words = (char**)malloc(sizeof(char*) * MAX_WORD_LENGTH);
    if (array->words == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    return array;
}

void doubleCapacity(DynamicWordArray *array) {
    array->capacity *= 2;
    array->words = (char**)realloc(array->words, sizeof(char*) * array->capacity);
    if (array->words == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
}

void addWord(DynamicWordArray *array, const char *word) {
    if (array->size == array->capacity) {
        doubleCapacity(array);
    }

    array->words[array->size] = strdup(word);
    if (array->words[array->size] == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    array->size++;
}

void freeDynamicWordArray(DynamicWordArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free(array->words[i]);
    }
    free(array->words);
    free(array);
}
