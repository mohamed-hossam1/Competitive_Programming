int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dx2[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy2[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int N = 1e5;
bool vis[N];
vector <int> adj[N];vector <pair<int,int>> adjw[N];
void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == false)
         dfs(adj[s][i]);
    }
}

bool cycle(int node, int par, int &count) //count=number of nodes in this cycle ----> cycle(node,-1,count);
{
    if(vis[node]) return true;
    vis[node] = 1;
    for(auto child_node : adj[node]) if(child_node != par)
    {
        count++;
        if(cycle(child_node, node, count) == true)
            return true;
    }
    return false;
}

