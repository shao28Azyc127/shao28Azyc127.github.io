#include <iostream>

using namespace std;

long long n,ans=0;
long long nstr[2000005],lstr[2000005],num[2000006],val[2000005];
bool pre[30];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n ;
    char c;
    long long i,j,x;
    for(i=1;i<=n;i++)
    {
        cin >> c ;
        x=c-'a'+1;
        val[i]=x;
        if(pre[x]==0)
        {
            pre[x]=1;
            continue;
        }
        j=i-1;
        bool q=0;
        while(j>0)
        {
            if(val[j]==x)
            {
                q=1;
                break;
            }
            j=nstr[j]-1;
        }
        if(q==0)
            continue;
        nstr[i]=j;
        num[i]=1;
        if(j>2 && lstr[j-1]!=0)
        {
            num[i]+=num[j-1];
            lstr[i]=lstr[j-1];
        }
        else
            lstr[i]=j;
        ans+=num[i];
    }
    cout << ans ;
}
