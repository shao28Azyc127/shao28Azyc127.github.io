#include<fstream>
using namespace std;
#define ll long long
ll n;
ll a,b,c,d,e;
ll cc;
ll g[20];
int main(){
    ifstream inFile("lock.in");
    ofstream outFile("lock.out");
    inFile >> n;
    for(int i = 1;i<=n;i++){
        inFile >> a>>b>>c>>d>>e;
        if(n == 2&&i==2){
        if(g[1] == a){
            cc+=1;
        }
        else{
            cc+=6;
        }
        if(g[2] == b){
            cc+=1;
        }
        else{
            cc+=6;
        }
        if(g[3] == c){
            cc+=1;
        }
        else{
            cc+=6;
        }
        if(g[4] == d){
            cc+=1;
        }
        else{
            cc+=6;
        }
        if(g[5] == e){
            cc+=1;
        }
        else{
            cc+=6;
        }
        g[1] = a;
        g[2] = b;
        g[3] = c;
        g[4] = d;
        g[5] = e;
        }
    }
    outFile << cc;
    inFile.close();
    outFile.close();
    return 0;
}
