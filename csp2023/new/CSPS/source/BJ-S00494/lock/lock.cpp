#include <bits/stdc++.h>
using namespace std;
int n,a[10][10];
long long s;
bool comp(int x[10],int y[10]){
    int dif=0,xx,yy;
    for(int i=1;i<=5;i++){
        if(x[i]!=y[i]){
            dif++;
            if(dif==1){
                xx=i;
            }
            if(dif==2){
                yy=i;
            }
        }
    }
    if(dif>2||dif==0){
        return false;
    }
    if(dif==1){
        return true;
    }
    if(!(yy-xx==1)){
        return false;
    }
    for(int i=1;i<=9;i++){
        if((x[xx]+i)%10==y[xx]&&(x[yy]+i)%10==y[yy]){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        bool flag=true;
                        int arr[10]={0,i,j,k,l,m};
                        for(int i=1;i<=n;i++){
                            if(!comp(arr,a[i])){
                                flag=false;
                            }
                        }
                        if(flag){
                            s++;
                        }
                    }
                }
            }
        }
    }
    cout<<s;
    return 0;
}
