#include<bits/stdc++.h>
using namespace std;
struct w{
    char l;
    int num=0;
}word[1000001];
w w3[1000001],w2[1000001];
int mem3[1000001]={0},h3=1;
int main(){
    FILE* f=freopen("game.in","r",stdin);
    FILE* f2=freopen("game.out","w",stdout);
    int n,h=1,d=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>word[i].l;
        word[i].num=i;
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            w2[h]=word[i];
            h++;
            continue;
        }
        if(word[i].l==w2[h-1].l){
            h--;
            if(h==1){
                mem3[h3++]=word[i].num;
            }
            continue;
        }
        w2[h++]=word[i];
    }
    int now=1,h2=1,ans2=0;
    for(int j=1;j<h3;j++){
        for(int i=now;i<=mem3[j];i++){
            if(i==1){
                w3[h2]=word[i];
                h2++;
                continue;
            }
            if(word[i].l==w3[h2-1].l){
                d++;
                h2--;
                continue;
            }
            w3[h2++]=word[i];
        }
        now=w2[h].num+1;
        ans2+=(d-1)*d/2;
        d=0;
    }
    int p=(h3-2)*(h3-1)/2;
    cout<<ans2+p;
    fclose(f);
    fclose(f2);
    return 0;
}
