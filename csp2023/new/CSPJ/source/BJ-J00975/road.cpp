#include<iostream>
#include<fstream>
using namespace std;
struct qnw{
	long long v;
	long long a;
};
int main(){
    ifstream inFile("road.in");
    ofstream outFile("road.out");
    long long n,d,k=0;
    qnw l[100010];
    inFile>>n>>d;
    for(int i=1;i<=n-1;i++) inFile>>a[i].v;
    for(int i=1;i<=n;i++) inFile>>a[i].a;
    for(int i=1;i<=n-1;i++) k+=a[i].v;
    outFile<<(k/d)*a[1]<<endl;
    inFile.close();
    outFile.close();
    return 0;
}
