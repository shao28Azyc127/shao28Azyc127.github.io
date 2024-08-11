#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        int k;
        cnt++;
        if(n%3==1&&!ans){
            ans=cnt;
        }
        if(n%3==0){
            k=n/3;
        }else{
            k=n/3+1;
        }
        n-=k;
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}
