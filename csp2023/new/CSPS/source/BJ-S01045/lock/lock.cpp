#include<bits/stdc++.h>
using namespace std;
int n,a[10],b[10],c[10],d[10],e[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<"81";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
        if(a[i]==0){
            a[i]=10;
        }
        if(b[i]==0){
            b[i]=10;
        }
        if(c[i]==0){
            c[i]=10;
        }
        if(d[i]==0){
            d[i]=10;
        }
        if(e[i]==0){
            e[i]=10;
        }
    }
    if(n==2){
        int cnt[7]={0};
        if(a[2]!=a[1]){
            cnt[1]=1;
        }
        if(b[2]!=b[1]){
            cnt[2]=1;
        }
        if(c[2]!=c[1]){
            cnt[3]=1;
        }
        if(d[2]!=d[1]){
            cnt[4]=1;
        }
        if(e[2]!=e[1]){
            cnt[5]=1;
        }
        if(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]==4){
            cout<<"1";
            return 0;
        }
        else if(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]==1){
            if(cnt[1]==1||cnt[5]==1){
                cout<<"10";
                return 0;
            }
            else{
                cout<<"12";
                return 0;
            }
        }
        else if(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]==2){
            if((cnt[1]==1&&cnt[2]==1)||(cnt[2]==1&&cnt[3]==1)||(cnt[3]==1&&cnt[4]==1)||(cnt[4]==1&&cnt[5]==1)){
                if(abs(a[2]-a[1])==abs(b[2]-b[1])||abs(b[2]-b[1])==abs(c[2]-c[1])||abs(c[2]-c[1])==abs(d[2]-d[1])||abs(d[2]-d[1])==abs(e[2]-e[1])){
                    cout<<"10";
                    return 0;
                }
                else{
                    cout<<"6";
                    return 0;
                }
            }
            else if((cnt[1]==1&&cnt[3]==1)||(cnt[2]==1&&cnt[4]==1)||(cnt[3]==1&&cnt[5]==1)){
                cout<<"3";
                return 0;
            }
            else{
                cout<<"2";
                return 0;
            }
        }
    }
    else{
        int cnt[7]={0};
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]){
                cnt[1]++;
            }
            if(b[i]!=b[i-1]){
                cnt[2]++;
            }
            if(c[i]!=c[i-1]){
                cnt[3]++;
            }
            if(d[i]!=d[i-1]){
                cnt[4]++;
            }
            if(e[i]!=e[i-1]){
                cnt[5]++;
            }
        }
        cout<<50-cnt[1]-cnt[2]-cnt[3]-cnt[4]-cnt[5];
        return 0;
    }
    return 0;
}
