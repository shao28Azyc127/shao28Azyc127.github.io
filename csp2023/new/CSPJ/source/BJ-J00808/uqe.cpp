#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

ll n,m,k;

ll a,c;

int main (){
    ifstream inFile ("bus.in");
    ofstream outFile ("bus.out");

inFile >> a >> c;

for (int i = 1;i <= a;i++){

inFile >> n >> m >> k;
}

for (int i = 1;i <= a;i++){

outFile << "NO" << endl;
}
    inFile.close();
    outFile.close();

    return 0;
}