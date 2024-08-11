#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt,ansday=0,ansn,flag=1;
    cin>>n;
    cnt=n;
    while(cnt>0){
        ansday++;
        if(flag&&(cnt-1)%3==0){
            ansn=ansday;
            flag=0;
        }
        cnt-=(cnt-1)/3+1;
    }
    cout<<ansday<<" "<<ansn;
    return 0;
}