#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int b[n]={},ans=0,t=1,c[n]={},d[n]={};//b��ֵ�������ڿ�ɾ���Ӵ���ţ�t������һ��ţ�c��ֵ����ÿ������������Ӵ�������d��ֵ����ÿ������Ƿ����ǰ����
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            ans++;
            if(b[i]!=0){
                d[t]=1;
            }
            b[i]=t;
            b[i+1]=t;
            int j=i-1,k=i+2;
            while(j>=0&&k<n){
                if(a[j]==a[k]){
                    ans++;
                    if(b[j]!=0){
                        d[t]=1;
                    }
                    b[j]=t;
                    b[k]=t;
                    j--;
                    k++;
                }else{
                    break;
                }
            }
            c[t]++;
            t++;
        }
    }
    for(int i=0;i<n-1;i++){
        if(b[i]<b[i+1]&&d[b[i+1]]==0){
            ans+=c[b[i]];
            c[b[i+1]]+=c[b[i]];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
