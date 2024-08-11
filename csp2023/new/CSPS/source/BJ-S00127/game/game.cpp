#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
long long sum = 0;
string str;
long long dptable[8100][8100];

void dfs(long long st,long long et){
    if (dptable[st][et] == 1){
        return;
    }
    if (st >= 1 && et < str.size()-1 && str[st-1] == str[et+1]){
        dfs(st-1,et+1);
    }
    for (long long i = 0;i <= st-1;i++){
        if (dptable[i][st-1] == 1){
            dfs(i,et);
        }
    }
    sum++;
    dptable[st][et] = 1;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n;
    cin>>n>>str;
    for (long long i = 0;i < str.size();i++){
        if (str[i] == str[i+1]){
            dfs(i,i+1);
        }
    }
    cout<<sum<<endl;
    return 0;
}
