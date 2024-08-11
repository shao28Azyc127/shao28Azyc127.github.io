#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str[3010];
int maxn[3010];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
        cin>>str[i];
        for (int j = 0;j < m;j++){
            if (int(str[i][j]) > maxn[i]){
                maxn[i] = int(str[i][j]);
            }
        }
    }
    for (int i = 1;i <= n;i++){
        int minx = 21000;
        for (int j = 0;j < m;j++){
            if (int(str[i][j]) < minx){
                minx = int(str[i][j]);
            }
        }
        int flag = 0;
        for (int j = 1;j <= n;j++){
            if (j != i && maxn[j] <= minx){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
