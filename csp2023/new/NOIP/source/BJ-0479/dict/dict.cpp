#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=3005;
char c[N][N],d[N][N];
int cnt[30];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>c[i][j],d[i][j]=c[i][j];
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=26; j++) cnt[j]=0;
        for(int j=1; j<=m; j++)
            cnt[c[i][j]-'a'+1]++;
        int t=0;
        for(int j=26; j<=1; j--)
            while(cnt[j]>0) cnt[j]--,c[i][++t]=(char)(j-1+'a');
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            d[i][j]=c[i][m-j+1];
    }
    int a=1,b=2;
    for(int i=2; i<=n; i++)
    {
        bool flag=false;
        for(int j=1; j<=m; j++)
        {
            if(c[i][j]<c[a][j])
            {
                flag=true;
                break;
            }
            if(c[i][j]>c[a][j]) break;
        }
        if(flag) b=a,a=i;
        else
        {
            flag=false;
            for(int j=1; j<=m; j++)
            {
                if(c[i][j]<c[b][j])
                {
                    flag=true;
                    break;
                }
                if(c[i][j]>c[b][j]) break;
            }
            if(flag) b=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(a==i)
        {
            int flag=0;
            for(int j=1; j<=m; j++)
            {
                if(d[i][j]<c[b][j])
                {
                    flag=1;
                    break;
                }
                if(d[i][j]<c[b][j]) break;
            }
            cout<<flag;
        }
        else
        {
            int flag=0;
            for(int j=1; j<=m; j++)
            {
                if(d[i][j]<c[a][j])
                {
                    flag=1;
                    break;
                }
                if(d[i][j]<c[a][j]) break;
            }
            cout<<flag;
        }
    }
    cout<<endl;
    return 0;
}
