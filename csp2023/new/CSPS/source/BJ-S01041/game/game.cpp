#include <bits/stdc++.h>
using namespace std;
ifstream fin("game.in");
ofstream fout("game.out");

enum{ N=2000006,S=26 };
int n;
char s[N];
int p[N][S]; // p[i][ch]: �����ϴӵ�i�����ߣ������ĵ�һ��ch��ı�ţ����ޣ�Ϊ0��
int fa[N]; // fa[i]: i�ĸ��ף���fa[i]=max{j: (j,i]������}���������ڣ�Ϊ-1
int dep[N];
int main(){
    fin>>n>>(s+1);
    for(int i=1;i<=n;i++){
        const int ch=s[i]-'a';
        const int j=p[i-1][ch];
        fa[i]=j-1;
        if(j) memcpy(p[i],p[j-1],sizeof(p[i])), dep[i]=dep[j-1]+1;
        p[i][ch]=i;
    }
    fout<<accumulate(dep+1,dep+1+n,0ll)<<'\n';

    return 0;
}