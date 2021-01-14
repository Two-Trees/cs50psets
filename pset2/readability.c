#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//teachtolearn.life
    
int main(void)
{
    
    string lang = get_string("What language are you processing?\n");
    
    int len = strlen(lang);

    int letters = 0;
    int words = 0;
    int sentences = 0;
    
    
    for(int i = 0; i <= len; i++)
    {
        if isalpha(lang[i])
        {
            letters++;
        }
        
        if ((i == 0 && lang[i] == ' ') || 
            (i != len && lang[i] == ' ' && lang[i + 1] != ' ') ||
            (i == len && lang[i] != ' '))
        {
            words++;
        }    
        
        if((lang[i] == '.') || (lang[i] == '!') || (lang[i] == '?'))
        {
            sentences++;
        }
    }    
    
    float L = (letters / (float) words * 100);
    
    float S = (sentences / (float) words * 100);
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
        if(index < 1)
        printf("Before Grade 1\n");
       
        else if(index >= 16) 
        printf("Grade 16+\n");
       
        else
        printf("Grade %i\n", index);
    
}
