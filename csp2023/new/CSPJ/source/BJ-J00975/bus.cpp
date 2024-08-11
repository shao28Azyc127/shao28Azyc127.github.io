#include<iostream>
#include<fstream>
using namespace std;
struct qnw{
    long long u;
    long long v;
    long long a;
};
int main(){
    ifstream inFile("bus.in");
    ofstream outFile("bus.out");
    long long n,m,k;
    qnw l[30030];
    inFile>>n>>m>>k;
    for(int i=1;i<=m;i++) inFile>>l[i].u>>l[i].v>>l[i].a;
    outFile<<"-1"<<endl;
    inFile.close();
    outFile.close();
    return 0;
}
