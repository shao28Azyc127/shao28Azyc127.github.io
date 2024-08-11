#include<iostream>
#include<fstream>
using namespace std;
string stac;
bool is(string str){
    stac.clear();
    stac+=str[0];
    for(int i=1;i<str.length();++i){
        if(str[i]==stac[stac.length()-1]) stac.pop_back();
        else stac+=str[i];
    }
    return stac.empty();
}
string slice(string str,int x,int y){
    string ans;
    for(int i=x;i<=y;++i) ans+=str[i];
    return ans;
}
int main(){
    ifstream fin("game.in");
    ofstream fout("game.out");
    string str;
    int n,ans;
    fin>>n;
    //for(int x=0;x<n;++x){
        fin>>str;
        ans=0;
        for(int i=0;i<str.length();++i){
            for(int j=i+1;j<str.length();j+=2)
                if(is(slice(str,i,j))) ++ans;
        }
        fout<<ans<<endl;
    //}
    fin.close();
    fout.close();
    return 0;
}
