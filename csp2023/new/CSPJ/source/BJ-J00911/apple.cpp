#include<fstream>
using namespace std;
#define ll long long
ll n;
ll cc;
ll sum;
int main(){
    ifstream inFile("apple.in");
    ofstream outFile("apple.out");
    inFile >> n;
    if(n == 1){
        outFile << 1 <<" "<<1;
        return 0;
    }
    ll a = n;
    while(n > 0){
            ll num = 0;
        for(int i = 1;i<=n;i+3){
            num++;
        }
        n -= num;
        cc++;
        if(n + 3 == a){
            sum = cc;
        }
        if(a <= 3){
            sum = a;
        }
    }
    outFile << cc<<" "<<sum;
    inFile.close();
    outFile.close();
    return 0;
}
