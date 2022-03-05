#include <iostream>
#define NOT_FOUND -1

int main()
{
    int signature[]{ 8691, 1, 1, 3696, 69211, 145, 1, 2, 3, 4, 5 };
    int sizeSignature = sizeof(signature) / 4;
    int startOfSignature = 0;
    int pattern[]{ 1, 2, 3, 4, 5 };
    int j = 0; // j == pattern index

    printf("[*]Scanning the signature, size : %d \n", sizeSignature);

    for (int i = 0; i < sizeSignature; i++) // i == signature index
    {
        if (signature[i] == pattern[j])
        {
            // check if the last element in the signature matches
            if (j == (sizeof(pattern) / 4) - 1)
            {
                printf("[*]The patern start at index: signature[%d]!", startOfSignature);
                return 0;
            }

            // when the signature started to match but the last element of the signature is not present in the pattern 
            if (i == sizeSignature - 1 && signature[i] != pattern[(sizeof(pattern) / 4) - 1])
            {
                printf("Pattern not found !");
                return 0;
            }
            //
            j++;
        }

        else
        {
            // when the search for the signature end on something not matching 
            if (i == sizeSignature - 1)
            {
                startOfSignature = NOT_FOUND;
                printf("Pattern not found !");
                return 0;
            }
            //
            startOfSignature++;
            j = 0;
            if (signature[i] == pattern[j]) { j++; }
        }
    }
}