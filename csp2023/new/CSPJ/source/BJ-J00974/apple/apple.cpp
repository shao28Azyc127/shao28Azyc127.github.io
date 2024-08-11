#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int q[100000009];
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        q[i]=1;
    }
    
    int k=1;
    int m=0;
    int j;
    for(j=1;m<n;j++){
		for(int i=1;i<=n;i++){
			if(q[i]>0){
				k++;
			}
			if(k==2){
				k=0;
				m++;
				if(i==n){
					cout<<j<<" ";
				}
				q[i]=0;
			}
		}
	}
    cout<<j;
    return 0;
}
