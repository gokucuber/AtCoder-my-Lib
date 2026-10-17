// 基本的なalgorithm
// bit全探索
/*
for (int bits = 0; bits < (1 << n); bits++)
    {
        for (int i = 0; i < n; i++)
        {
            if (bits & (1 << i))
            {

            }
*/

// 累積和
/*
int N; cin >> N; // 配列サイズ
vector<int> a(N);
for (int i = 0; i < N; ++i) cin >> a[i]; // a の入力

// 累積和
vector<int> s(N+1, 0); // s[0] = 0 になる
for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

// 区間 [left, right) の総和を求める
int left, right;
cin >> left >> right;
cout << s[right] - s[left] << endl;
https://qiita.com/drken/items/56a6b68edef8fc605821

*/

// BFS
/*
実装例
# include <iostream>
# include <vector>
# include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
O(N+M)
各辺の重みが等しいとき、最短距離が保証される
探索空間が大きいため、解がスタートから十分近いところにあるときに使える。

*/

// DFS
/*
実装例
# include <iostream>
# include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //有効グラフならpush_backは片方でよさそう
    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}



O(N+M)
探索空間が広くても使える
*/

// 順列全探索
/*
do {
    print(v);
  } while (std::next_permutation(v.begin(), v.end()));


vはソートされている必要がある。
*/

// 二分探索
/*
O(logn)
めぐる式二分探索
bool is_ok(long long mid) {
    // ここに問題ごとの条件判定を書く
    // midが条件を満たせばtrueを返す
    return true;
}

long long binary_search() {
    // okとngの初期値は問題に合わせて設定する
    long long ok = 1e18; // 絶対に条件を満たす値
    long long ng = -1;   // 絶対に条件を満たさない値

    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if (is_ok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

lower_bound(v.begin(),v.end(),val)：「val 以上」の要素が最初に現れる場所を返す
upper_bound(v.begin(),v.end(),val)：「val より大きい」要素が最初に現れる場所を返す(イテレータ)

① X以上の最小の値を求めたい
これはそのまま lower_bound を使えば一発だよ。

② 配列の中にXがいくつあるか数えたい
upper_bound と lower_bound の結果を引き算すると要素の個数がパッとわかるよ。
upper_bound(2) - lower_bound(2) を計算すると 4 - 1 = 3 になってちゃんと2が3個あることがわかるね。
*/

// p->firstは*p.firstの意味
// ranges::upper_bound(takahashi, T, {}, &pair<unsigned, unsigned>::second)->first

/*
尺取り法
雰囲気これ
long long ans = 0; // 答えが大きくなるから long long にしておくね
int right = 0;
for (int left = 0; left < s.size(); left++)
{
    // 条件を満たす限り right を右に進める
    while (right + 1 < s.size() && s[right] != s[right + 1])
    {
        right++;
    }

    // left から right までの長さの分だけ部分文字列があるよ
    ans += (right - left + 1);
    ans %= 998244353; // ここで余りを取るのを忘れないようにね！

    // left が right に追いついちゃったら right も一緒に進める
    if (left == right)
    {
        right++;
    }
}


*/

/*
ランレングス圧縮
rep(i, n) {
        ll A;
        cin >> A;
        if(A!=bef&&i>0){
            a.push_back(count);
            count=0;
        }
        if(count==0)a.push_back(A);
        bef=A;
        count++;
    }

*/

/*
// 深さ優先探索でn^kを全探索する関数
void dfs(int depth, int n, int k, vector<int>& current) {
    // k個選び終わったら結果を出力して戻る
    if (depth == k) {
        for (int val : current) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // 0からn-1までの選択肢を順番に試す
    for (int i = 0; i < n; ++i) {
        current.push_back(i);        // 選んだ数字を追加
        dfs(depth + 1, n, k, current); // 次の深さへ進む
        current.pop_back();          // 戻ってきたら要素を消して次の選択肢へ（バックトラック）
    }
}
*/

/*
imos法
ABC408Cのように、様々な区間が与えられて、その重なりの最小値を求めたいとき、愚直にカウントするとO(NM)になってしまいTLEするので、

①区間が始まるところを+1
②区間が終わるところの次の位置を-1
③前の区間の人数+今回区間に加わる数+区間から外れる数を順次足し算していく➡O(N+M)

各バス停では「乗った人数」と「降りた人数」だけメモしておく。最後に1番のバス停から順番に「前のバス停の人数 ＋ 今回乗った人数 − 今回降りた人数」を計算していく方法。（だから+1とは限らない）

*/