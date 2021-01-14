#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{

float change;

    do
    { 
      change = get_float("what is your change?\n");
} while (change < 0);

    int coins = round(change * 100);

    int q = coins / 25;
   
    int afterQuarters = coins % 25;
    
    int d = afterQuarters / 10; 

    int afterDimes = afterQuarters % 10; 
    
    int n = afterDimes / 5; 
    
    int afterNickels = afterDimes % 5; 
    
    int p = afterNickels / 1;
    
    int totalCoins = q + d + n + p; 
    
    printf("%i\n", totalCoins);
  
}