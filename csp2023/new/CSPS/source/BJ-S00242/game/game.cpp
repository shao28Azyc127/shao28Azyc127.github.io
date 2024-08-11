#include <iostream>
using namespace std;
char x;
int s,t;
char a[2000010];
bool visit[2000010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	cin>>a;
	for (int i=0;i<n;i++){
		
		if(a[i]==a[i+1]){
			if (visit[i]==0&&visit[i+1]==0){
				s++;
				visit[i]=0;
				visit[i+1]=0;
			}	
		}else{
			t=1;
			while(i+t<n){
				if (a[i]==a[i+t]){
					s++;
					visit[i]=0;
					visit[i+t]=0;
					break;
				}else{
					t++;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
