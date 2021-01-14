#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h> 
#include <ctype.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int gray = round((float) (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
        }
    }
}

            
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            int sepiaRed = round ((float) ((image[i][j].rgbtRed * 0.393)
            + (image[i][j].rgbtGreen * 0.769)
            + (image[i][j].rgbtBlue * 0.189)));

            int sepiaGreen = round ((float) ((image[i][j].rgbtRed * 0.349)
            + (image[i][j].rgbtGreen * 0.686)
            + (image[i][j].rgbtBlue * 0.168)));

            int sepiaBlue = round ((float) ((image[i][j].rgbtRed * 0.272)
            + (image[i][j].rgbtGreen * 0.534)
            + (image[i][j].rgbtBlue * 0.131)));

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
}

void swap(RGBTRIPLE *image1, RGBTRIPLE *image2)
{
        RGBTRIPLE temp = *image1;
        *image1 = *image2;
        *image2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }

    }
    
}


// Blur image
// Thank you Harvard undergraduate, Simeon Radav++, for your thoughtful guidance! 
// teachtolearn.life

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int blur_red = 0; 
            int blur_green = 0;
            int blur_blue = 0;
            int get_denom = 0;
            
            for(int h = fmax(i - 1, 0); h <= fmin(i + 1, height -1); h++)
            {
                for(int w = fmax(j - 1, 0); w <= fmin(j + 1, width -1); w++)
                {
                
                        blur_red += image[h][w].rgbtRed;
                        blur_green += image[h][w].rgbtGreen;
                        blur_blue += image[h][w].rgbtBlue; 
                        get_denom++;
                }
                        
                    
            }
    
            temp[i][j].rgbtRed = round((float) blur_red / get_denom);  
            temp[i][j].rgbtGreen = round((float) blur_green / get_denom); 
            temp[i][j].rgbtBlue = round((float) blur_blue / get_denom); 
        }
        
    }


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        { 
            image[i][j] = temp[i][j];
           
        }    
    }
    
    return; 
}

