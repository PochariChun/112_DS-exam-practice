#include<iostream>
#include<string>
using namespace std;
const int maxn = 100 + 100;
const int INF = 0x3f3f3f3f; //設定為無限大
int c, s, q; //宣告c為頂點數量 s為邊數 q為需要求出解答的路徑數量
int c1, c2, d;
int dist[maxn][maxn]; //宣告一個二維矩陣做路徑儲存
void Floyd()
{
    for(int k = 1; k <= c; k++)
    {
        for(int i = 1; i <= c; i++)
            for(int j = 1; j <= c; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));//車流量大小比較

    }
}
int main()
{
    int cnt = 0;
    c = 7; //頂點7個
    s = 9; //邊9條
    cin >> q;
    for(int i = 1; i <= c; i++)
        for(int j = 1; j <= c; j++)
            dist[i][j] = INF; //先將依照頂點數量所建構的二維矩陣做初始值無限大設定
    dist[1][2] = dist[2][1] = 50;//AB邊車流量為50
    dist[1][3] = dist[3][1] = 60;//AC邊車流量為60
	dist[2][4] = dist[4][2] = 120;
	dist[2][5] = dist[5][2] = 90;
	dist[3][6] = dist[6][3] = 50;
	dist[4][6] = dist[6][4] = 80;
	dist[4][7] = dist[7][4] = 70;
	dist[5][7] = dist[7][5] = 40;
	dist[6][7] = dist[7][6] = 140;
	
    Floyd(); //設定好頂點和邊的設定後進行計算

    for(int i = 0; i < q; i++)
    {
        cin >> c1 >> c2; //輸入起點和終點
        if(dist[c1][c2] == INF) //若此路徑為無限大(即無邊連接)
            cout << "no path" << endl; //代表沒有路可走
        else //若有車流量
            cout << dist[c1][c2] << endl;//輸出所求的車流量
    }
}