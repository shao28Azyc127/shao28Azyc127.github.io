#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

ll n,d;

ll a[100010],b[100010];

ll sum;

int main (){

    ifstream inFile ("road.in");

    ofstream outFile ("road.out");

    inFile >> n >> d;

    for (int i = 1;i < n;i++){

        inFile >> a[i];

        sum += a[i];
    }

    for (int i = 1;i <= n;i++){

        inFile >> b[i];
    }

    if (sum % (b[1] * d) == 0){

        outFile << sum / (b[1] * d) << endl;

        return 0;
    }

    outFile << sum / (b[1] * d) + 1 << endl;

    return 0;
}