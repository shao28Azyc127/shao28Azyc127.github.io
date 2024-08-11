#include<bits/stdc++.h>
using namespace std;
int n,day,t=1,cnt,out[100000005],tot,tr,ans;
struct aaa{
    int num;
    bool in;
}apple[100000005];
void calc(int a){
    for(int i=1;i<=n;i++){
        apple[i].num=i+cnt;
    }
    cnt=1;
    t=1;
    day++;
    for(int i=1;i<=a;i++){
        apple[i].in=1;
    }
    apple[1].in=0;
    for(int j=1;j<=a;j++){
        if(apple[t+3].in==1){
            apple[t+3].in=0;
            cnt++;
            if(apple[t+3].num==n) ans=day;
        }
        t+=3;
    }
    if(a-cnt>3){
        calc(a-cnt);
    }else if(a-cnt<=3){
        tr=a;
        return;
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    out[1]=1;
    calc(n);
    if(tr%2==0){
       cout<<day+2<<" ";
    }else{
        cout<<day+3<<" ";
    }if(ans==0){
        ans=day;
       for(int i=1;i<=tr;i++){
         if(apple[i].in==1) ans++;
       }
    }
    cout<<ans;
    return 0;
}
