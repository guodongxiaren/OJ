#include<iostream>
#include<cstring>
using namespace std;
bool g[26][26];
bool used[26];
bool dfs(int i)
{
    used[1]=true;
    for(int j=0;j<26;j++)
    {
        if(i!=j&&!used[j]&&g[i][j])
        {
            if(i!=1)
                g[1][j]=true;
            used[j]=true;
            dfs(j);
        }
    }
    return g[1][12];
}
int main()
{
    char s[100];
    while(cin>>s)
    {
        if(s[0]!='0')
        {
            int len=strlen(s);
            g[s[0]-'a'][s[len-1]-'a']=true;
            continue;
        }
        if(dfs(1))
            cout<<"Yes."<<endl;
        else
            cout<<"No."<<endl;
        memset(g,false,sizeof(g));
        memset(used,false,sizeof(used));
    }
}

