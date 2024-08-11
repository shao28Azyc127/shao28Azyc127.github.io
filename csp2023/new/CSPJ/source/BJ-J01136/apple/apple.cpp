#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int t=n;
    int cnt=0;
    while(t>0){
        if(t%3==0){
            t-=t/3;
            cnt++;
        }
        else{
            t-=t/3+1;
            cnt++;
        }
    }
    cout<<cnt<<" ";
    if(n%3==1){
        cout<<1;
        return 0;
    }
    int f;
    t=n;
    int z=n;
    cnt=0;
    while(t>0){
        if(t%3==0){
            f=t/3;
            t-=t/3;
            cnt++;
        }
        else{
            f=t/3+1;
            t-=t/3+1;
            cnt++;
        }
        n-=f;
        if(t%3==1){
            cout<<cnt+1;
            return 0;
        }
    }
    return 0;
}
