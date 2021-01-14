#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCKSIZE 512

typedef uint8_t BYTE; 

//thank you to Harvard CS undergrad Simeon Radev, for your thoughtful guidance
//teachtolearn.life
//bostonphil.org

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1; 
    }

    char *infile = argv[1];
    
    FILE *inptr = fopen(infile, "r");
    
    if(inptr == NULL)
    {
        printf("Unable to open %s!\n", infile);
        return 2; 
    }
    
    char filename[8];
    FILE *outptr = NULL; 
    BYTE buffer[512];
    int counter = 0;
    
    
    while(fread(buffer, 1, BLOCKSIZE, inptr) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
        (buffer[3] & 0xf0) == 0xe0)
        {
            if(outptr == NULL)
            {
                sprintf(filename, "%03i.jpg", counter++);
                outptr = fopen(filename, "w");
            }
           
            else
            {
                fclose(outptr);
                sprintf(filename, "%03i.jpg", counter++);
                outptr = fopen(filename, "w");
            }
        
        } 
     
        if(outptr != NULL)
        {
            fwrite(buffer, 1, BLOCKSIZE, outptr);   
        }    
    }    
        
     
    if(inptr != NULL) 
    {
        fclose(inptr);
    }
    
    if(outptr != NULL) 
    {
        fclose(outptr);
    }
    
}
  
