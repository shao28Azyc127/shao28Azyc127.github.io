#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int a[1000];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,a,b,c;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a >> b >> c;
    }for(int i = 1;i<n;i++){
        cin >> a >> b;
    }
    cout<<n+a*b*a;
    return 0;
}
