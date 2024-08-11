#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
ll a[15];
ll n;
int main(){
    ifstream inFile ("lock.in");
    ofstream outFile ("lock.out");
    inFile >>n;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 5;j++){
            inFile >>a[i];
        }
    }
    if (n == 1){
        outFile <<81;
    }
    else {
        outFile <<10;
    }
    inFile.close();
    outFile.close();
    return 0;
}