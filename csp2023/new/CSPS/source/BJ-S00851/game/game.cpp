#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans=0;
bool fadb(int x,int y,int lo){
	//cout<<"q"<<endl;
    if(lo%2==1){
        return 0;
    }else if(lo=2 && s[x]==s[y]){
        return true;
    }else if(lo=2 && s[x]!=s[y]){
        return 0;
    }else if(lo%2==1){
        return 0;
    }else if(s[x]!=s[y]){
        //cout<<(y+x+1)/2-x<<"(y+x+1)/2-x"<<endl;
        return (fadb(x,(y+x+1)/2,lo-((y+x+1)/2-x)) && fadb((y+x-1)/2,y,y-(y+x-1)/2));
    }else if(s[x]==s[y]){
        return fadb(x+1,y-1,lo-2);
    }
    return 0;
}
int main(){
    freopen("game.in","w",stdin);
    freopen("game.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
		//cout<<"ok";
        for(int j=i+1;j<n;j++){
            if(fadb(i,j,j+1-i+1)){
                //cout<<i+1<<" "<<j+1<<" "<<j-i+1<<endl;
                ans++;
            }
            //cout<<"y"<<endl;
        }
    }
    cout<<ans-1;
    return 0;
}
