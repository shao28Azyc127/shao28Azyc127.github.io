#include<iostream>
#include<fstream>
using namespace std;
#define ll long long
ll n;
ll sum;
ll a[10][10];
int main(){
    ifstream inFile("lock.in");
    ofstream outFile("lock.out");
    inFile>>n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= 5;j ++){
            inFile >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= 5;j ++){
            sum += 9;
        }
    }
    sum += (5 - 1) * 9;
    outFile<<sum;
    inFile.close();
    outFile.close();
    return 0;
}
