#include<bits/stdc++.h>
using namespace std;
int n,j=1,x;
bool p=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int l=0;
    for(j=1;n;j++){
        for (int i=1;i<=n;i+=3){
            l++;
            if (i == n && p){
                x = j;
                p=0;
            }
        }
        n-=l;
        l=0;
    }
    cout << j-1 << " " << x;
    return 0;
}