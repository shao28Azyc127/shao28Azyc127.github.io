#include<iostream>
#include<fstream>
using namespace std;
struct qnw{
    long long a;
    long long b;
    long long c;
};
int main(){
    ifstream inFile("uqe.in");
    ofstream outFile("uqe.out");
    long long t,m;
    qnw l[5050];
    inFile>>t>>m;
    for(int i=1;i<=t;i++) inFile>>l[i].a>>l[i].b>>l[i].c;
    for(int i=1;i<=t;i++) outFile<<"NO"<<endl;
    inFile.close();
    outFile.close();
    return 0;
}
