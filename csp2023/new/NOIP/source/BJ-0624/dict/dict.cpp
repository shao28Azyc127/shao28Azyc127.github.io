#include<iostream>
using namespace std;
const int N=3010;
int n,len;
struct node{
    int point;
    char c;
};
node maxn[N];
node mini[N];
string s[N];
bool flag;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> len;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i]=" "+s[i];
        maxn[i].c=s[i][1];
        mini[i].c=s[i][1];
        maxn[i].point=1;
        mini[i].point=1;
        for(int j=1;j<=len;j++){
            if(s[i][j]>=maxn[i].c){
                maxn[i].c=s[i][j];
                maxn[i].point=j;
            }
            if(s[i][j]<=mini[i].c){
                mini[i].c=s[i][j];
                mini[i].point=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        string test=s[i];
        flag=true;
        for(int j=1;j<=len;j++){
            if(test[j]>mini[i].c&&j<mini[i].point){
                //cout << j << " ";
                char x;
                x=test[mini[i].point];
                test[mini[i].point]=test[j];
                test[j]=x;
                //cout << x << " " << test[mini[j].point] << " " << test[j] << endl;
                break;
            }
        }
        //cout << maxn[i].point << " " << mini[i].point;
        //cout << test << endl;
        for(int j=1;j<=n;j++){
            if(j==i){
                continue;
            }
            if(mini[i].c>maxn[j].c){
                flag=false;
                break;
            }
            string cp=s[j];
            for(int k=1;k<=len;k++){
                if(cp[k]<maxn[j].c&&k<maxn[j].point){
                    //cout << j << " ";
                    char x;
                    x=cp[maxn[j].point];
                    cp[maxn[j].point]=cp[k];
                    cp[k]=x;
                    //cout << x << " " << cp[maxn[j].point] << " " << cp[k] << endl;
                    break;
                }
            }
            //cout << test << " " << cp << endl;
            if(test>cp){
                flag=false;
                //cout << 19 << endl;
                break;
            }
        }
        if(flag==true){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
