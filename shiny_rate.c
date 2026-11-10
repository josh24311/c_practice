#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DAYSEC    86400
#define BIG_RATE  8192.0
#define ROUNDSEC  46

int main(void) {
    int day = 0, try = 0;
    double no_hit_rate = (BIG_RATE-1.0) / (BIG_RATE);
    double exp_rate = 0.0;

    printf("Enter TRY:\n");
    fflush(stdout);
    scanf("%d", &try);
    //try = ( DAYSEC  /ROUNDSEC ) * day;
    exp_rate = 1.0 - (pow(no_hit_rate, (double)try));
    printf("Expect shiny rate after %d days is : %f\n", day, exp_rate);
    system("pause");
    return 0;
}