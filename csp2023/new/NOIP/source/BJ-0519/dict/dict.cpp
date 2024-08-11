#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,id1,id2,a[3001][3001],a1[3001][3001],a2[3001][3001],m1[3001],m2[3001];
bool flag;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    	{
    	    char c;
    	    cin>>c;
    	    a[i][j]=c-'a'+1;
    	}
    if(N==1)
    {
        printf("1");
        return 0;
    }
    memset(m1,0x3f,sizeof(m1));
    memset(m2,0x3f,sizeof(m2));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++) a1[i][j]=a[i][j];
        sort(a1[i]+1,a1[i]+M+1);
        for(int j=1;j<=M;j++) a2[i][j]=a1[i][M-j+1];
        flag=0;
        for(int j=1;j<=M;j++)
        {
            if(a2[i][j]>m1[j])
            {
                flag=0; break;
            }
            if(a2[i][j]<m1[j])
            {
                flag=1; break;
            }
        }
        if(flag)
        {
            for(int j=1;j<=M;j++)
            {
                m2[j]=m1[j];
                m1[j]=a2[i][j];
            }
            id2=id1; id1=i;
            continue;
        }
        flag=0;
        for(int j=1;j<=M;j++)
        {
            if(a2[i][j]>m2[j])
            {
                flag=0; break;
            }
            if(a2[i][j]<m2[j])
            {
                flag=1; break;
            }
        }
        if(flag)
        {
            for(int j=1;j<=M;j++) m2[j]=a2[i][j];
            id2=i;
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(i==id1)
        {
            flag=0;
            for(int j=1;j<=M;j++)
            {
                if(a1[i][j]>m2[j])
                {
                    flag=0; break;
                }
                if(a1[i][j]<m2[j])
                {
                    flag=1; break;
                }
            }
            if(flag) printf("1");
            else printf("0");
        }
        else
        {
            flag=0;
            for(int j=1;j<=M;j++)
            {
                if(a1[i][j]>m1[j])
                {
                    flag=0; break;
                }
                if(a1[i][j]<m1[j])
                {
                    flag=1; break;
                }
            }
            if(flag) printf("1");
            else printf("0");
        }
    }
    return 0;
}