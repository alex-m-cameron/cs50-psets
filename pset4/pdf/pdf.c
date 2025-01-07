#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage ./pdf filename\n");
        return 1;
    }

    // Open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create buffer for file. unsigned integer of byte size
    uint8_t buffer[4];

    // Create an array of signature bytes that identify a file as a pdf
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    // Read first 4 bytes from the file
    fread(buffer, sizeof(uint8_t), 4, input);

    // Compare the first 4 bytes of input to signature
    for (int i = 0; i < 4; i++)
    {
        if (signature[i] != buffer[i])
        {
            printf("File is Not a pdf\n");
            return 0;
        }
    }

    // File is a pdf if all bytes matched
    printf("File is a PDF\n");

    // Close file
    fclose(input);
    return 0;
}
