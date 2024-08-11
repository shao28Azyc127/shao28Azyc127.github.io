#include<bits/stdc++.h>
using namespace std;
int cnt[100000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,num = 0,flag = 0,tag = 0,day = 0,l = 0;
    cin>>n;
    while(true){
        l = 0;
        for(int i = 1;i<=n;i++){
            if(cnt[i] == 0){
                l = 1;
                break;
            }
        }
        if(l == 0){
            break;
        }
        day++;
        num = 0;
        flag = 0;
        for(int i = 1;i<=n;i++){
            if(cnt[i] == 0 && flag==0 && num%3==0){
                cnt[i] = 1;
                flag = 1;
                if(i == n){
                    tag = day;
                }
                num++;
            }
            else if(cnt[i] == 1){
                continue;
            }
            else{
                num++;
                flag = 0;
            }
        }
    }
    cout<<day<<" "<<tag;
    return 0;
}
