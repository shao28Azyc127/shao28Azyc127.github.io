#include<iostream>
#include<cstdio>
using namespace std;
int cnt[10][10];
int n;
bool member_diff(int a,int b,int c,int d,int e,int i){
    int ans=0;
    int f[10];
    int v[10];
    if(a!=cnt[i][1]){
        f[ans]=1;
        v[ans]=(a-cnt[i][1]+10)%10;
        ans++;
    }
    if(b!=cnt[i][2]){
        f[ans]=2;
        v[ans]=(b-cnt[i][2]+10)%10;
        ans++;
    }
    if(c!=cnt[i][3]){
        f[ans]=3;
        v[ans]=(c-cnt[i][3]+10)%10;
        ans++;
    }
    if(d!=cnt[i][4]){
        f[ans]=4;
        v[ans]=(d-cnt[i][4]+10)%10;
        ans++;
    }
    if(e!=cnt[i][5]){
        f[ans]=5;
        v[ans]=(e-cnt[i][5]+10)%10;
        ans++;
    }
    if(ans>2||ans==0){
        return false;
    }
    if(ans==1){
        return true;
    }
    if(f[0]==f[1]-1&&v[0]==v[1]){
        return true;
    }
    return false;
}
bool check(int a,int b,int c,int d,int e){
    bool vis=true;
    for(int i=1;i<=n;i++){
        if(!member_diff(a,b,c,d,e,i)){
            vis=false;
            break;
        }
    }
    if(vis){
        return true;
    }
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>cnt[i][j];
        }
    }
    int ans=0;
    for(int a=0;a<=9;a++)
        for(int b=0;b<=9;b++)
            for(int c=0;c<=9;c++)
                for(int d=0;d<=9;d++)
                    for(int e=0;e<=9;e++)
                        if(check(a,b,c,d,e)){
                            ans++;
                          }
    cout<<ans;
    return 0;
}
