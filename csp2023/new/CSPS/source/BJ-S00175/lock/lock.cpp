#include<bits/stdc++.h>
using namespace std;
int a[100];
int check(int t){
    int cnt=0;
    while(t>0){
        if(t%10!=0)cnt++;
        t=t/10;
    }
    return cnt;
}
int sq(int t){
    int ans=1;
    for(int i=0;i<t;i++){
        ans=ans*10;
    }
    return ans;
}
int absy(int t1,int t2){
    return max(t1-t2,t1-t2<0?10-abs(t1-t2):-(10-abs(t1-t2)));
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a[i]=0;
        for(int j=0;j<5;j++){
            int temp;
            cin>>temp;
            a[i]=a[i]*10+temp;
        }
    }
    int ans=0;
    for(int i=0;i<100000;i++){
        bool q=0;
        for(int j=0;j<n;j++){
            int minut=0;
            for(int k=0;k<5;k++){
                minut=minut*10+absy(a[j]/sq(k)%10,i/sq(k)%10);
            }
            if(!(check(minut)==1||(check(minut/11)==1&&minut%11==0)))q=1;
        }
        if(q==0)ans++;
    }
    cout<<ans<<endl;
}