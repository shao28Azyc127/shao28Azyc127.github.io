#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[10][10];
bool isok(int i,int j,int k,int u,int w){
    int dif,p[5],cha[5];
    for(int x=1;x<=n;x++){
        dif=0;
        if(a[x][1]!=i)dif++,p[dif]=1,cha[dif]=(a[x][1]-i+10)%10;
        if(a[x][2]!=j)dif++,p[dif]=2,cha[dif]=(a[x][2]-j+10)%10;
        if(a[x][3]!=k)dif++,p[dif]=3,cha[dif]=(a[x][3]-k+10)%10;
        if(a[x][4]!=u)dif++,p[dif]=4,cha[dif]=(a[x][4]-u+10)%10;
        if(a[x][5]!=w)dif++,p[dif]=5,cha[dif]=(a[x][5]-w+10)%10;
        if(dif==1)continue;
        else if(dif==2&&abs(p[1]-p[2])==1&&cha[1]==cha[2])continue;
        else return false;
    }
    return true;
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
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int u=0;u<=9;u++){
                    for(int w=0;w<=9;w++){
                        if(isok(i,j,k,u,w)){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
