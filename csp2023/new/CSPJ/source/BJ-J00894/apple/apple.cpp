#include <bits/stdc++.h>
using namespace std;
long long a,cnt=0;//141309
long long recursive(long long n){
    cnt++;
    long long tmp=(n-1)/3+1;
    n-=tmp;
    if (n!=0){
        return recursive(n);
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>a;
    if (a==1){
        cout<<"1 1";
    }else if (a==2){
        cout<<"2 2";
    }else if (a==3){
        cout<<"3 3";
    }else{
        recursive(a);
        cout<<cnt;
        if (a%3==1){
            cout<<" 1";
        }else{
            cout<<" "<<cnt;
        }
    }
	return 0;
}
