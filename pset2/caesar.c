#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

//get key 
// get plaintext 
// encipher text
// print eciphered text
bool check_key(string s);

int main(int argc, string argv[])
{

   if(argc != 2 || !check_key(argv[1]))
   {
       printf("Usage: ./caesar key\n");
       return 1;
   }

   int key = atoi(argv[1]);
   
   string plaintext = get_string("plaintext: ");
   
   int len = strlen(plaintext);
   
   printf("ciphertext: ");
   
   for(int i = 0; i < len; i++)
   {
   
   char c = plaintext[i];
   
   if (isupper(c))
   {
      char m = 'A';
      printf("%c", (c - m + key) % 26 + m);
   }
      
      else if (islower(c))
      {
         char m = 'a'; 
         printf("%c", (c - m + key) % 26 + m);
      }
      
      else
      {
         printf("%c", plaintext[i]);
      }
   }
   
   printf("\n");
}   
   
bool check_key(string s)
{      
      int len = strlen(s);
      
      for(int i = 0; i < len; i++)
      {
         if(!isdigit(s[i]))
         {
            return false;
         }
         
      }
      
      return true;
}
