#include<iostream>
#include<cstdio>
using namespace std;
int n,day,ans,x,m;
bool a[1000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    x=n;
    while(x){
        day++;
        int cnt=2,t;
        for(int i=1;i<=m;i++){
            if(cnt==2&&a[i]==false){
                cnt=0;
                a[i]=true;
                if(i==n) ans=day;
                x--;
            }else if(a[i]==false){
                cnt++;
                t=i;
            }
        }
        m=t;
    }
    cout<<day<<" "<<ans;
    return 0;
}
