#include<bits/stdc++.h>
using namespace std;
int x[500000]={},y[500000]={};
int check(int n,int m)
{
    if(x[0]>y[0])
    {
        bool flag=false;
        int i=0,j=0;
        while(flag!=true&&i==n)
        {
            if(x[i]>y[j]&&x[i+1]<=y[j])
            {
                j++;
            }
            else if(x[i]>y[j]&&x[i+1]>y[j])
            {
                i++;
            }
            else if(x[i]<=y[j])
            { 
				i--;
			}
            if(i!=n&&j==m)
            {
                flag=true;
            }
        }
        if(flag==true)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(x[0]<y[0])
    {
        bool flag=false;
        int i=0,j=0;
        while(flag!=true&&i==n)
        {
            if(x[i]<y[j]&&x[i+1]<y[j])
            {
                i++;
            }
            else if(x[i]<y[j]&&x[i+1]>=y[j])
            {
                j++;
            }
            else if(x[i]>=y[j])
            {
				i--;
			}
            if(i!=n&&j==m)
            {
                flag=true;
            }
        }
        if(flag==true)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(x[0]==y[0])
    {
        return 0;
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>y[i];
    }
    cout<<check(n,m);
    int tempx[500000]={},tempy[500000]={};
    for(int i=0;i<n;i++)
    {
		tempx[i]=x[i];
	}
	for(int i=0;i<m;i++)
	{
		tempy[i]=y[i];
	}
    for(int i=0;i<c;i++)
    {
		for(int i=0;i<n;i++)
        {
		    x[i]=tempx[i];
	    }
	    for(int i=0;i<m;i++)
	    {
		    y[i]=tempy[i];
	    }
        int kx,ky;
        cin>>kx>>ky;
        for(int j=0;j<kx;j++)
        {
			int px,vx;
			cin>>px>>vx;
			x[px-1]=vx;
		}
		for(int j=0;j<ky;j++)
		{
			int py,vy;
			cin>>py>>vy;
			y[py-1]=vy;
		}		
		cout<<check(n,m);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}