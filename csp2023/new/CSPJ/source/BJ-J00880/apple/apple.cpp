#include<bits/stdc++.h>
using namespace std;
bool a[1000000005]={};
long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int c,b;
    int cnt=1;
    while(1){
        int tot=2;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                tot++;
                flag=1;
            }
            else{
                continue;
            }
            if(tot==3){
                a[i]=1;
                if(i==n){
                    b=cnt;
                }
                tot=0;
            }
        }
        if(flag==0){
            c=cnt-1;
            break;
        }
        cnt++;
    }
    cout<<c<<" "<<b;
    return 0;
}
