#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=1,a[9][5]={},num=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        num=81;
    }
    if(n>1)
    {
		int df=-1;
		bool flag=false;
	    for(int i=0;i<n-1;i++)
	    {
			for(int j=0;j<5;j++)
			{
				if(a[i][j]!=a[i+1][j])
				{
					if(df!=j&&df!=-1)
					{
						num=1;
						flag=true;
						break;
						break;
					}
					else
					{
						df=j;
					}
				}
			}
		}
		if(flag==false)
		{
			num=10-n;
		}
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}