#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],ans,vis[200];
vector<int>vec[10];
void pb(int x){
    for(int i=1;i<=5;i++){
        for(int j=0;j<=9;j++){
            if(i==1&&j!=a[x][1]){
               int t1=j*10000+a[x][2]*1000+a[x][3]*100+a[x][4]*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==2&&j!=a[x][2]){
               int t1=a[x][1]*10000+j*1000+a[x][3]*100+a[x][4]*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==3&&j!=a[x][3]){
               int t1=a[x][1]*10000+a[x][2]*1000+j*100+a[x][4]*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==4&&j!=a[x][4]){
               int t1=a[x][1]*10000+a[x][2]*1000+a[x][3]*100+j*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==5&&j!=a[x][5]){
               int t1=a[x][1]*10000+a[x][2]*1000+a[x][3]*100+a[x][4]*10+j;
               vec[x].push_back(t1);
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=0;j<=9;j++){
            int k=a[x][i+1]-a[x][i];
            if(i==1&&j!=a[x][1]){
               int w=(j+k)%10;
               int t1=j*10000+w*1000+a[x][3]*100+a[x][4]*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==2&&j!=a[x][2]){
               int w=(j+k)%10;
               int t1=a[x][1]*10000+j*1000+w*100+a[x][4]*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==3&&j!=a[x][3]){
               int w=(j+k)%10;
               int t1=a[x][1]*10000+a[x][2]*1000+j*100+w*10+a[x][5];
               vec[x].push_back(t1);
            }
            if(i==4&&j!=a[x][4]){
               int w=(j+k)%10;
               int t1=a[x][1]*10000+a[x][2]*1000+a[x][3]*100+j*10+w;
               vec[x].push_back(t1);
            }
        }
    }
}
void qc(int x){
    for(int i=0;i<vec[1].size();i++){
        int flag=0;
        for(int j=0;j<vec[x].size();j++){
            if(vis[i]==0){
                break;
            }
            if(vec[1][i]==vec[x][j]){
                flag=1;
            }
        }
        if(flag==0){
            vis[i]=0;
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=90;i++){
        vis[i]=1;
    }
    if(n==1){
       cout<<81;
       return 0;
    }
    else{
       for(int i=1;i<=n;i++){
           pb(i);
       }
       for(int i=2;i<=n;i++){
           qc(i);
       }
    }
    for(int i=0;i<=80;i++){
        if(vis[i]==1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}