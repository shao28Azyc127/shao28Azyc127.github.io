#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    long long cnt=n,all=0,ans=-1;
    while(cnt){
        all++;
        if(cnt%3==1&&ans==-1){
            ans=all;
        }
        cnt-=(cnt+2)/3;
       //cout<<cnt<<endl;
    }
    printf("%lld %lld\n",all,ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
