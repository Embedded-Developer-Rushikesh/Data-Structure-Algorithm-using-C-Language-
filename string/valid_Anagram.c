#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
bool isAnagram(char* s, char* t)
{
    int freq[26]={0};
    if(strlen(s)!=strlen(t))
    {
        return false;
    }
    for(int i=0;s[i]!='\0';i++)
    {
        freq[tolower(s[i])-'a']++;
    }
    for(int i=0;t[i]!='\0';i++)
    {
        freq[tolower(t[i])-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char s[8]="rat";
    char t[8]="car";
    bool result=isAnagram(s,t);
    printf("Output: %s\n", result ? "true" : "false"); 
}