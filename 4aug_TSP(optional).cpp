#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int inf = 1e9;
const int N = 6;
int a[N][N];

int solve(vector <int> path, int n){
    int dist = 0;

    for (int i = 0; i < path.size() - 1; i++){
        if (a[path[i]][path[i+1]] == 0 && path[i+1] == 0){
            dist = inf;
            break;
        }
        else dist += a[path[i]][path[i+1]];
    }

    if (a[path.size()-1][0] == 0) dist = inf;
    else dist += a[path[path.size()-1]][0];

    return dist;
}

int main(){
    freopen("C:/Users/almaz/CLionProjects/lab4aug/input.txt","r",stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector <int> path;
    for (int i = 0; i < n; i++) path.pb(i);

    int minlen = inf;
    vector <int> ans;

    do {
        int len = solve(path,n);
        if (len < minlen){
            minlen = len;
            ans = path;
        }

    } while (next_permutation(path.begin()+1, path.end()));

    cout << minlen << '\n';
    ans.pb(0);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}