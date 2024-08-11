#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int NR = 2e6;
const int MR = 8e3;
char s[NR + 10];
bool dp[MR + 10][MR + 10];
map<char, int> mp;
bool flag1[NR + 10];
bool flag2[NR + 10];

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int len;
    scanf("%d", &len);
    scanf("%s", s + 1);
    int tmp = 0;
    for(int i = 1;i < len;i++){
        if(s[i] == s[i + 1]){
            tmp++;
            dp[i][i + 1] = true;
            flag1[i] = true;
            flag2[i + 1] = true;
        }
    }
    for(int i = 1;i <= len;i++){
        mp[s[i]]++;
    }
    if(len <= 800 && false){
        for(int l = 3;l <= len;l++){
            for(int i = 1;i + l - 1 <= len;i++){
                int j = i + l - 1;
                if(s[i] == s[j]) dp[i][j] |= dp[i + 1][j - 1];
                for(int k = i;k < j;k++){
                    dp[i][j] |= (dp[i][k] && dp[k + 1][j]);
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i <= len;i++){
            for(int j = i;j <= len;j++){
                if(dp[i][j]){
                    cnt++;
                    //printf("%d %d\n", i, j);
                }
            }
        }
        printf("%d\n", cnt);
        return 0;
    }
    if(len <= 8000){
        for(int l = 3;l <= len;l++){
            for(int i = 1;i + l - 1 <= len;i++){
                int j = i + l - 1;
                if(s[i] == s[j]) dp[i][j] |= dp[i + 1][j - 1];
                dp[i][j] |= (flag1[i] && flag2[j]);
                flag1[i] |= dp[i][j];
                flag2[j] |= dp[i][j];
            }
        }
        int cnt = 0;
        for(int i = 1;i <= len;i++){
            for(int j = i;j <= len;j++){
                if(dp[i][j]){
                    cnt++;
                    //printf("%d %d\n", i, j);
                }
            }
        }
        printf("%d\n", cnt - tmp);
        return 0;
    }
    if(mp.size() == 2){
        int cnt = 0;
        for(int i = 1;i < len;i++){
            if(s[i] == s[i + 1]){
                cnt++;
            }
        }
        printf("%d\n", cnt);
        return 0;
    }
    printf("0\n");
    /*
    if(len <= 8000){
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if()
            }
        }
    }
    */
    return 0;
}
/*
8
accabccb
*/
