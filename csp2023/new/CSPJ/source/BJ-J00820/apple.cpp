#include<bits/stdc++.h>
using namespace std;
bool a[100000001];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,days=0,outdays=0,num=0,i=0,q=0,start=1,l=1,kl,outa=0;
	cin>>n;
	if(n%3==1) outdays=1;
	while(num<n){
        q=0;
        for(int i=1;i<=n;i++){
            if(!a[i]) q++;
            if(q%3==1 && !a[i]){
                    a[i]=1,num++;
                    if(i==n && !outdays) outdays=days+1;
            }
        }
        days++;
	}
	cout<<days<<" "<<outdays;
	return 0;
}
