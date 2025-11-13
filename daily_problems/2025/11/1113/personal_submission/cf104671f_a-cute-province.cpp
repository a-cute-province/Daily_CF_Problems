#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;
int sum[N][35], a[N];
void solve()
{   
   int n, k, q;
   cin >> n >> k >> q;
   for(int i = 1;i  <= n; i ++){
        cin >> a[i];
        if((a[i]&k) != k)continue;
        
        for(int j = 0 ;j < 30; j ++){
            if((a[i] >> j) & 1)sum[i][j] = 1;
        }
   }
   for(int j = 0; j < 30 ;j ++){
    
    for(int i = 1; i <= n; i ++)sum[i][j] += sum[i-1][j];
   }
  

   while(q--){
    int l, r;
    cin >> l>> r;
    int fl = 0, L = r-l+1;
    for(int j = 0; j < 30 && !fl; j ++){
        if((k >> j) & 1){
            L = sum[r][j] -sum[l-1][j];
            break;
        }
    }
    for(int j = 0; j < 30 && !fl; j ++){
        if(((k >> j) & 1) == 0){
            if(sum[r][j] -sum[l-1][j] == L){
                fl=  1;
                break;
            }
        }
    }
    if(fl || L == 0)cout << "NO\n";
    else cout << "YES\n";
   }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;    
    while (t--)
    {
        solve();
    }
    return 0;
}
