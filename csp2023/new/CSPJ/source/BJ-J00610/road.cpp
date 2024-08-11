#include <iostream>
#include <fstream>
using namespace std;
int n,d,v[100000],a[100005],minn,sum;
int dfs(int i){
    for(int j=1;j<=sum/d;j++){
        if(j*d>=v[i]){
            minn+=j*d;
            dfs(i+1);
        }
    }
}
int main(){
    ifstream inFile("road.in");
    inFile>>n>>d;
    for(int i=1;i<n;i++){
        inFile>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        inFile>>a[i];
    }
    inFile.close();
    dfs(1);
    ofstream outFile("road.out");
    outFile<<minn;
    outFile.close();
    return 0;
}
