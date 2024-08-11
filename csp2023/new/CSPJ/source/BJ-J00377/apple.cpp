#include<bits/stdc++.h>
using namespace std;
bool b[1e9+1];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int day=0,cnt1=0,cnt2=0,result;
    bool re=true;
    while(cnt1!=n){
        day++;
        cnt2=0;
        for(int i=1;i<=n;i++){
            if(!b[i]){
                if(cnt2%3==0){
                    b[i]=true;
                    cnt1++;
                }
                cnt2++;
            }
        }
        if(re&&b[n]){
            result=day;
            re=false;
        }
    }
    cout<<day<<' '<<result;
    return 0;
}