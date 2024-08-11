#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	if(n%3==1){
		int cn=0;
		int nn=n;
		while(nn>=0){
			int tmp=nn/3;
			if(nn%3>0){
				tmp++;
			}
			if(nn==0 && tmp==0){
                                break;
                        }
			nn-=tmp;
			cn++;
		}
		
		cout <<cn<<" 1\n";
		return 0;
	}		
	for(int i = 1; i <= n; i++){
         	int cnt=0; 
                for(int j = 1; j <= n; j++){
                        if(a[j]==0){
                                cnt++;
                                if(cnt%3==1){
                                        a[j]=i;
                                }
                        }

                }
        }
	for(int i = 1; i <= n; i++){
		ans=max(ans,a[i]);
	}
	cout << ans<<" "<< a[n]<<"\n";
	return 0;
}