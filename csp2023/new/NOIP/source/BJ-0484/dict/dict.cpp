#include<bits/stdc++.h>
using namespace std;
//11.18 NOIP
//t1
//qianmian tepan
//houmian bidaxiao
struct node{
    int num;
    int wei;
}minn;
const long long N=100000007;
int cnt1,cnt2,cnt;
long long n,m,flag,tong[3005][30],yuan[3005],hou[3005],now;
int tu[1005][1005];
string s[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    minn.num=1e9+7;
    minn.wei=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==1&&m==1){
       cout<<1;
    }
    else if(n<=26&&m==1){
        for(int i=1;i<=n;i++){
            flag=1;
            for(int j=1;j<=n;j++){
                if(((int)(s[i][0]))>((int)(s[j][0]))){//douyaoxiao
                   flag=0;
                }
            }
            if(flag==1){
                 cout<<1;
            }
            else{
                 cout<<0;
            }
        }
    }
    //0kaishi
    else if(n<=15&&m==2){
        for(int i=1;i<=n;i++){
            flag=1;
            cnt1=((int)(s[i][1]-'a'+1))*100+((int)(s[i][0]-'a'+1));
            cnt2=((int)(s[i][0]-'a'+1))*100+((int)(s[i][1]-'a'+1));
            cnt=min(cnt1,cnt2);
            for(int j=1;j<=n;j++){
                if(cnt>=((int)(s[j][0]-'a'+1))*100+((int)(s[j][1]-'a'+1))&&j!=i){
                   flag=0;
                }
            }
            if(flag==1){
                 cout<<1;
            }
            else{
                 cout<<0;
            }
        }
    }
    else if(n<=300){
        for(int i=1;i<=n;i++){
            for(int j=m-1;j>=0;j--){
            long long t=((int)(s[i][j]-'a'+1));
            tong[i][t]++;
            }
            int t=1;
            for(int j=1;j<=26;j++){
                for(int k=1;k<=tong[i][j];k++){
                    tu[i][t]=j;
                    t++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            flag=1;
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                for(int k=1;k<=m;k++){
                    //cout<<tu[i][k]<<" "<<((int)(s[j][k-1]-'a'+1))<<endl;
                    if(tu[i][k]<((int)(s[j][k-1]-'a'+1))){
                        break;
                    }
                    if(tu[i][k]>((int)(s[j][k-1]-'a'+1))){
                        flag=0;
                        break;
                    }
                }
                if(flag==0){
                    break;
                }
            }
            cout<<flag;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            long long k=131;
            for(int j=m-1;j>=0;j--){
            long long t=((int)(s[i][j]-'a'+1));
                yuan[i]+=t*k;
                yuan[i]%=N;
                tong[i][t]++;
                k=(k*131)%N;
            }
            if(yuan[i]<minn.num){
                minn.wei=i;
                minn.num=yuan[i];
            }
            k=1;
            now=26;
                for(int w=tong[i][now];w>=0;w--){
                    while(w==0&&now>0){
                          now--;
                          w=tong[i][now];
                    }
                    k=(k*131)%N;
                    hou[i]+=k*now;
                    hou[i]%=N;
                    if(now==0){
                        break;
                    }
                }
        }
        for(int i=1;i<=n;i++){
            if(hou[i]<minn.num||(hou[i]==minn.num&&i==minn.wei)){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    return 0;
}
