#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double a[N],v[N],s[N];//yuan juli
bool b;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,i,j,cnt=0,sum=0,tmp,idx;
	cin>>n>>d;
	for(i=1;i<=n-1;i++) {cin>>v[i]; s[i]=v[i]+s[i-1];}
	for(i=1;i<=n;i++) cin>>a[i];
	s[n]=s[n-1]+v[n-1];
	for(i=1;i<n;i++)
	{
		b=0;
		if(sum>=v[i]) 
		{
			if(a[i]>=a[i-1]) 
			{
				sum-=v[i];
				continue;
			}
			tmp=sum;
			idx=i+1;
			while(tmp-v[idx]>0)
			{
				tmp-=v[idx];
				if(a[idx]<a[i]) {b=1; break;}
				idx++;
			}
			if(b) continue;
		}
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				b=1;
				cnt+=(int((s[j]-s[i])/d-0.1-sum/d)+1)*a[i];
				sum+=(int((s[j]-s[i])/d-0.1-sum/d)+1)*d;
				break;
			}
		}
		if(!b) 
		{
			cnt+=(int((s[n]-s[i])/d-0.1-sum*1.0/d)+1)*a[i];
			break;
		}
		sum-=v[i];
	}
	cout<<cnt;
	return 0;
}