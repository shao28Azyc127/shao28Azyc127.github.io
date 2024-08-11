#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e5 + 10;

int v[SIZE],a[SIZE];

int main(){

    ifstream fin ("road.in");
    ofstream fout ("road.out");
    
    int n,d,sum = 0;

    fin >> n >> d;

    for(int i = 0;i < n - 1;i++){
        fin >> v[i];
        sum += v[i];
    }

    for(int i = 0;i < n;i++){
        fin >> a[i];
    }

    fout << ceil(1.0 * sum / d) * a[0] << endl;

    fin.close();
    fout.close();

    return 0;
}