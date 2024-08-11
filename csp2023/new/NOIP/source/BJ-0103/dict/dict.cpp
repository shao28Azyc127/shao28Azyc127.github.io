#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
char s[3005][3005],c;
int pos1=-1,pos2=-1;

bool low_max_max(int x, int y)
{
    if(y==-1)
        return 1;
    int i;
    for(i=m-1;i>=0;i--)
    {
        if(s[x][i]>s[y][i])
            return 0;
        if(s[x][i]<s[y][i])
            return 1;
    }
    return 0;
}

bool low_min_max(int x, int y)
{
    int i,j;
    for(i=0,j=m-1;i<m;i++,j--)
    {
        if(s[x][i]>s[y][j])
            return 0;
        if(s[x][i]<s[y][j])
            return 1;
    }
    return 0;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m ;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            c='{';
            while(c<'a' || c>'z')
                c=getchar();
            s[i][j]=c;
        }
        sort(s[i],s[i]+m);
        if(low_max_max(i,pos1))
        {
            pos2=pos1;
            pos1=i;
            continue;
        }
        if(low_max_max(i,pos2))
            pos2=i;
    }
    for(i=0;i<n;i++)
    {
        if(low_min_max(i,pos1) || i==pos1 && low_min_max(i,pos2))
            putchar('1');
        else
            putchar('0');
    }
    return 0;
}
