#include<iostream>
#include<cstdio>
using namespace std;
//bool a[3000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cur,ans=0,cnt=0;
    cin>>n;
    cur=n;
    while(cur){
        cnt++;
        if(cur%3==0) cur-=cur/3;
        else if(cur%3==1){
                if(ans==0) ans=cnt;
                cur-=cur/3,cur--;
        }
        else if(cur%3==2) cur-=cur/3,cur--;
        else if(cur==2) cur--;
        else if(cur==1){
            if(ans==0) ans=cnt;
            cur--;
        }

    }
    cout<<cnt<<' '<<ans;
    return 0;
}
