#include <iostream>
using namespace std;
int n,l[100000],m[100000],L,nl=0,nm=0;
int main(){
    freopen("road.in",'r',stdin);
    freopen("road.out",'w',stdout);
    cin>>n>>L;
    for(int i=1;i<n;i++){
    	cin>>len[i];
    }
    for(int i=1;i<=n;i++){
    	cin>>m[i];
    }
    int Min=9999999;
    for(int i=1;i<n;i++){
    	Min=min(Min,m[i]);
    	while(nl*L<len[i]){
            nl++;
            nm+=Min;
    	}
    }
    cout<<nm;
    return 0;
}
