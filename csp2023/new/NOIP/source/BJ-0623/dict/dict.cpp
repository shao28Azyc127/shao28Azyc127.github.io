#include<bits/stdc++.h>
using namespace std;

bool cmpMax(char a, char b){
    return a < b;
}

bool cmpMin(char a, char b){
    return b < a;
}

int main(){

    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    char diction[n][m];
    char maximumDict[n][m], minimumDict[n][m];
    char ans[n];
    char flag;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> diction[i][j];
            maximumDict[i][j] = diction[i][j];
            minimumDict[i][j] = diction[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        sort(maximumDict[i], maximumDict[i]+m, cmpMax);
        sort(minimumDict[i], minimumDict[i]+m, cmpMin);
    }

    for(int i = 0; i < n; i++){
        flag = '1';
        for(int j = 0; j < n; j++){
            if(i != j){
                for(int k = 0; k < m; k++){
                    if(maximumDict[i][k] < minimumDict[j][k]) break;
                    else if(maximumDict[i][k] > minimumDict[j][k]){
                        flag = '0';
                        break;
                    }
                }
                if(flag == '0') break;
            }
        }
        ans[i] = flag;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i];
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}