#include<iostream>
#include<cstdio>
using namespace std;
int a[5][10]={},b[4][10]={};
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,x[5],y[5],c=0;
    cin>>n;
    for(int i=0;i<5;i++) cin>>x[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>y[j];
            y[j]=(y[j]+10-x[j])%10;
        }
        for(int j=0;j<5;j++)
        {
            for(int k=1;k<10;k++)
            {
                if(a[j][k]) continue;
                int f=-1;
                for(int l=0;l<5;l++)
                {
                    if(l==j)
                    {
                        if(y[l]!=k)
                        {
                            if(f==-1) f=l;
                            else if(f==l-1&&(y[l]+10-k)%10==y[l-1]) f=5;
                            else
                            {
                                f=-1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(y[l])
                        {
                            if(f==-1) f=l;
                            else if(f==l-1&&(l-1==j&&y[l]==(y[l-1]+10-k)%10||l-1!=j&&y[l]==y[l-1]))
                                f=5;
                            else
                            {
                                f=-1;
                                break;
                            }
                        }
                    }
                }
                if(f==-1) a[j][k]=1;
            }
        }
        for(int j=0;j<4;j++)
        {
            for(int k=1;k<10;k++)
            {
                if(b[j][k]) continue;
                int f=-1;
                for(int l=0;l<5;l++)
                {
                    if(l==j||l==j+1)
                    {
                        if(y[l]!=k)
                        {
                            if(f==-1) f=l;
                            else if(f==l-1&&(l-1==j&&y[l]==y[l-1]||l-1!=j&&(y[l]+10-k)%10==y[l-1]))
                                f=5;
                            else
                            {
                                f=-1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(y[l])
                        {
                            if(f==-1) f=l;
                            else if(f==l-1&&((l-1==j||l-1==j+1)&&y[l]==(y[l-1]+10-k)%10||l-1!=j&&y[l]==y[l-1]))
                                f=5;
                            else
                            {
                                f=-1;
                                break;
                            }
                        }
                    }
                }
                if(f==-1) b[j][k]=1;
            }
        }
    }
    for(int i=0;i<5;i++)
        for(int j=1;j<10;j++)
            c+=!a[i][j];
    for(int i=0;i<4;i++)
        for(int j=1;j<10;j++)
            c+=!b[i][j];
    cout<<c;
    return 0;
}
