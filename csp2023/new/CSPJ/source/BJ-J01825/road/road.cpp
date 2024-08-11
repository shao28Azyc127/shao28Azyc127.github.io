#include<bits/stdc++.h>
using namespace std;
int n,d;
int b;
int cnt;
int sum,sum1;
int minn=10001;
struct road{
    int u;
    int a;
}r[100005];
int oil;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>r[i].u>>r[i].a;
        sum+=r[i].u;
        if(r[i].a<minn)
            minn=r[i].a;
    }
    cin>>b;
    for(int i=1;i<n;i++)
    {	
    	if(r[i].u%d==0)
    	{
    		if(oil>=r[i].u*(r[i].u/d))
    		{
    			oil-=r[i].u*(r[i].u/d);
    			continue;
			}
		}
    	else
    	{
    		if(oil>=r[i].u*(r[i].u/d+1))
    		{
    			oil-=r[i].u*(r[i].u/d);
    			continue;
			}
		}
        if(r[i].a>r[i+1].a)
        {
            if(r[i].u%d==0)
            {
                cnt=cnt+(r[i].u/d)*r[i].a;
                oil+=d*(r[i].u*d);
            }
            else
            {
                cnt=cnt+(r[i].u/d+1)*r[i].a;
                oil+=d*(r[i].u*d+1);
            }

        }
        else
        {
            if(r[i].a==minn)
            {
                if(sum%d==0)
                    cnt=cnt+(sum/d)*r[i].a;
                else
                    cnt=cnt+(sum/d+1)*r[i].a;
                cout<<cnt;
                return 0;
            }
            int bj=0;
            for(int j=i+1;j<=n;j++)
            {
                if(r[j].a>=r[i].a)
                {
                    bj++;
                    sum1+=r[j].u;
                }
                else
                    break;	
            }
            i+=bj;
            if(sum1%d==0)
            {
                cnt=cnt+(sum1/d)*r[i].a;
                oil+=d*(sum1/d);
            }
            else
            {
                cnt=cnt+(sum1/d)*r[i].a;
                oil+=d*(sum1/d+1);
            }
        }
        if(r[i].u%d==0)
    	{
    		oil-=r[i].u*(r[i].u/d);
		}
    	else
    	{
    		oil-=r[i].u*(r[i].u/d);
		}
    }
    cout<<cnt;
    return 0;	
}
    