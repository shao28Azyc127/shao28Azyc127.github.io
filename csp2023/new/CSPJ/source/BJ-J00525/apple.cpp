#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int nget = 0,yn = n,all = 0;
    for(int i=1;;i++){
        if((yn-1)%3 == 0){
            if(nget == 0)   nget = i;
        }
        yn -= ((yn - 1) / 3 + 1);
        if(yn == 0){
            all = i;
            break;
        }
    }
    cout << all << ' ' << nget;
    return 0;
}
