# include <bits/stdc++.h>
# define N 3005
using namespace std;
int n,m;
char s[N][N];
char maxc[N],minc[N];
bool check(int i,int j)
{
    return minc[i]<maxc[j];
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        maxc[i]=minc[i]=s[i][1];
        for(int j=2;j<=m;j++)
            maxc[i]=max(maxc[i],s[i][j]),minc[i]=min(minc[i],s[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
            if(j!=i && !check(i,j))
            {
                flag=0;
                break;
            }
        printf("%d",flag);
    }
    cout<<endl;
    return 0;
}