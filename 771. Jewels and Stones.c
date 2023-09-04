/*
771. Jewels and Stones
回傳在s中，有多少個字元曾經在j中出現
Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 
 作法:
 先統計j中所有元素各自出現的次數存在array
 
*/
int numJewelsInStones(char * jewels, char * stones){
    // j = 'aA' , s = 'aAAbbbb'
    int count = 0;
    int countInJ[256] = {0};
    for(int i = 0; i < strlen(jewels); i++){
        countInJ[jewels[i]]++;
    }

    for(int i = 0; i < strlen(stones); i++){
        if(countInJ[stones[i]] > 0){
            count++;
        }
    }
    return count;
}