#include<iostream>
#include<fstream>
using namespace std;
#define ll long long
string str;
ll summ;
ll cc;
ll a[200010];
ll n;
int main(){
    ifstream inFile("game.in");
    ofstream outFile("game.out");
    inFile >> n;
    inFile >> str;
    for(int i = 1, cc = 0;i < n;i += 2, cc ++){
        a[cc] += i;
    }
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++){
            if(str[i] == str[i + a[j]] && str[i] != 0){
                summ ++;
/*                cout << str[i] << str[i + a[j]]<<" ";*/
                str[i] = 0;
                str[i + a[j]] = 0;
            }
        }
    }
    outFile << summ + 1;/*han you kong chuan*/
    inFile.close();
    outFile.close();
    return 0;
}
