#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;file:///home/rdfz/game.out

    long long res = 0;
    for(int z = 0;z<n-1;z++){
        for(int c = z+1;c<n;c++){
            string s1;
            for(int j = z;j<=c;j++){
                s1+=s[j];
            }
            int v = s1.size();
            if((c-z+1)%2==0){
                bool l = true;
                while(l==true){
                    l = false;
                    for(int i = 1;i<v;i++){
                        if(s1[i]==s1[i-1]){
                            l = true;
                            string t1;
                            for(int j = 0;j<i-1;j++){
                                t1+=s1[j];
                            }
                            string t2;
                            for(int j = i+1;j<v;j++){
                                t2+=s1[j];
                            }
                            s1 = t1+t2;
                            v-=2;
                            break;
                        }
                    }
                }
                if(s1.size()==0){
                    res++;
                }
            }
        }
    }
    printf("%d",res);


    return 0;
}
