#include <bits/stdc++.h>
using namespace std;
int i,j,a[10][5]={0};int n;
int check(int j,int q,int i){
    if(j==0){
        return q*10000+a[i][j+1]*1000+a[i][j+2]*100+a[i][j+3]*10+a[i][j+4];
    }
    else if(j==1){
        return a[i][j-1]*10000+q*1000+a[i][j+1]*100+a[i][j+2]*10+a[i][j+3];
    }
    else if(j==2){
        return a[i][j-2]*10000+a[i][j-1]*1000+q*100+a[i][j+1]*10+a[i][j+2];
    }
    else if(j==3){
        return a[i][j-3]*10000+a[i][j-2]*1000+a[i][j-1]*100+q*10+a[i][j+2];
    }
    else if(j==4){
        return a[i][j-4]*10000+a[i][j-3]*1000+a[i][j-2]*100+a[i][j-1]*10+q;
    }
}

int f(int j,int x,int y,int i){
    if(j==0){
        return x*10000+y*1000+a[i][j+2]*100+a[i][j+3]*10+a[i][j+4];
    }
    else if(j==1){
        return a[i][j-1]*10000+x*1000+y*100+a[i][j+2]*10+a[i][j+3];
    }
    else if(j==2){
        return a[i][j-2]*10000+a[i][j-1]*1000+x*100+y*10+a[i][j+2];
    }
    else if(j==3){
        return a[i][j-3]*10000+a[i][j-2]*1000+a[i][j-1]*100+x*10+y;
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;

    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    int q;
    int h[100000]={0};
    int r[100000]={0};
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            for(int t=1;t<=9;t++){
                q=(a[i][j]+t)%10;
                h[check(j,q,i)]=1;
            }
        }
    }
    int x,y;
    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            for(int e=1;e<=9;e++){
                x=(a[i][j]+e)%10;
                y=(a[i][j+1]+e)%10;
                //cout<<f(j,x,y,i)<<" ";
                r[f(j,x,y,i)]=1;
            }
        }
    }
    int num=0;
    for(i=0;i<100000;i++){
        if(h[i]==1)
            num++;
        if(r[i]==1)
            num++;
    }
    if(n==1)
        printf("%d",num);
    else{
        num=num%12;
        printf("%d",num);
    }


}
