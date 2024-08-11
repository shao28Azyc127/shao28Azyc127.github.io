#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[100];
void dfs(int t,int s){
    if(t>n){
        cnt++;
        return;
    }
    for(int i=1;i<=5;i++){
        int p=pow(10,i-1);
        int x=(s/p)%10;
        for(int j=0;j<=9;j++){
            int ss=s-x*p;
            if(j==x) continue;
            else{
                ss+=(j*p);
                if(ss==a[t]){
                    dfs(t+1,s);
                    return;
                }
            }
        }

    }
    for(int i=1;i<=4;i++){
        int p1=pow(10,i-1);
        int p2=pow(10,i);
        for(int j=1;j<=9;j++){
            int x1=s/p1%10;
            int x2=s/p2%10;
            int ss=s-x1*p1;
            ss-=(x2*p2);
            x1+=j;x2+=j;
            if(x1>9) x1-=10;
            if(x2>9) x2-=10;
            ss+=x1*p1;
            ss+=x2*p2;
            if(ss==a[t]){
                dfs(t+1,s);
                return;
            }
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp=0;
        for(int j=1;j<=5;j++){
            int tx;
            cin>>tx;
            if(j==1) temp+=tx;
            else temp+=pow(10,j-1)*tx;
        }
        a[i]=temp;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    int s1=a[1];
    for(int i=1;i<=5;i++){
        int p=pow(10,i-1);
        int x=(s1/p)%10;
        for(int j=0;j<=9;j++){
            int ss1=s1-x*p;
            if(j==x) continue;
            else{
                ss1+=(j*p);
                dfs(1,ss1);
            }
        }

    }
    for(int i=1;i<=4;i++){
        int p1=pow(10,i-1);
        int p2=pow(10,i);
        for(int j=1;j<=9;j++){
            int x1=s1/p1%10;
            int x2=s1/p2%10;
            int ss1=s1-x1*p1;
            ss1-=(x2*p2);
            x1+=j;x2+=j;
            if(x1>9) x1-=10;
            if(x2>9) x2-=10;
            ss1+=x1*p1;
            ss1+=x2*p2;
            dfs(1,ss1);
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
