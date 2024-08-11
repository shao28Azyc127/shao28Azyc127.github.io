#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);

    int n,t,cnt=0;
    cin>>n;

    bool x=true;
    while(n){
        cnt++;
        if(n%3==1&&x){
            t=cnt;
            x=false;
        }
        n-=1;
        n=n-n/3;
    }

    cout<<cnt<<' '<<t;

    fclose(stdin);
    fclose(stdout);
	return 0;
}
