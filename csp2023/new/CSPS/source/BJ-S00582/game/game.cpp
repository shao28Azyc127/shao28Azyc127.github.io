//T1 14:46
//first sent
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int n,i,j;
int a[2000010],b[2000010][40];
long long an[2000010];
string t;
long long tans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>t;
    for(i=0;i<n;i++)
        a[i+1]=t[i]-'a'+1;
    for(i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            if(i>2)
                b[i][a[i-2]]=i-2;
            for(j=1;j<=26;j++)
                if(b[i][j]==0)
                    b[i][j]=b[i-2][j];
            an[i]=an[i-2]+1ll;                
        }
        else
        {
            if(b[i-1][a[i]]==0)
                continue;
            int last=b[i-1][a[i]]-1;
            an[i]=an[last]+1ll;
            b[i][a[last]]=last;
            for(j=1;j<=26;j++)
                if(b[i][j]==0)
                    b[i][j]=b[last][j];
        }
        tans+=an[i];
    }
    cout<<tans;
    return 0;
}