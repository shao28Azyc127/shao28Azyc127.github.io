#include<fstream>
using namespace std;
#define ll long long
ll n;
string s;
ll cc;
int main(){
    ifstream inFile("game.in");
    ofstream outFile("game.out");
    inFile >> n;
    inFile >> s;
    if(n == 1){
        outFile << 1;
    }
    ll len = s.size();
    for(int i = 1;i<=len;i+=3){
        if(i>=4 && s[i-1] == s[i-2]){
            if(s[i-3] == s[i]){
                cc++;
            }
            i+=1;
        }
        if(i + 4 > len){
            break;
        }
    }
    for(int i = 0;i<=len - 1;i++){
        if(s[i] == s[i+1]){
            cc++;
        }
    }
    outFile << cc;
    inFile.close();
    outFile.close();
    return 0;
}
