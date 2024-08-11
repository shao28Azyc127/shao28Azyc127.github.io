#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
struct word
{
    char s[3][3005];
    void in()
    {
        scanf("%s",s[0]+1);
        for(int i=1;i<=m;i++)
            s[1][i]=s[2][i]=s[0][i];
        sort(s[1]+1,s[1]+m+1);
        sort(s[2]+1,s[2]+m+1,greater<char>());
    }
} a[3005];
bool _(char* a,char* b){
    for(int i=1;i<=m;i++)
        if(a[i]<b[i]) return false;
        else if(a[i]>b[i])return true;
    return false;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        a[i].in();
    for(int i=1;i<=n;i++)
    {
        bool b=true;
        for(int j=1;j<=n&&b;j++)
        {
            if(j!=i&&_(a[i].s[1],a[j].s[2]))
            {
                b=false;
                //cout<<"i="<<i<<" j="<<j<<" a[j].s[2]="<<(a[j].s[2]+1)<<" a[i].s[1]="<<(a[i].s[1]+1)<<'\n';
            }
        }
        cout<<b;
    }
    return 0;
}
