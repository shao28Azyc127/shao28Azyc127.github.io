#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
int n,d;
int dis[10001];
int price[10001];
int cal[10001];
int main(){
    ifstream fin;
    ofstream fout;
    fout.open("road.out");
    fin.open("road.in");
    fin>>n>>d;
    int cnt;
    for(int i=1;i<n;i++){
        fin>>dis[i-1];
        cnt+=dis[i-1];
    }
    for(int i=0;i<n;i++){
        fin>>price[i];
    }
    fout<<ceil(double(cnt)/d)*price[0];
    return 0;
}