#include <bits/stdc++.h>
using namespace std;
int a[10000005];
bool Rule(int x,int y){
    if(x==0)return 0;
    else if(y==0)return 1;
    return x<y;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=0;
    int ans1=0,ans2=1,ans3=0;
    cin >> n;
    if(1){
        int m=n;
        for(int i=1;i<=m;i++){
            a[i]=i;
        }
        while(m){

            for(int i=1;i<=m;i++){
                if((i%3)==1){
                    if(a[i]==n){
                        ans3=ans2;
                    }
                    a[i]=0;
                    m--;
                }

            }
            sort(a+1,a+n+3,Rule);
            ans2++;
        }
    }
    cout << ans2 << ' '<<ans3;
    return 0;
}
