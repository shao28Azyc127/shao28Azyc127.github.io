
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q[10000],km[10000];
string str[10000];
char rt[10000],bigest[3001][3001],smallest[3001][3001];
bool compare(int a,int b)
{
    for(int i=0;i<m;i++)
    {
        if(smallest[a][i]>bigest[b][i]) return false;
        else if(smallest[a][i]<bigest[b][i]) return true;
    }
    return false;
}
void st(string a)
{
    for(int i=0;i<m;i++)
    {
        q[i]=a[i]-'a';
    }
    sort(q,q+m);
    for(int i=0;i<m;i++)
    {
        rt[i]='a'+q[i];
    }
}
void usdst(string a)
{
    for(int i=0;i<m;i++)
    {
        q[i]=a[i]-'a';
    }
    sort(q,q+m);
    for(int i=0;i<m;i++)
    {
        rt[m-i-1]='a'+q[i];
    }
}
bool bigcompare(int g)
{
    for(int i=0;i<n;i++)
    {
        if(i==g) continue;
        else
        {
            if(compare(g,i)!=true)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    for(int i=0;i<n;i++)
    {
        usdst(str[i]);
        for(int j=0;j<m;j++)
        {
            bigest[i][j]=rt[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        st(str[i]);
        for(int j=0;j<m;j++)
        {
            smallest[i][j]=rt[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(bigcompare(i)==true)
        {
            km[i]=1;
        }
        else
        {
            km[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<km[i];
    }
    return 0;
}
