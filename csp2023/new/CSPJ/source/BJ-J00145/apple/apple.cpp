#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int x=n;
    while(x){
        int d;
        if(x%3==0) d=x/3;
        else d=(x+3-x%3)/3;
        if(d==0) d=1;
        x-=d,cnt++;
        if((x+d)%3==1&&flag==0){
            ans=cnt;
            flag=1;
        }
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
