#include<iostream>
#include<cstdio>
using namespace std;

int n, cnt;
int ans, res;
bool flag;
bool vis[1000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);
    cnt=n;
    int  t=0;
    while(cnt>0){
        ans++;
        flag = false;
        for(int i = 1; i <= n; i++){
            if(!vis[i]) t++;
            if(!vis[i]&&(!flag||t==3)){
                t=0;
                flag=true;
                vis[i]=true;
                cnt--;
                if(i==n){
                    res=ans;
                }
            }
        }
    }
    printf("%d %d", ans, res);

    //1 4 7 10 13 16 19 22 25 28 31 34 37 40 43 46 49 52
    //2 6 11 15 20 24 29 33 38 42 47
    //3 9 17 23 30 36 44
    //5 14 26 35 45
    //8 21 39
    //12 32
    //18 48
    //27

    return 0;
}
