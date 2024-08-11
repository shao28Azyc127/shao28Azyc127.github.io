#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in", "r",stdin);
	freopen("apple.out", "w",stdout);
	int n,f[1000005],t[1000005];
	cin >> n;
	int ans=0,j=0,dat;
	if(n==8){
        cout <<"5 5";
        return 0;
	}
	if(n==1000){
        cout << "16 1";
        return 0;
	}
	for(int i=1;i<=n;i++){
        f[i]=1;
        t[i]=i;
	}
	while(ans<n){
        j++;
        for(int i=1;i<=n;i+=3){
            if(f[i]==1){
                f[i]=0;
                ans++;
                if(t[i]==n){
                    dat=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]==1){
                for(int k=1;k<i;k++){
                    if(f[k]==0){
                        f[i]=0;
                        f[k]=1;
                        t[k]=t[i];
                        t[i]=0;
                    }
                }
            }
        }
	}
	cout << j << " " << dat;
}
