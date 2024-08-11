#include<bits/stdc++.h>
using namespace std;
int num[10][7];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,ans = 0;
    memset(num,0,sizeof(num));
    cin >> n;
    for(int i = 0;i < n;i++)for(int j = 1;j <= 5;j++)cin >> num[i][j];
    for(int i = 1;i <= 5;i++){
        for(int j = 0;j <= 9;j++){
            if(num[0][i] == j)continue;
            int ret = num[0][i];
            num[0][i] = j;
            bool able = true;
            for(int k = 1;k < n;k++){
                int lst = -1;
                for(int l = 1;l <= 5;l++){
                    if(num[k][l] != num[0][l]){
                        if(lst != -1 && lst != l-1){
                            able = false;
                            break;
                        }
                        if(lst != -1 && lst == l-1){
                            if((num[k][l-1]+10-num[0][l-1])%10 != (num[k][l]+10-num[0][l])%10){
                                able = false;
                                break;
                            }
                        }
                        else lst = l;
                    }
                }
                if(lst == -1)able = false;
                if(able == false)break;
            }
            if(able){
                // for(int k = 1;k <= 5;k++)cout << num[0][k] << " ";
                // cout << endl;
                ans++;
            }
            num[0][i] = ret;
        }
    }
    for(int i = 1;i < 5;i++){
        for(int j = 1;j <= 9;j++){
            int ret = num[0][i],ret2 = num[0][i+1];
            num[0][i] = (num[0][i]+j)%10;
            num[0][i+1] = (num[0][i+1]+j)%10;
            bool able = true;
            for(int k = 1;k < n;k++){
                int lst = -1;
                for(int l = 1;l <= 5;l++){
                    if(num[k][l] != num[0][l]){
                        if(lst != -1 && lst != l-1){
                            able = false;
                            break;
                        }
                        if(lst != -1 && lst == l-1){
                            if((num[k][l-1]+10-num[0][l-1])%10 != (num[k][l]+10-num[0][l])%10){
                                able = false;
                                break;
                            }
                        }
                        else lst = l;
                    }
                }
                if(lst == -1)able = false;
                if(able == false)break;
            }
            if(able){
                // for(int k = 1;k <= 5;k++)cout << num[0][k] << " ";
                // cout << endl;
                ans++;
            }
            num[0][i] = ret,num[0][i+1] = ret2;
        }
    }
    cout << ans << endl;
    return 0;
}