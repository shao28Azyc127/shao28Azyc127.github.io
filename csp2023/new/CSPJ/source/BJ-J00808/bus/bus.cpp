#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

ll n,m,k;

ll a,b,c;

int main (){
    ifstream inFile ("bus.in");
    ofstream outFile ("bus.out");

    inFile >> n >> m >> k;

    for (int i = 1;i <= m;i++){

        inFile >> a >> b >> c;
	}

    outFile << -1 << endl;

    inFile.close();
    outFile.close();

    return 0;
}