#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int q=n;
    int t1=0,t2;
    bool flag=false;
    while(q!=0){
        t1++;
        if(q%3==1&&flag==false){
            t2=t1;
            flag=true;
        }
        if(q%3==0){
            q-=q/3;
        }else{
            q=q-q/3-1;
        }
    }
    cout<<t1<<" "<<t2;
    return 0;
}
