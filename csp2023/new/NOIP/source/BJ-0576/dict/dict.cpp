#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
    int n=1,m=1;
    string a[3001]={};
    int max[3001]={},min[3001]={};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<"1";
    }        
    else
    {
        for(int x=0;x<n;x++)
        {
             int min1=INT_MAX;
             int max1=INT_MIN;
             for(int i=0;i<m;i++)
             {
				 int an=a[x][i];
				 if(an<min1)
				 {
					 min1=an;
				 }
				 if(an>max1)
				 {
					 max1=an;
				 }
			 }
			 max[x]=max1;
			 min[x]=min1;
        }
        for(int i=0;i<n;i++)
        {
			bool flag=false;
			for(int j=0;j<n;j++)
			{
				if(min[i]>=max[j]&&i!=j)
				{
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
    fclose(stdout);
    fclose(stdin);
    return 0;
}