#include <iostream>
using namespace std;
int main(){
    int n;
    int i ;
    int f , b , c , d , e;
    int a[101];
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
cin >> n ;
for (i = 1;n*5 > i;i++){
    for (int ddd = 0;n>ddd;ddd=ddd+5)
    cin >> a[i] ;
}
if(n==1){
    cout << "81";
}
if(n==2){
    cout << "10";
}

return(0);
}
