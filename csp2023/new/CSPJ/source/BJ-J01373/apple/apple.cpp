#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum=0,day=0,ans,a=3,x=1;
    cin>>n;
    bool apple[n+1]={},flag,f=0;
    while(sum<n){
        if(x>n){
            flag=0;
            x=1,f=1;
        }
        if(apple[x]){
            x++;
            continue;
        }
        if(f&&a==2) a=3,f=0;
        if(a>=3){
            a=0,apple[x]=1,sum++;
            if(!flag) flag=1,day++;
            if(x==n) ans=day;
        }
        a++,x++;
    }
    cout<<day<<" "<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}