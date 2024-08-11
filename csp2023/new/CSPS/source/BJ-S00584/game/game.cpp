#include <iostream>
using namespace std;
#define ll long long
ll n;
string s;
int main(){
    ifstream inFile ("game.in");
    ofstream outFile("game.out");
    inFile >> n;
    inFile >> s;
    for (int i = 1;i <= n;i++){
        if (s[i] != "a" && s[i] != "b"){
            cnt++;
        }
    }
    if (cnt == 0){
        outFile << s.size() / 2;
    }
    inFile.close();
    outFile.close();
    return 0;
}