#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long a;
    cin>>a;
    long long cnt=0,pos=0;
    while(a>0){
        cnt++;
        if(a%3==1&&pos==0){
            pos=cnt;
        }
        a=a-(a%3==0?a/3:a/3+1);
    }
    cout<<cnt<<" "<<pos<<endl;
    return 0;
}
