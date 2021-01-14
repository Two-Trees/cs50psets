// teachtolearn.life

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
   
    do
    {
        n = get_int("how would you like to cut through the bullshit??\n");
    } while (n < 1 || n > 8);
    
    
    // declares variable i 
    for(int i = 0;  i < n; i++)
    {
        // declares variable j 
        for(int j = 0; j < n; j++)
        {
            //creates conditions for printing hashes and spaces
            if(i + j < n - 1) 
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            
                if(j == n - 1)
                {
                    printf("  ");
                
                    for(int k = 0; k < i + 1; k++)
                    {
                        printf("#");
                    }
                }
            }
        }
        
        printf("\n");
    }
}

