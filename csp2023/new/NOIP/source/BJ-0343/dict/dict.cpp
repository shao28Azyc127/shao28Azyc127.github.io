#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=3005;

string s[N];
int n,m,a[N][N],b[N][N];

int Max(char a,char b)
{
    int A=a-'a';
    int B=b-'b';
    if(A>B)
        return A*26+B;
    return B*26+A;
}

int Min(char a,char b)
{
    int A=a-'a';
    int B=b-'b';
    if(A<B)
        return A*26+B;
    return B*26+A;
}

bool cmp(int a,int b)
{
    return a>b;
}

bool com(int x,int y)//x<y
{
    for(int i=1;i<=m;i++)
        if(a[x][i]!=a[y][i])
            return a[x][i]<a[y][i];
    return 1;
}

bool com2(int x,int y)//<
{
    for(int i=1;i<=m;i++)
        if(b[x][i]!=a[y][i])
            return b[x][i]<a[y][i];
    return 1;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    if(n==1)
        cout<<1<<endl;
    else if(m==1)
    {
        if(n==1)
        {
            cout<<1<<endl;
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            bool f=1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i&&s[j][0]<s[i][0])
                {
                    f=0;
                    break;
                }
            }
            cout<<f;
        }
        cout<<endl;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            bool f=1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i&&Max(s[j][0],s[j][1])<Min(s[i][0],s[i][1]))
                {
                    f=0;
                    break;
                }
            }
            cout<<f;
        }
        cout<<endl;
    }
    else
    {
        int min1=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                a[i][j]=b[i][j]=s[i][j-1]-'a';
            sort(a[i]+1,a[i]+m+1,cmp);
            sort(b[i]+1,b[i]+m+1);
            if(min1==-1||com(i,min1))
                min1=i;
        }
        for(int i=1;i<=n;i++)
            cout<<com2(i,min1);
        cout<<endl;
    }
    return 0;
}
