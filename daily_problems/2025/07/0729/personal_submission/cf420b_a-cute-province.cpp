#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10;
const int mod = 998244353;
/*
    把[l, r]看成[l, r-1]取差分求等于全集的区间
*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n+1), sum(m+3), l(n+1);
    for(int i = 1;i <= m; i ++){
        char x;
        int y;
        cin >> x >> y;
        if(x == '+'){
           l[y] = i;
           sum[l[y]]++;
        }
        else{
            if(l[y] == 0)sum[0]++, sum[i]--;
            else sum[i]--;
            nums[y]+=i-l[y];
            l[y] = 0;
        }
        
    }
    for(int i = 1; i <= n; i++){
    	if(l[i] != 0){
    		nums[i] += m+1-l[i];
    		sum[m+1]--;
		}
	}
    int ans = 0, p = 0, cnt = 0, all = 0;
    for(int i = 0; i <= m+1; i ++){
    	p += sum[i];
    	if(p > 0)all++;
	}
    
    for(int i = 1; i <= n;i ++){
        if(nums[i] == all){
            ans = i;
            break;
        }
    }
    for(int i = 1 ;i <= n; i ++){
        if(nums[i] == 0)cnt++;
    }
    if(ans != 0)cnt++;
    cout << cnt << '\n';
    for(int i = 1; i <= n; i ++){
        if(nums[i] == 0 || i == ans)cout << i <<' ';
    }

   
    
    
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流


     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
