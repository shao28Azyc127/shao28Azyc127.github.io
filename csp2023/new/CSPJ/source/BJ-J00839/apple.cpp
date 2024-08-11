#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n, cnt=0;
    long long flag=0;
    cin>>n;
    while(n){
        cnt++;
        //cout<<n<<endl;
        int t=n/3;
        if(n%3!=0) t++;
        //cout<<flag<<" "<<n<<endl;
        if(n%3==1&&flag==0){
            flag=cnt;
        }
        n-=t;

    }
    cout<<cnt<<" "<<flag;
    return 0;
}
