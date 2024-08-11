#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;
int n;
char c[2000001];
bool mark[2000001],brake;
int ret;
int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    //cout<<c<<endl;
    // ???
    for(int s=0;s<n-1;s+=2) {
        for(int e=1;e<n;e+=2) {
            for(int i=0;i<(e-s+1)/2;i++) {
                int j=s;
                int curpos=j;
                char curr=c[j];
                while(j<e) {
                    j++;
                    if(c[j]==curr) {
                        mark[j]=mark[curpos]=1;
                        j++;
                        curr=c[j];
                        curpos=j;
                    } else {
                        brake=0;
                        if(!mark[j]) {
                            brake=1;
                            break;
                        }
                    }
                }
                if(brake) {
                    break;
                }
            }
            //
            if(!brake) {
                ret++;
            }
        }
    }
    cout<<ret;
    return 0;
}
