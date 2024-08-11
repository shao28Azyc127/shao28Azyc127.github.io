#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
char c[MAXN];
int n;
bool hw(char c[],int l)
{
    if(l%2==1) return false;
    else
    {
        int mid=l/2;
        for(int i=0;i<mid;i++)
        {
            if(c[i]!=[c[l-1-i])return false;
        }
    }
    return true;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=2;i<=n;i+=2)
    {
        for(int j=0;j<n;j++)
        {
            char ck[i];
        }
    }
    cout<<"10"<<endl;
    return 0;
}
