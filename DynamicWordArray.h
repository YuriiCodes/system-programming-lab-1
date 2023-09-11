#ifndef DYNAMICWORDARRAY_H
#define DYNAMICWORDARRAY_H

typedef struct DynamicWordArray DynamicWordArray;  // Forward declaration of the structure

DynamicWordArray* createDynamicWordArray();
void doubleCapacity(DynamicWordArray* array);
void addWord(DynamicWordArray* array, const char* word);
void freeDynamicWordArray(DynamicWordArray* array);

#endif // DYNAMICWORDARRAY_H
