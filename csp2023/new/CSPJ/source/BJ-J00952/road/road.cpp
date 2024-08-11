#include <bits/stdc++.h>
using namespace std;
long long n,d,u[100010],u1[100010],a[100010],mi, mii,mi1,cnt=0,sum=0,i1,sheng,lc,num;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=0;i<n-1;i++){
        cin >> u[i];
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        u1[i]=u[i]+u1[i-1];
    }
    mi1=a[0];
    cnt=0;
    for(int i=0;i<n;i++){
        if(mi1>a[i]){
            mi1=a[i];
            cnt++;
        }
    }
    if(cnt==0){
        num=u1[n-2]/d;
        if(u1[n-2]%d!=0){
            num++;
        }
        cout <<num*a[0];
        return 0;
    }
    mi=INT_MAX;
    mii=0;
    i1=0;
    num=0;
    while(cnt--){
        lc=0;
        num=0;
        for(int i=1;i<n-1;i++){
            if(a[i]<mi){
                mi=a[i];
                mii=i;
                //cout << mii << " ";

                break;
            }
        }
        lc=u1[mii]-u1[i1];
        if(sheng!=0){
            lc-=sheng;

        }
        num=lc/d;

        if(lc%d!=0){
            num+=1;
        }

        sum+=num*a[i1];
        i1=mii;
        sheng=num*d-lc;
        //cout <<mii <<" " <<num<<sum << endl;
    }
    cout << sum;
    return 0;
}
