#include<bits/stdc++.h>
using namespace std;

int n,res = 0;
string str;

int main(){

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin >> n >> str;

    if(n <= 10){
        if(n == 1){
            cout << 0;
            return 0;
        }

        for(int i = 1; i < str.size(); i++){
            if(str[i] == str[i-1]) res++;
        }

        for(int i = 3; i < str.size(); i++){
            if(str[i] == str[i-3] && str[i-1] == str[i-2]) res++;
        }

        for(int i = 5; i < str.size(); i++){
            if(str[i] == str[i-5] && str[i-1] == str[i-4] && str[i-2] == str[i-3]) res++;

        }

        for(int i = 7; i < str.size(); i++){
            if(str[i] == str[i-7] && str[i-1] == str[i-6] && str[i-2] == str[i-5] && str[i-3] == str[i-4]) res++;

        }

        for(int i = 9; i < str.size(); i++){
            if(str[i] == str[i-9] && str[i-1] == str[i-8] && str[i-2] == str[i-7] && str[i-3] == str[i-6] && str[i-4] == str[i-5]) res++;

        }

    }

    cout <<res;


    return 0;
}
