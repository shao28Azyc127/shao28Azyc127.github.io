#include<cstdio>
#include<iostream>
using namespace std;
int n, ans, len, d, lengh[100005], price[100005], you, anss;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1;i <= n-1;i++){
        cin >> lengh[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> price[i];
    }
    price[n] = 0;
    for(int i = 1;i <= n-1;){
        int o, ans = 0;
        for(int j = i+1;j <= n;j++){
            if(price[j] < price[i]){
                o = j;
                ans += lengh[j-1];
                break;
            }
            else{
                ans += lengh[j-1];
            }
        }
        if((ans - you) % d == 0){
            anss += ((ans - you) / d * price[i]);
            you = 0;
        }
        else{
            int ansss = (ans - you) / d + 1;
            you = ansss * d - ans + you;
            anss += ansss * price[i];
        }
        i = o;
        //cout << o << " " << anss << endl;
    }
    cout << anss;
    return 0;
}

