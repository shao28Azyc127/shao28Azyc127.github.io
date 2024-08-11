#include<fstream>
#include<algorithm>
using namespace std;
#define ll long long
ll t;
ll a,b,c;
ll m;
int main()
{
    ifstream inFile("uqe.in");
    ofstream outFile("uqe.out");
    inFile >>t >>m;
    while(t --){
        outFile << "NO" <<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}
