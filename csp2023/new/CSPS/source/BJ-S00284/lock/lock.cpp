#include<bits/stdc++.h>
using namespace std;
int a[100][10];
int data[10];
int f[100];
int s[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<5;i++)
        cin>>data[i];
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    for(int i=0;i<81;i++)
    {
        f[i]=1;
        for(int j=0;j<5;j++)
            a[i][j]=data[j];
    }
    int q=0;
    for(int i=0;i<45;i++,q++)
    {
        if((q%10)==a[i][i/9])
            q++;
        a[i][i/9]=q%10;
    }
    q=0;
    for(int i=45;i<81;i++,q++)
    {
        if((q%10)==a[i][(i-45)/9])
            q++;
        a[i][(i-45)/9+1]=(q-a[i][(i-45)/9]+a[i][(i-45)/9+1]+10)%10;
        a[i][(i-45)/9]=q%10;
    }
    for(int t=1;t<n;t++)
    {
        for(int i=0;i<5;i++)
            cin>>data[i];
        for(int i=0;i<81;i++)
        {
            int found=0;
            if(f[i]==0)
                continue;
            for(int j=0;j<5;j++)
                s[j]=(a[i][j]-data[j]+10)%10;
            for(int x=0;x<5;x++)
            {
                if(s[x]!=0)
                {
                    if(x==4)
                    {
                        found=1;
                        break;
                    }
                    for(int y=x+1;y<5;y++)
                    {
                        if(s[y]!=0)
                            break;
                        if(y==4)
                            found=1;
                    }
                    break;
                }
            }
            if(found==1)
                continue;
            for(int x=0;x<4;x++)
            {
                if(s[x]!=0)
                {
                    if(s[x]==s[x+1])
                    {
                        if(x==3)
                        {
                            found=1;
                            break;
                        }
                        for(int y=x+2;y<5;y++)
                        {
                            if(s[y]!=0)
                                break;
                            if(y==4)
                                found=1;
                        }
                    }
                    break;
                }
            }
            if(found==0)
                f[i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<81;i++)
    {
        if(f[i]==1)
            ans++;
    }
    cout<<ans;
    return 0;
}
