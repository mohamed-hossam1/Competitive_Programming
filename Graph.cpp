int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dx2[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy2[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int N = 1e5;
bool visited[N];
vector <int> adj[N];vector <pair<int,int>> adjw[N];
void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == false)
         dfs(adj[s][i]);
    }
}

void list() {
    int n,j;
    cin>>n>>j;
    int s,d;
    for(int i = 0;i < j;i++){
    {
        cin>>s>>d;
        adj[s].push_back(d);
    }
}
