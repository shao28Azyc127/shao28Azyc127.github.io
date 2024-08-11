#include<bits/stdc++.h>
using namespace std;

const int N = 10000010;

int vis[N];
int main(){

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    scanf("%d",&n);
    int cnt = n;
    int d = 0;
    bool f  =0;
    int res;

    if(n%3 == 1){
         while(cnt){
            bool flag = 0;
            if(cnt%3 != 0){
                flag = 1;
            }

            int now = cnt/3+flag;
            cnt -= now;

            d++;
       // cout << f << " " <<now<<" "<<cnt <<endl;
        }
        printf("%d %d",d,1);
        return 0;

    }
    while(cnt){
        bool flag = 0;
        if(cnt%3 != 0){
            flag = 1;
        }

        int now = cnt/3+flag;
        cnt -= now;
        if(!f){
            for(int i = 1;i<=n;i++){
                if(!vis[i]){
                    vis[i] = 1;
                    if(i == n){
                        res = d+1;
                        f  = 1;
                    }
                    break;
                }
            }

          //  cout << 1<<endl;
          if(now-1 > 0){
            int num = 0;
            for(int j =1;j<=n;j++){
                if(!vis[j]){
                    if(num == 2){
                        num = -1;
                        vis[j] = 1;
                        if(j == n){
                            f = 1;
                            res = d+1;
                            break;
                        }
                    }
                    num++;
                }
            }

          }



        }
        d++;
       // cout << f << " " <<now<<" "<<cnt <<endl;
    }

    printf("%d %d",d,res);
    return 0;
}
