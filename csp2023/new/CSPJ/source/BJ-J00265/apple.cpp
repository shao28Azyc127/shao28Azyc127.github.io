#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int p=n;
	int sum=0;
	int ans=0;
	if(p<=3){ cout<<p<<" "; cout<<p;}
	else{
		bool falg=true;
	    while(p>3){
		    sum++;
		    if(p%3==1&&falg==true){ ans=sum; falg=false; }
		    p-=p/3+1;
	    } 
	    sum+=p; 
	    cout<<sum<<" "; if(ans==0) cout<<sum; else cout<<ans;
	}
	return 0;
}
