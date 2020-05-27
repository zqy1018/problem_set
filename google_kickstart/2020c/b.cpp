#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, du[100], cnt;
char s[105][105];
bool to[100][100], vis[100], vis2[100];
queue<int> q;
char ans[100];
void init(){
    n = read(), m = read();
    memset(to, 0, sizeof(to));
    memset(du, 0, sizeof(du));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j){
            if (!vis[s[i][j] - 'A'])
                vis[s[i][j] - 'A'] = true, ++cnt;
        }
    }
}
void solve(){
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j){
            if (s[i][j] != s[i + 1][j]){
                int u = s[i][j] - 'A', v = s[i + 1][j] - 'A';
                if (!to[v][u])
                    to[v][u] = true, ++du[u];
            }
        }
    int tot = 0;
    for (int i = 0; i < 26; ++i)    {
        if (!du[i] && vis[i])
            q.push(i);
    }
    while (!q.empty()){
        int h = q.front();
        q.pop();
        ans[tot++] = h + 'A';
        for (int i = 0; i < 26; ++i){
            if (to[h][i]){
                to[h][i] = false, --du[i];
                if (!du[i]) q.push(i);
            }
        }
    }
    if (tot != cnt) printf("-1\n");
    else ans[tot] = '\0', printf("%s\n", ans);
}
int main(){
    int T = read();
    for (int i = 1; i <= T; ++i){
        printf("Case #%d: ", i);
        init();
        solve();
    }
    return 0;
}