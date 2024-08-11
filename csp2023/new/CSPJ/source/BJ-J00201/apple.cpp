#include<fstream>
#include<cmath>
using namespace std;
#define ll long long
ll n;
ll tim,ans;
bool f = 1;
int main()
{
    ifstream inFile("apple.in");
    ofstream outFile("apple.out");
    inFile >> n;
    while(n){
        tim ++;
        if(n % 3 == 1 && f){
            ans = tim;
            f = 0;
        }
        n = n - ceil(n / 3.0);
    }
    outFile << tim << ' ' << ans;
    inFile.close();
    outFile.close();
    return 0;
}
