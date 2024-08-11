#include<iostream>
#include<cstdio>
using namespace std;
char maxx[3005],minn[3005];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    char mm=127;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        getchar();
        maxx[i]=0;
        minn[i]=127;
        for(int j=0;j<m;j++)
        {
            char c=getchar();
            maxx[i]=max(maxx[i],c);
            minn[i]=min(minn[i],c);
        }
        mm=min(mm,maxx[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<(minn[i]<mm||minn[i]==mm&&minn[i]==maxx[i]);
    }
    return 0;
}
