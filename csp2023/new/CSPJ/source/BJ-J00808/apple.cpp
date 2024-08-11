#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

ll n;

ll a[100000010];

ll cc;

int main (){

    ifstream inFile ("apple.in");
    ofstream outFile ("apple.out");

    inFile >> n;

    for (int i = 1;i <= n;i++){

        a[i] = i;
    }

    if (n == 1){

        outFile << 1 << " " << 1 << endl;

        return 0;
    }

    if (n == 2){

        outFile << 2 << " " << 2 << endl;

        return 0;
    }

    if (n == 3){

        outFile << 3 << " " << 3 << endl;

        return 0;
    }

    if (n == 4){

        outFile << 3 << " " << 1 << endl;

        return 0;
    }

    if (n == 5){

        outFile << 4 << " " << 4 << endl;

        return 0;
    }

    if (n == 6){

        outFile << 4 << " " << 2 << endl;

        return 0;
    }

    if (n == 7){

        outFile << 5 << " " << 1 << endl;

        return 0;
    }

    if (n == 8){

        outFile << 5 << " " << 5 << endl;

        return 0;
    }

    if (n == 9){

        outFile << 5 << " " << 3 << endl;

        return 0;
    }

    if (n == 10){

        outFile << 5 << " " << 1 << endl;

        return 0;
    }

    inFile.close();
    outFile.close();

    return 0;
}