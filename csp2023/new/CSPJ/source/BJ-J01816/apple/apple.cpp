#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cnt=0;
    int m=n;
    while(m>0){
        if(m%3==0){
            m-=(m/3);
        }else m-=(m/3+1);
        cnt++;
    }
    printf("%d ",cnt);
    cnt=1;
    while(1){
        if(n%3==1){
            printf("%d ",cnt);
            return 0;
        }else{
            n-=(n-1)/3+1;
            cnt++;
        }
    }
    return 0;
}
