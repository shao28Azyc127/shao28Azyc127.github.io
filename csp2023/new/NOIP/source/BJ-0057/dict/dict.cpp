#include <bits/stdc++.h>
using namespace std;

const int NR=3e3+100;
string s[NR];
string a[NR],b[NR];
string num1,num2;
char c[NR];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++) c[j]=s[i][j];
        sort(c,c+m);
        for(int j=0;j<m;j++) a[i]=a[i]+c[j];
        for(int j=0;j<m;j++) b[i]=b[i]+c[m-1-j];
    }
    num1=b[1];
    int id1=1;
    for(int i=1;i<=m;i++) num2=num2+"z";
    for(int i=2;i<=n;i++)
    {
        if(b[i]<num1) num1=b[i],id1=i;
        else if(b[i]<num2) num2=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i==id1)
        {
            if(a[i]<num2) printf("1");
            else printf("0");
        }
        else
        {
            if(a[i]<num1) printf("1");
            else printf("0");
        }
    }
    puts("");
    return 0;
}
