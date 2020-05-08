//This file is from redesigned-eureka
#include<iostream>
#include<cctype>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long map[28][28];
int n, m, xm, ym;
bool mapb[28][28];
int x[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int y[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int main(){
    cin>>n>>m;
    cin>>xm>>ym;
    mapb[xm][ym] = true;
    for(int i=0;i<8;i++){
        int xm1 = xm + x[i];
        int ym1 = ym + y[i];
        if(xm1 >= 0 && xm1 <= n && ym1 >=0 && ym1 <= m){
            //cout<<xm1<<" "<<ym1<<endl;
            mapb[xm1][ym1] = true;
        }
    }
    bool flag = false;
    for(int i=0;i<=n;i++){
        if(mapb[i][0]) flag = true;
        if(flag) map[i][0] = 0;
        else map[i][0] = 1;
    }
    flag = false;
    for(int j=0;j<=m;j++){
        if(mapb[0][j]) flag = true;
        if(flag) map[0][j] = 0;
        else map[0][j] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mapb[i][j]) map[i][j] = 0;
            else map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
    cout<<map[n][m]<<endl;
    return 0;
}
