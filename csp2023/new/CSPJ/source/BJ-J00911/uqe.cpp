
#include<fstream>
using namespace std;
#define ll long long
ll t,m;
ll a,b,c;
int main(){
    ifstream inFile("uqe.in");
    ofstream outFile("uqe.out");
    inFile >> t >> m;
    for(int i = 1;i<=t;i++){
        inFile >> a >> b >> c;
        if(b*b - 4*a*c < 0){
            outFile <<"NO";
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}
