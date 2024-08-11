#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int box[3050][30];
int ans[3050];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch<'a'||ch>'z')ch=getchar();
        while(ch>='a'&&ch<='z'){
            box[i][ch-'a'+1]++;
            ch=getchar();
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++)cout<<box[i][j]<<",";
        cout<<endl;
    }
    */
    int mid=1;
    for(int p=1;p<=n;p++){
        for(int i=26;i>=1;i--){
            if(box[p][i]>box[mid][i])break;
            if(box[p][i]<box[mid][i]){
                mid=p;
                break;
            }
        }
    }
    //cout<<mid<<endl;
    int mpos=26;
    while(box[mid][mpos]==0)mpos--;
    for(int i=1;i<=n;i++){
        if(i==mid)continue;
        int pos=1;
        while(box[i][pos]==0)pos++;
        if(mpos>pos)ans[i]=1;
        //cout<<i<<":"<<pos<<","<<mpos<<endl;

    }
    ans[mid]=1;
    for(int i=1;i<=n;i++){
        if(i==mid)continue;
        int mpos=1,pos=26;
        while(box[i][pos]==0)pos--;
        while(box[mid][mpos]==0)mpos++;
        if(mpos>=pos){
            ans[mid]=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }
return 0;
}
