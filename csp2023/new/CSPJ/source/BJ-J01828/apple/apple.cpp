#include<bits/stdc++.h>
using namespace std;
#define int long long
int day,n,x=0,gone=LLONG_MAX;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    x=n;
    while(x>0){
        day++;
        if(x<3){
            x--;
            //cout<<"a ";
        }else if(x%3==0){
            x-=x/3;
            //cout<<"b ";
        }else{
            if(x%3==1){
                gone=min(gone,day);
            }
            x-=x/3+1;
            //cout<<"c ";
        }
        //cout<<day<<" "<<x<<endl;
    }
    if(gone==LLONG_MAX){
        gone=day;
    }
    cout<<day<<" "<<gone;
    return 0;
}
