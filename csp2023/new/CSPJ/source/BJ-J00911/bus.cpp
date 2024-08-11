#include<fstream>
using namespace std;
#define ll long long
ll n,m,k;
ll a,b,c;
ll cc;
ll d[1010];
ll e[1010];
ll f[1010];
ll sum;
int main(){
    ifstream inFile("bus.in");
    ofstream outFile("bus.out");
    inFile >> n >> m >> k;
    for(int i = 1;i<=m;i++){
        inFile >> a >> b >> c;
        d[i] = a;
        e[i] = b;
        f[i] = c;
    }
    for(int i = 1;i<=m;i++){
        for(int j = i + 1;j<=m;j++){
            if(e[i] == d[j]){
                cc++;
                sum = j;
            }
            if(d[sum] == e[i]){
                cc++;
            }
        }
        cc += min(f[i],f[i+1]);
    }
    if(cc = 0){
            outFile << -1;
        }
    outFile << cc;
    inFile.close();
    outFile.close();
    return 0;
}
