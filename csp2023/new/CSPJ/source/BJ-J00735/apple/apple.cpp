#include <iostream>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int k=n;
    int cnt=0;
    while(true){
		if(n<=3){
			cnt+=n;
			break;
		}
        if(n%3==0){
            n-=n/3;
            cnt++;
        }else{
            n-=n/3+1;
            cnt++;
        }
    }
    cout<<cnt<<" ";
    if(k%3==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		if(k%3==1){
			cout<<i;
		}else if(k%3==0){
			k-=k/3;
		}else{
			k-=k/3+1;
		}
	}
    return 0;
}
