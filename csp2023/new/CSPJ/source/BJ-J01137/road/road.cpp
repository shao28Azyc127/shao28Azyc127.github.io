#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100010],b[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int cost=0,sheng=0;
    for(int i=1;i<n;i++){
            int ypj=a[i];
            if(sheng>=a[i]){
                sheng-=a[i];
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(b[j]>=b[i]){
                ypj+=a[j];
            }
            else{
                break;
            }
        }
        int ss=-1;

        if((ypj-sheng)%m==0){
            ss=(ypj-sheng)/m;
        }
        else{
            ss=(ypj-sheng)/m+1;
        }
        if(ss!=-1&&ypj>sheng){
        cost+=b[i]*ss;
        sheng+=ss*m;
        }
        sheng-=a[i];
    }
    cout<<cost;
    return 0;
}
