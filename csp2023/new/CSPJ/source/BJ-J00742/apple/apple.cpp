#include<bits/stdc++.h>
using namespace std;
int n;//apple amount
int cnt;
bool first=true;
int cnt2;
int day=0;
int nday;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=n;
    while(cnt>0){
        cnt2=cnt;
        for(int i=1;i<=cnt;i++){
            if((i+2)%3==0){
                cnt2--;
                if(i==cnt&&first==true){
                    nday=day+1;
                    first=false;
                }
            }
        }
        cnt=cnt2;
        day++;
    }
    cout<<day<<" "<<nday;
    return 0;
}
