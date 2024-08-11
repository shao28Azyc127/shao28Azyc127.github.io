                                                                                                                                                             #incude<bits/stdc++.h>
using namespace std;
int g[1001];
int main(){
        freopen("bus.in","r",stdin);
        freopen("bus.out,"w",stdout);                                                                                                                                                                      
        int a,b,c;                                                                                                                                                                                         
        cin>>a>>b>>c;                                                                                                                                                                                      
        int d[a+1],e[a+1],f[a+1];                                                                                                                                                                          
        for(int i=1;i<=a;i++){                                                                                                                                                                             
                cin>>d[i]>>e[i]>>f[i];                                                                                                                                                                     
                g[d[i]]++;                                                                                                                                                                                 
        }                                                                                                                                                                                                  
        int y=0;                                                                                                                                                                                           
        for(int i=1;i<=1001;i++){                                                                                                                                                                          
                if(g[i]!=0){                                                                                                                                                                               
                        y++;                                                                                                                                                                               
                }                                                                                                                                                                                          
        }                                                                                                                                                                                                  
        cout<<c+(y-1);                                                                                                                                                                                     
}                                                                                                                                                                                                          