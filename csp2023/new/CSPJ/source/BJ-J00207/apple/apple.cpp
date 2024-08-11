#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 10;
bool a[maxn];
int n;
void print(){
    for(int i = 0;i < n;i++){
        cout << (int)a[i] << " ";
    }
    cout << endl;
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin.sync_with_stdio(false);
    int ans;int ans2;
    cin >> n;
    int j = 0;
    for(int i = 0;i < n;i++){
        a[i] = false;
    }
    bool make = false;bool make2 = false;
    do{
        make = false;
        j++;
        int i = 0;
        for(int k = 0;k < n;k++){
            if(!a[k]){
                if(i == 0){
                    a[k] = true;
                    make = true;
                }
                i++;
            }
            if(i == 3){
                i = 0;
            }
        }
        if(!make2 && a[n - 1] == true){
            make2 = true;
            ans2 = j;
        }
    }while(make);
    cout << j - 1 << " " << ans2 << endl;
    return 0;
}
