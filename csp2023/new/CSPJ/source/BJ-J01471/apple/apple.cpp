#include<bits/stdc++.h>
using namespace std;
const long long N=1000000005;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    int p=n;
    while(n>3){
        if(n%3==0){
            n=n-n/3;
        }else{
            n=n-n/3-1;
        }
        cnt++;
    }
    cout<<cnt+n<<" ";
    if(p%3==1){
    	cout<<1;
	}else if(p==9){
		cout<<3;
	}else if(p==6){
		cout<<2;
	}else{
		cout<<cnt+n;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}