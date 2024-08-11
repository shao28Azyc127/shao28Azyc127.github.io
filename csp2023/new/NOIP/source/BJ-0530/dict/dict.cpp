#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
bool cmp(char a,char b){
    return a>b;
}
char s[3001][3001];
char min1[3001];
char min2[3001];
int ind;
bool comp(char *a,char *b){
    //a smaller than b?
    for(int i = 0;i<m;i++){
        if(a[i]<b[i]){
            return 1;
        }else if(a[i]>b[i]){
        return 0;
        }
    }
    return 0;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1){
        cout << 1;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        cin >> s[i];
        sort(s[i],s[i]+m,cmp);
      //  cout << s[i]<< endl;
      //  cout << (int)s[i][0]<<' '<<(int)s[i][1]<< endl;
        if(i==1){
            for(int j = 0;j<m;j++){
                min1[j] = s[i][j];

            }
            ind = 1;
        }else if(i==2){
            if(comp(min1,s[2])){
                for(int j = 0;j<m;j++){
                    min2[j] = s[i][j];
                }
            }else{
                for(int j = 0;j<m;j++){
                    min2[j] = min1[j];
                    min1[j] = s[i][j];
                }
            }
        }else{
            if(comp(s[i],min1)){
                for(int j = 0;j<m;j++){
                    min2[j] = min1[j];
                    min1[j] = s[i][j];
                }
                ind = i;
            }else{
                if(comp(s[i],min2)){
                    for(int j = 0;j<m;j++){
                        min2[j] = s[i][j];
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        sort(s[i],s[i]+m);
        if(i==ind){
            if(comp(s[i],min2))printf("1");
            else printf("0");
        }else{
            if(comp(s[i],min1))printf("1");
            else printf("0");
        }
    }
    return 0;
}
