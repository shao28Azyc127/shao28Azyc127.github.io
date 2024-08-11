#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int len;
string str;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>len>>str;
    int ans = 0;
    for(int i = 0; i < len-1; i++){
        if(str[i] == str[i+1]){
            ans++;
        }
    }
    for(int i = 0; i < len-3; i++){
        if(str[i] == str[i+1] && str[i+2] == str[i+3]){
            ans++;
        }
        if(str[i] == str[i+3] && str[i+2] == str[i+1]){
            ans++;
        }
    }
    for(int i = 0; i < len-5; i++){
        if(str[i] == str[i+1] && str[i+2] == str[i+3] && str[i+4] == str[i+5]){
            ans++;
        }
        if(str[i] == str[i+3] && str[i+2] == str[i+1] && str[i+4] == str[i+5]){
            ans++;
        }
        if(str[i] == str[i+1] && str[i+2] == str[i+5] && str[i+3] == str[i+4]){
            ans++;
        }
        if(str[i] == str[i+5] && str[i+2] == str[i+3] && str[i+1] == str[i+4]){
            ans++;
        }
        if(str[i] == str[i+5] && str[i+2] == str[i+1] && str[i+3] == str[i+4]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
