/******************************************************************************
LC6 Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
                     

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void* a, const void* b){
    return *(const char*)a - *(const char*)b;
}
typedef struct{
    char *original;
    char *sorted;
} Pair;
int cmpPair(const void* a, const void* b){
    const Pair* pa = (const Pair*)a;
    const Pair* pb = (const Pair*)b;
    return strcmp(pa->sorted, pb->sorted);
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    Pair* pairs = malloc(sizeof(Pair)*strsSize);
    for(int i = 0; i < strsSize; i++){
        char *sorted_str = malloc(sizeof(char)*(strlen(strs[i])+1));
        strcpy(sorted_str, strs[i]);
        qsort(sorted_str, strlen(strs[i]), sizeof(char), cmpChar);
        
        pairs[i].original = strs[i];
        pairs[i].sorted = sorted_str;
    }
    
    qsort(pairs, strsSize, sizeof(Pair), cmpPair);
    char*** returnResult = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    for(int i = 0; i < strsSize; i++){
        if(i == 0 || strcmp(pairs[i].sorted, pairs[i-1].sorted) != 0)
        {
            int lastGroupIndex = *returnSize;
            returnResult = realloc(returnResult, sizeof(char**)*(*returnSize+1));
            returnResult[lastGroupIndex] = malloc(sizeof(char*)*1);
            returnResult[lastGroupIndex][0] = pairs[i].original;//"bat"
            
            (*returnSize)++;
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(*returnSize));
            (*returnColumnSizes)[lastGroupIndex] = 1;            
        }
        else
        {
            int lastGroupIndex = *returnSize -1;
            int lastGroupSize = (*returnColumnSizes)[lastGroupIndex];
            returnResult[lastGroupIndex] = 
                realloc(returnResult[lastGroupIndex], sizeof(char*)*(lastGroupSize+1));
            returnResult[lastGroupIndex][lastGroupSize] = pairs[i].original;
            (*returnColumnSizes)[lastGroupIndex] = lastGroupSize+1;
        }
    }
    return returnResult;
}
int main()
{
    //printf("Hello World");

    return 0;
}