#include <iostream>
#include <cstdio>
using namespace std;
int b[300000],c[200000];
int main(){
    int a;
    cin >> a;
    for(long long i = 0;  i  <  a * 3;  i++){
        cin >> b[i];
    }
    for(long long i = 0;  i  <  a * 2;  i++){
        cin >> c[i];
    }
    cout << a + 1;
    return 0;
}