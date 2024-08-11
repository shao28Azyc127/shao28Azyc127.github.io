#include<bits/stdc++.h>
using namespace std;
const int MXN=10,MXS=1e5+100,p10[]={1,10,100,1000,10000};
int n;
int st[MXN];
int get(int num,int i){
    return (num/p10[i])%10;
}
int get_num(int num,int i){
    return get(num,i)*p10[i];
}
bitset<MXS> cnt[MXN];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cnt[i].reset();
        int d,nst;
        for(int j=0;j<=4;j++){
            cin>>d;
            st[i]+=d*p10[j];
        }
        for(int j=0;j<=4;j++){
            for(int k=0;k<=9;k++){
                nst=st[i]-get_num(st[i],j)+k*p10[j];
                if(nst==st[i]) continue;
                //for(int l=0;l<5;l++) cout<<get(nst,l)<<' ';
                //cout<<'\n';
                cnt[i][nst]=1;
            }
        }
        //cout<<cnt[i].count()<<'\n';
        for(int j=0,dlt;j<=3;j++){
            for(int k=0;k<=9;k++){
                dlt=get(st[i],j+1)-get(st[i],j);
                nst=st[i]-get_num(st[i],j)-get_num(st[i],j+1);
                //cout<<'*'<<dlt;
                dlt=((dlt+k)%10+10)%10;
                //cout<<'*'<<dlt<<'\n';
                nst+=k*p10[j]+dlt*p10[j+1];
                if(nst==st[i]) continue;
                //for(int l=0;l<5;l++) cout<<get(nst,l)<<' ';
                //cout<<'\n';
                cnt[i][nst]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        cnt[1]&=cnt[i];
    }
    cout<<cnt[1].count()<<'\n';
    return 0;
}