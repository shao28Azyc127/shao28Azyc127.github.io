#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
char s[3010][3010];
bool cmp(char A,char B)
{
    return A<B;
}
bool cmp1(char A,char B)
{
    return A>B;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    for(int i=1;i<=n;i++)
        sort(s[i]+1,s[i]+m+1,cmp1);
    for(int i=1;i<=n;i++)
    {
        bool f=true;
        sort(s[i]+1,s[i]+m+1,cmp);
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(s[i][k]>s[j][k])
                {
                    f=false;
                    break;
                }
                if(s[i][k]<s[j][k])
                    break;
            }
            if(f==false)
                break;
        }
        sort(s[i]+1,s[i]+m+1,cmp1);
        if(f==false)
            cout<<"0";
        else
            cout<<"1";
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
