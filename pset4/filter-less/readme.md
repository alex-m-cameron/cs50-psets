Filter-less
https://cs50.harvard.edu/x/2025/psets/4/filter/less/

Program to apply a filter to an input image.bmp to out.bmp.
My code is the helpers.c file.
All other files are provided by CS50.


Usage: ./filter -g images/tower.bmp out.bmp
                -g grayscale
                -s sepia
                -r reflect
                -b blur


In the helpers.c file my code has 4 functions for each of the 4 different filters that can be applied.

After the header files of a image.bmp. Each pixel of an image is represented by 3 BYTES of data 1 BYTE for each of Blue, Green and Red in this order left to right.
Each pixel is represented by image[height][width] and each colour BYTE can be accessed by image[i][j].rgbtBlue ect.
