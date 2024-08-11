#include<bits/stdc++.h>
using namespace std;
bool apple[1000500];
int n,day=0,tday,all;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) apple[i]=1;
    bool change=1;
    while(change){
        change=0;
        day++;
        int cnt=1;
        for(int i=1;i<=n;i++){
            if(apple[i]==1){
                if((cnt+2)%3==0){
                    apple[i]=0;
                    if(i==n) tday=day;
                    change=1;
                }
                cnt++;
            }
        }
    }
    cout<<day-1<<' '<<tday;
    return 0;
}
