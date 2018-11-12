#include <bits/stdc++.h>
using namespace std;

int H,W;
int cnt = 0;

vector < string > Map;
int visit[20][20];

int dy[4][2] = { {1,1},{1,1},{1,0},{0,1} };
int dx[4][2] = { {0,-1},{0,1},{0,1},{1,1} };

void fillBoard() {
    int sy = -1, sx = -1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(visit[i][j] == 0) {
                sy = i;
                sx = j;
                break;
            }
        }
        if(sy>=0 && sx>=0) break;
    }
    //cout << sy << " " << sx << '\n';
    if(sy < 0 && sx < 0) {
        cnt++;
    }
    else {
        for(int i=0; i<4; i++) {
            bool flag = true;
            for(int j=0; j<2 && flag; j++) {
                int Y = sy+dy[i][j], X = sx+dx[i][j];
                if(Y < 0 || Y >= H || X < 0 || X >= W) {
                    flag = false;
                }
                else if(visit[Y][X] == 1) {
                    flag = false;
                }
            }
            if(flag) {
                visit[sy][sx] = 1;
                for(int j=0; j<2; j++) {
                    int Y = sy+dy[i][j], X = sx+dx[i][j];
                    visit[Y][X] = 1;
                }
                fillBoard();
                visit[sy][sx] = 0;
                for(int j=0; j<2; j++) {
                    int Y = sy+dy[i][j], X = sx+dx[i][j];
                    visit[Y][X] = 0;
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int C;
    cin >> C;
    while(C--) {
        memset(visit,0,sizeof(visit));
        Map.clear();
        cin >> H >> W;
        Map.resize(H);
        for(int i=0; i<H; i++) {
            cin >> Map[i];
            for(int j=0; j<W; j++) {
                if(Map[i][j] == '#') {
                    visit[i][j] = 1;
                }
            }
        }
        cnt = 0;
        fillBoard();
        cout << cnt << '\n';
    }

    return 0;
}
