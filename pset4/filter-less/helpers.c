#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale ie/ average the rgb values
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over width and height of image to access each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Each image[i][j] pixel consists of 3 BYTE one for each blue, red and green.
            // Get each BYTE with RGBTRIPLE struct, add together, average and round for grayscale pixel.
            int rgb_average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Put new values back into image array
            image[i][j].rgbtBlue = rgb_average;
            image[i][j].rgbtGreen = rgb_average;
            image[i][j].rgbtRed = rgb_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over width and height of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get each colour integer
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            // Apply sepia formula
            int sepia_blue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));
            int sepia_green = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            int sepia_red = round((0.393 * red) + (0.769 * green) + (0.189 * blue));

            // Account for that each pixel colour is only a BYTE in size if single colour integer is larger than 255, set to 255
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }

            // Put new values back into image array
            image[i][j].rgbtBlue = sepia_blue;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtRed = sepia_red;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over height only of image
    for (int i = 0; i < height; i++)
    {
        // Init temp array of just image width
        RGBTRIPLE reflected_image_row[width];

        // write the last pixel of image into first slot of reflected_image_row
        for (int j = 0; j < width; j++)
        {
            reflected_image_row[j] = image[i][width - j - 1];
        }

        // Write reflected_image_row array into image array
        for (int j = 0; j < width; j++)
        {
            image[i][j] = reflected_image_row[j];
        }
    }
    return;
}

// Blur image
// Blur pixel is calcuated by taking average of 9 pixels; a central pixel and the surrounding 8 pixels.
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Init image_blur RGBTRIPLE struct
    RGBTRIPLE image_blur[height][width];

    // Iterate over width and height of image for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Init pixel_count and sum_colour for central and surrrounding pixels
            int pixel_count = 0;
            int sum_blue = 0;
            int sum_green = 0;
            int sum_red = 0;

            // Iterate over a 3x3 area surrounding central pixel
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Check that there is a valid pixel within a the 3x3 area of central pixel
                    // Accounts for edge and corner pixels where there is less pixels surrounding central pixel
                    // Sum colours from central and surronding pixels
                    if (k >= 0 && k < height && l >= 0 && l < height)
                    {
                        sum_blue += image[k][l].rgbtBlue;
                        sum_green += image[k][l].rgbtGreen;
                        sum_red += image[k][l].rgbtRed;
                        pixel_count += 1;
                    }
                }
            }

            // Average and round each sum_colour by number of pixels around central pixel
            image_blur[i][j].rgbtBlue = round((float) sum_blue / pixel_count);
            image_blur[i][j].rgbtGreen = round((float) sum_green / pixel_count);
            image_blur[i][j].rgbtRed = round((float) sum_red / pixel_count);
        }
    }

    // Write image_blur into image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image_blur[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image_blur[i][j].rgbtGreen;
            image[i][j].rgbtRed = image_blur[i][j].rgbtRed;
        }
    }
    return;
}
