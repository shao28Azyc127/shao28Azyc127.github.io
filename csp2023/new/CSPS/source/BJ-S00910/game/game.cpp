#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+5;
int n;
char c[MAXN];
int gc[30];
int ans;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>c;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            memset(gc,false,sizeof(gc));
            for(int k=i;k<=j;k++){
                gc[c[k]-96]++;
            }
            int cnt;
            for(int k=1;k<=26;k++) cnt+=gc[k];
            if(gc[1]%2==0){
                if(gc[2]%2==0){
                    if(gc[3]%2==0){
                        if(gc[4]%2==0){
                            if(gc[5]%2==0){
                                if(gc[6]%2==0){
                                    if(gc[7]%2==0){
                                        if(gc[8]%2==0){
                                            if(gc[9]%2==0){
                                                if(gc[10]%2==0){
                                                    if(gc[11]%2==0){
                                                        if(gc[12]%2==0){
                                                            if(gc[13]%2==0){
                if(gc[14]%2==0){
                    if(gc[15]%2==0){
                        if(gc[16]%2==0){
                            if(gc[17]%2==0){
                                if(gc[18]%2==0){
                                    if(gc[19]%2==0){
                                        if(gc[20]%2==0){
                                            if(gc[21]%2==0){
                                                if(gc[22]%2==0){
                                                    if(gc[23]%2==0){
                                                        if(gc[24]%2==0){
                                                            if(gc[25]%2==0){
                                                                if(gc[26]%2==0&cnt!=0){
                                                                    ans++;

                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
