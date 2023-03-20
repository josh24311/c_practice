//L137 implement rand with self define
#include <stdio.h>
#include <time.h>

static unsigned int _next = 1;
int rand(void){
    
    _next = _next * 1103515245 + 12345;
    return _next / 65535 % 32768;
}
void srand(unsigned int seed){
    _next = seed;
}
int main()
{
    srand(time(0));
    printf("%d\n",rand());

    return 0;
}

