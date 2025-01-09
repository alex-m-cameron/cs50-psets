# Filter-less
https://cs50.harvard.edu/x/2025/psets/4/filter/less/

- Program to apply a filter to an input image.bmp and outputs an out.bmp image.
- My code is the helpers.c file.
- CS50 provides all other files.


-  Usage: ./filter -g images/tower.bmp out.bmp

-  Argument for each filter
      - -g grayscale
      - -s sepia
      - -r reflect
      - -b blur

\
My code in the helpers.c file has 4 functions for each of the 4 different filters that can be applied.

After the header info of an image.bmp, each pixel of the image is represented by 3 BYTES of data 1 BYTE for each of Blue, Green, and Red in this order left to right.
Each pixel is represented by ```image[height][width]``` and each colour BYTE can be accessed by ```image[i][j].rgbtBlue``` ect.
