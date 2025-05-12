#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
int compress(char* chars, int charsSize)
{
    int n=charsSize;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int count=1;
        char ch=chars[i];
        while(i+1<n &&  chars[i+1]==ch)
        {
            count++;
            i++;
        }
        chars[idx++]=ch;
        if(count>1)
        {
            char buffer[12];
            sprintf(buffer,"%d",count);
            for(int j=0;buffer[j]!='\0';j++)
            {
                chars[idx++]=buffer[j];
            }
        }
    }
    return idx;
}
int main() {
    char chars1[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int size1 = sizeof(chars1) / sizeof(chars1[0]);
    int compressedSize1 = compress(chars1, size1);
    printf("Compressed: ");
    for (int i = 0; i < compressedSize1; i++) {
        printf("%c ", chars1[i]);
    }
    printf("\nReturned: %d\n", compressedSize1);

    return 0;
}