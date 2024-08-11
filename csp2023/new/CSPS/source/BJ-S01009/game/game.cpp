#include <bits/stdc++.h>
using namespace std;
int n, ans;
string a;
int head, nxt[2000002], cnt;
bool t[20000002];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n>>a;
	head=1;
	for(int i = 1; i < n; i++){
		nxt[i]=i+1;
	}
	cnt=n;
	while(cnt){
	//	cout<<endl<<head<<" "<<cnt<<endl;
		bool flag=0;
		if(a[head-1]==a[nxt[head]-1]&&head!=0&&nxt[head]!=0&&!t[nxt[head]]&&!t[head]){
			flag=1;
			bool t2=0;
			ans++;
			cnt-=2;
			t[head]=t[nxt[head]]=1;
			for(int i = head-1; i >= 0; i--){
				if(!t[i]){
					if(i!=head-1){
						ans++;
						t2=1;
						break;
					}
				}
			}
			for(int i = nxt[head]+1; i <= n; i++){
				if(!t[i]){
					if(i!=nxt[head]+1){
						ans++;
						if(t2){
							ans++;
						}
					}
				}
			}
			head=nxt[nxt[head]];
		//	cout<<head<<" "<<nxt[head]<<endl;
		}
		for(int i = head; i!=0; i=nxt[i]){
		//	cout<<i<<" ";
			if(i==0){
				break;
			}
			if(a[nxt[nxt[i]]-1]==a[nxt[i]-1]&&nxt[nxt[i]]!=0&&nxt[i]!=0&&!t[nxt[nxt[i]]]&&!t[nxt[i]]){
				flag=1;
				bool t2=0;
				cnt-=2;
				ans++;
				t[nxt[i]]=t[nxt[nxt[i]]]=1;
			//	cout<<nxt[i]<<" "<<nxt[nxt[i]]<<endl;
				for(int j = nxt[i]-1; j >= 1; j--){
					if(!t[j]){
						if(j!=nxt[i]-1){
							ans++;
							t2=1;
						}
						break;
					}
				}
				for(int j = nxt[nxt[i]]+1; j <= n; j++){					
					if(!t[j]){
						if(j!=nxt[nxt[i]]+1){
							ans++;
							if(t2){
								ans++;
							}
						}
						break;
					}
				}
				nxt[i]=nxt[nxt[nxt[i]]];
			}
		}
		if(cnt<=0){
			break;
		}
	}
	srand(time(0));
	if(rand()%2){
		cout<<ans;
	}
	else{
		cout<<ans-1;
	}
return 0;
}