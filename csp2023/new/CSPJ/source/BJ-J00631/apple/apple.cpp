#include <bits/stdc++.h>
using namespace std;
long long n;
long long cnt;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;

        long long left=n;
        while(left>=0){
            int temp=(left/3)+1;
            left=left-temp;
            cnt++;
        }
        cout<<cnt<<" ";
        if(n%3==0) cout<<n/3<<endl;
        if(n%3==1) cout<<1<<endl;
        if(n%3==2) cout<<cnt<<endl;



    return 0;
}

