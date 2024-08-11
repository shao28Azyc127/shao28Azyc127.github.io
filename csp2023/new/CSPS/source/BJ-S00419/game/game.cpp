#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;
int sum=0;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            string str;
            string str1;
            for(int k=i;k<=j;k++){
                str+=s[k];
            }
            str1=str;
            if(str.length()%2==0){
                while(!str.empty()){
                    bool flag=false;
                    for(int k=0;k<str.length();k++){
                        if(str[k]==str[k+1]){
                            for(int l=k+2;k<str.length();k++){
                                str[l-2]=str[l];
                            }
                            str.pop_back();
                            str.pop_back();
                            flag=true;
                        }
                    }
                    if(!flag){

                        break;
                    }
                }
                if(str.empty()){
                    sum++;
                }
            }
        }
    }
    cout<<sum;
}
