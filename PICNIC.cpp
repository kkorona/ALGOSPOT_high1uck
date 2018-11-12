#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int R[10][10];
int visit[10];

void f(int cur,int ed) {
    if(cur == ed) cnt++;
    if(visit[cur]) f(cur+1,ed);
    for(int i=cur+1; i<ed; i++) {
        if(R[cur][i] && visit[i] == 0) {
            visit[cur] = 1;
            visit[i] = 1;
            f(cur+1,ed);
            visit[cur] = 0;
            visit[i] = 0;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int C;
    cin >> C;
    while(C--) {
        memset(R,0,sizeof(R));
        memset(visit,0,sizeof(visit));
        int n,m;
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int x,y;
            cin >> x >> y;
            if(x > y) swap(x,y);
            R[x][y] = 1;
        }
        
        cnt = 0;
        f(0,n);
        cout << cnt << '\n';
        
    }
    
    return 0;
}