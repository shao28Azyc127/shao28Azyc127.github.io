#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int s[2][10000001];
int main(){
    ifstream fin("apple.in");
    ofstream fout("apple.out");
    int n,row=-1,ans2;bool still=true;
    fin>>n;
    for(int i=1;i<=n;++i)
        s[0][i]=i;
    int i=2,j=n+1,ended=n;
    while(i>1){
        for(i=1,j=1,++row;j<=ended;++j){
            if(j%3==1) continue;
            s[(row+1)%2][i++]=s[row%2][j];
        }
        if(j%3==2&&still){
            still=false;
            ans2=row+1;
        }
        ended=i-1;
    }
    fout<<row+1<<" "<<ans2;
    fin.close();
    fout.close();
    return 0;
}
