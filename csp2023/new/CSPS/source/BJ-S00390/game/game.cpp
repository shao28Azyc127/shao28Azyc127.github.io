#include <iostream>
using namespace std;
char a[2000005];
bool zc(int x,int y){
	char answer[2000005];
	int anss=y-x+1;
	for(int i=x;i<=y;i++){
		answer[i-x+1]=a[i];
	}
	int answ=0;
	while(anss>0){
		for(int i=1;i<=y-x+1;i++){
			if(answer[i]=='A'){
				continue;
			}
			for(int j=i+1;j<=y-x+1;j++){
				if(answer[j]!='A' and answer[i]==answer[j]){
					answer[i]='A';
					answer[j]='A';
					anss-=2;
					break;
				}
			}
		}
		answ++;
		if(answ>y-x+1){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(zc(i,j)==true){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
