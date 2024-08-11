#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int gt[100005],n,cost[1000005],x[100005],remain,road,tot,sum,d,tot1,minn = 2147483647;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	f(i,1,n-1){
		cin>>x[i];
		gt[i] = gt[i-1]+x[i];
		tot+=x[i];
	}
	f(i,1,n) cin>>cost[i],minn = min(minn,cost[i]);
	if(minn == cost[1]){
		sum+=cost[1]*tot/d;
		if(tot%d!=0) sum+=cost[1];
		cout<<sum;
		return 0;
	}
	f(i,1,n-1){
		int dis = gt[i]-gt[i-1],p = cost[i];
		if(p<cost[i+1]){
			f(j,i+2,n){
				if(cost[j]<cost[i]){
					dis = gt[j]-gt[i];
					p = cost[j];
					break;
				}
			}
		}
		tot1+=dis;
		if(tot1>tot) break;
		sum+=p*(dis/d);
		if((dis)%d!=0) sum+=p;
		
	}
	cout<<sum-cost[n];
	return 0;
}
