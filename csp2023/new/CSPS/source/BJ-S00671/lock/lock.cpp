#include <bits/stdc++.h>
#define MAXN 1000
#define ll long long
#define db double
#define P 1000000007

using namespace std;

int n;
int a;
int vis[100005];
int cnt;
int p10[10]={0,10000,1000,100,10,1,1};

int add(int x,int y,int k){
    int x1=(x/p10[k])%10;
    int ans=(x1+y)%10;
    return x-x1*p10[k]+ans*p10[k];
}

int main(){

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        a=0;
        for(int j=1;j<=5;j++){
            int x;
            cin>>x;
            a=10*a+x;
        }
        for(int j=1;j<=5;j++){
            for(int k=1;k<=9;k++){
                int temp=add(a,k,j);
                vis[temp]++;
                if(vis[temp]==n) cnt++;
            }
            if(j!=5){
                for(int k=1;k<=9;k++){
                    int temp=add(a,k,j);
                    temp=add(temp,k,j+1);
                    vis[temp]++;
                    if(vis[temp]==n) cnt++;
                }
            }

        }
    }
    cout<<cnt<<endl;

    return 0;
}
