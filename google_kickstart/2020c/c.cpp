#include <bits/stdc++.h>
#define INF 2000000000
#define OFFSET 10000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[100005];
int cnt[20000005] = {0};
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    int maxi = INT_MIN, sum = 0, mini = 0;
    cnt[0 + OFFSET] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        sum += a[i];
        maxi = max(maxi, sum - mini);
        mini = min(mini, sum);
        for (int j = 0; j * j <= maxi; ++j)
            ans += cnt[sum - j * j + OFFSET];
        ++cnt[sum + OFFSET];
    }
    printf("%lld\n", ans);
    sum = 0, cnt[0 + OFFSET] = 0;
    for (int i = 1; i <= n; ++i){
        sum += a[i];
        cnt[sum + OFFSET] = 0;
    }
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