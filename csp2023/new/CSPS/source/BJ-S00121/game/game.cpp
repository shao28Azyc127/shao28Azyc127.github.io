#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s1;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            vector<char>v;
            for(int a=i;a<=j;a++)v.push_back(s[a]);
            while(v.size()){
                    int f=0;
                    vector<char>::iterator it=v.begin();
                for(int k=0;k<v.size()-1;k++,it++)if(v[k]==v[k+1])v.erase(it),it--,v.erase(it),it--,k--,f=1;
                if(f==0){sum--;break;}
            }
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}
