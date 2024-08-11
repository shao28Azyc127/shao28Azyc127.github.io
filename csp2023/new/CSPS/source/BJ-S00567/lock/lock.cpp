#include<iostream>
using namespace std;

int a[10][10];
int s[10];
int f[10];



int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin>>n;
    if(n==1) {
        cout<<81<<endl;
        return 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=5; j++){
            cin>>a[i][j];
        }
    }


    for(int i = n;i>0; i--){
        for(int j = 1; j<=5; j++){
            a[i][j]-=a[1][j];
            if(a[i][j]<0) a[i][j]+=10;
        }
    }

    int ans = 0;
    for(int i = 1; i<=5; i++)
    for(int j = 1; j<=9; j++){
        a[1][i] = j;
        bool ok = true;
        for(int k = 2; k<=n; k++){
            int flag = 0;
            for(int t = 1; t<=5; t++){
                if(a[1][t] == a[k][t] or a[1][t]-10 == a[k][t]) continue;
                if(!flag){
                    flag = t;
                    continue;
                }

                if(flag == t-1&&(a[1][t-1]-a[k][t-1]+10)%10 == (a[1][t]-a[k][t]+10)%10) continue;
                ok = false;
                //printf("A %d %d %d %d\n", i, j, k, t);

                break;
            }
            if(!ok) break;
        }
        if(ok) {ans ++;
        //printf("CCC %d %d\n", i , j );
        };
        a[1][i] = 0;
    }

    for(int i = 1; i<=4; i++)
    for(int j = 1; j<=9; j++){
        a[1][i] = a[1][i+1] = j;
        bool ok = true;
        for(int k = 2; k<=n; k++){
            int flag = 0;
            for(int t = 1; t<=5; t++){
                if(a[1][t] == a[k][t]) continue;
                if(!flag){
                    flag = t;
                    continue;
                }

                if(flag == t-1) continue;
                //printf("B %d %d %d %d\n", i, j, k, t);
                ok = false;
                break;
            }
            if(!ok) break;
        }
        if(ok) {ans ++;
        //printf("CCC %d %d\n", i , j );
        };
    }
    cout<<ans<<endl;
}
