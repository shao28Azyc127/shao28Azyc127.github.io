#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 3e3+5;

char a[N][N];
int n,m;

char mina[N][N],maxa[N][N];

priority_queue<char, vector<char>, less<char> > q;

bool cmp(char *a,char *b){
    for(int i = 1;i <= m;i++){
        if(a[i] < b[i]){
            return true;
        }
        if(a[i] >= b[i]){
            //cout << " ," << a[i] << ">=" << b[i] << ", ";
            return false;
        }
    }
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            q.push(a[i][j]);
        }
        for(int j = 1;j <= m;j++){
            maxa[i][j] = q.top();
            mina[i][m-j+1] = q.top();
            q.pop();
        }
    }

    for(int i = 1;i <= n;i++){
        bool flag = true;
        //cout << endl << mina[i]+1 << endl;
        for(int j = 1;j <= n;j++){
            //cout << maxa[j]+1;
            if(!cmp(mina[i],maxa[j])){
                flag = false;
                //cout << '!' << endl;
                break;
            }
            //cout << endl;
        }
        if(flag) printf("1");
        else printf("0");

    }
    return 0;
}
