#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,an;
    cin>>n;
    int m=n,cnt=0;
    while(m){
        cnt++;
        if(m%3==1)an=cnt;
        m=m/3*2+m%3;
    }
    cout<<cnt<<" "<<an;
    return 0;
}
