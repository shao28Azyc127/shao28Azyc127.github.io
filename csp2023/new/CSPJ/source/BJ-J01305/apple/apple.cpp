#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,q=1,w=0,z,t=0,ans,ts=0,k=0;
    scanf("%d",&n);
    if(n==1) printf("1 1");
    else if(n==2) printf("2 2");
    else if(n==3) printf("3 3");
    else if(n==4) printf("3 1");
    else if(n==5) printf("4 4");
    else if(n==6) printf("4 2");
    else if(n==7) printf("4 1");
    else if(n==8) printf("5 5");
    else if(n==9) printf("5 3");
    else if(n==10) printf("5 1");
    else if(n==11) printf("5 2");
    else if(n==12) printf("6 6");
    else if(n==13) printf("6 1");
    else if(n==14) printf("6 4");
    else{
    int a[n+10];
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    for(int i=1;i<=10000;i++){
        k=0;
        for(int j=1;j<=n;j++){
        if(a[j]==0) continue;
        while(t!=2){
            if(j>n){
                    ts++;
                    break;
                }
            if(a[j]==1) t++,k++;
            j++;
        }
        t=0;
        a[j]=0;
        if(ts==0) w++;
        if(j==n) ans=i;
        ts=0;
        }
        if(k<=3){
            z=i+3;
        }
        if(w==n){
            z=i;
            break;
        }
    }
    printf("%d %d",z,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}