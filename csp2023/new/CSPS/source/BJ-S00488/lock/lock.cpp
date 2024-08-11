#include <bits/stdc++.h>

using namespace std;
map <int,int> m;
int gai[10],ans[10],wei[10],anss;
int n;
int gett(int now,int www){
    return (ans[now]%wei[www]-ans[now]%wei[www-1])/wei[www-1];
}
void change(int now,int www,int zhi){
    memset(gai,0,sizeof(gai));
    int ct=0,k=ans[now];
    int h=0;
    for(int i=1;i<=5;i++){
        gai[++ct]=k%10,k/=10;
        if(ct==www) gai[ct]=zhi;
    }
    for(int i=ct;i>=1;i--){
        h=h*10+gai[i];
    }
    //cout<<h<<'\n';
    if(m[h]==-1)return;
    m[h]++;
    if(m[h]==n)anss++;
}
void change2(int now,int www,int zhi,int zzz,int zhi2){
    memset(gai,0,sizeof(gai));
    int ct=0,k=ans[now];
    int h=0;
    for(int i=1;i<=5;i++){
        gai[++ct]=k%10,k/=10;
        if(ct==www) gai[ct]=zhi;
        if(ct=zzz) gai[ct]=zhi2;
    }
    for(int i=ct;i>=1;i--){
        h=h*10+gai[i];
    }//cout<<h<<'\n';
    if(m[h]==-1)return;
    m[h]++;
    if(m[h]==n)anss++;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a;
    cin>>n;
    wei[0]=1;
    wei[1]=10;
    wei[2]=100;
    wei[3]=1000;
    wei[4]=10000;
    wei[5]=10000;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=5;j++){
        cin>>a;
        ans[i]=a+ans[i]*10;
    }
    for(int i=1;i<=n;i++){
        m[ans[i]]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            int qqq=gett(i,j);
           // cout<<qqq<<'\n';
            for(int z=0;z<=9;z++){
                if(z!=qqq){change(i,j,z);}
            }
        }
        for(int j=1;j<=4;j++){
            int qqq=gett(i,j);
            int kkk=gett(i,j+1);
            for(int z=1;z<=9;z++){
                change2(i,j,(z+qqq)%10,j+1,(z+kkk)%10);
            }
        }
    }
    cout<<anss;
    return 0;
}
