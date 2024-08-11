#include<fstream>
#include<algorithm>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
ll sum;
ll n,d;
ll x;
int main()
{
    ifstream inFile("road.in");
    ofstream outFile("road.out");
    inFile >>n >>d;
    for(int i = 1;i <= n;i ++){
        inFile >> x;
        sum += x;
    }
    inFile >>x;
    outFile <<sum * x;
    inFile.close();
    outFile.close();
    return 0;
}
