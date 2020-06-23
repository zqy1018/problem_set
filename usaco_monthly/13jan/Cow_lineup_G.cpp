#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar(); }
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
int n, k, a[100005];
int tot = 0;
pair<int, int> p[100005];
unordered_map<int, int> cnt;
void init(){
	n = read(), k = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read(), cnt[a[i]] = 0;
	for (int i = 1, j; i <= n; j = i){
		for (j = i; j <= n && a[i] == a[j]; ++j)
			;
		p[++tot].first = a[i], p[tot].second = j - i;
		i = j;
	}
}
void solve(){
	int cur = 1, ans = 0, cb = 0;
	for (int i = 1; i <= tot; ++i){
		int b = p[i].first, len = p[i].second;
		if (!cnt[b]) ++cb;
		cnt[b] += len;
		while (cb > k + 1){
			int bb = p[cur].first, ll = p[cur].second;
			cnt[bb] -= ll;
			if (!cnt[bb]) --cb;
			++cur;
		}
		ans = max(ans, cnt[b]);
	}
	printf("%d\n", ans);
}
int main(){
	init();
	solve();
	return 0;
}
