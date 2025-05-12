#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
bool isAlphanumeric(char ch)
{
    if(ch>='0'&& ch<='9'|| tolower(ch)>='a'&& tolower(ch)<='z')
    {
        return true;
    }
    return false;
}
bool isPalindrome(char* s) 
{
    if(s==NULL)
    {
        return false;
    }
    int start=0,end=strlen(s)-1;
    while(start<end)
    {
        while(!isAlphanumeric(s[start]))
        { 
            start++;
           continue;
        }
        while(!isAlphanumeric(s[end])) 
        {
            end--;
            continue;
        }
        if(tolower(s[start])!=tolower(s[end])) 
            return false;
        start++;
        end--;
    }
    return true;
}

int main() 
{
    char s[] = "race a car";
    bool result = isPalindrome(s);
    printf("Output: %s\n", result ? "true" : "false"); 
    return 0;
}