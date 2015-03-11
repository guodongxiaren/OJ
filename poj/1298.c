#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char str[205];
    while(scanf("%s",str))
    {
        if(strcmp(str,"ENDOFINPUT")==0)
            break;
        getchar();
        gets(str);
        int len=strlen(str);
        for(i=0;i<len;i++) 
        {
            if(isalpha(str[i]))
                str[i]='A'+(str[i]-'A'+21)%26;
        }
        printf("%s\n",str);
        scanf("%s",str);
    }
}

