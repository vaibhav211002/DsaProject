#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1000];
vector<pair<int,int>> adj2[1000];
const int m = 30,n = 50;
map<int,string> mp;
int minTime = -1;
int minDis = -1;
string name = "";
int number = -1;

void createGraph(){
    vector<vector<int>> adjM = {
        {0, 10, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 30, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {20, 30, 0, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 15, 0, 8, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 6, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    //convert to adjacency list
    for(int i = 0; i<30; i++) {
        for(int j = 0; j<30; j++) {
            if(adjM[i][j] != 0 &&  i!=j) {
                int wt = adjM[i][j];
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
    }

    //matrix for road blockage
    vector<vector<int>> adjM2 = {
        {0, 1, 5, 0, 2, 6, 0, 7, 8, 9, 0, 0, 3, 4, 0, 5, 0, 6, 7, 8, 0, 0, 9, 1, 0, 0, 0, 2, 0, 3},
        {1, 0, 0, 8, 6, 0, 0, 0, 0, 7, 9, 0, 0, 0, 4, 5, 8, 3, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 4, 3, 0, 1, 0, 7, 0, 0, 2, 0, 8, 6, 0, 0, 9, 0, 0, 1, 5, 3, 0, 4, 0, 0, 0, 0, 9},
        {0, 8, 4, 0, 0, 9, 5, 6, 7, 1, 3, 4, 0, 0, 0, 0, 2, 1, 9, 8, 0, 7, 6, 8, 0, 2, 0, 0, 0, 0},
        {2, 6, 3, 0, 0, 8, 7, 0, 0, 2, 0, 1, 9, 0, 0, 3, 0, 0, 0, 0, 0, 5, 0, 0, 0, 8, 4, 0, 6, 0},
        {6, 0, 0, 9, 8, 0, 6, 0, 5, 4, 2, 0, 0, 0, 0, 0, 7, 1, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 5, 7, 6, 0, 8, 4, 0, 0, 5, 0, 3, 0, 0, 0, 0, 8, 9, 2, 0, 4, 1, 0, 0, 0, 0, 0, 7},
        {7, 0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3, 5, 9, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 7, 7, 0, 5, 4, 0, 0, 0, 0, 8, 0, 0, 1, 4, 0, 2, 0, 3, 0, 9, 6, 2, 0, 0, 0, 0, 0, 0},
        {9, 7, 0, 1, 2, 4, 0, 0, 0, 0, 0, 2, 5, 7, 0, 0, 6, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 9, 0, 3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 4, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 4, 1, 0, 5, 0, 8, 2, 0, 0, 3, 0, 6, 9, 0, 0, 0, 0, 5, 7, 8, 1, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 9, 0, 0, 0, 0, 5, 0, 3, 0, 0, 0, 2, 0, 6, 0, 7, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0, 3, 0, 0, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 6, 0, 0, 0, 0, 3, 1, 0, 0, 6, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 5, 0, 0, 3, 0, 0, 5, 4, 0, 0, 9, 2, 8, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 2, 0, 7, 0, 9, 0, 6, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 9, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {6, 3, 9, 1, 0, 1, 0, 0, 2, 0, 0, 0, 6, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 9, 0, 0, 8, 0, 0, 8, 4, 0, 0, 0, 0, 0, 7, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 8, 0, 6, 9, 0, 3, 0, 1, 0, 7, 0, 0, 0, 0, 6, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 5, 0, 0, 0, 9, 9, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 5, 7, 5, 0, 0, 4, 9, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 7, 3, 6, 0, 0, 4, 1, 6, 0, 0, 8, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 8, 0, 0, 1, 0, 2, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 9, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    //convert to adjacency list
    for(int i = 0; i<30; i++) {
        for(int j = 0; j<30; j++) {
            if(adjM2[i][j] != 0 &&  i!=j) {
                int wt = adjM2[i][j];
                adj2[i].push_back({j,wt});
                adj2[j].push_back({i,wt});
            }
        }
    }
}

void display(){
    for(int i=1;i<=m;i++) {
        cout << i << " -> {";
        for(auto it : adj2[i]) {
            cout << "(" << it.first << "," << it.second << "),";
        }
        cout << "}" << endl;
    }
}

string removeSpaces(const string &str) {
    stringstream ss;
    for (char c : str) {
        if (!isspace(c)) {
            ss << c;
        }
    }
    return ss.str();
}

vector<int> bfs(int source, int dest) {
    vector<int> ans;
    queue<int> q;
    q.push(source);
    int vis[m+1] = {0};
    vis[source] = 1;
    while (! q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        if(node == dest) {
            return ans;
        }

        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                vis[it.first] = 1;
                q.push(it.first);
            }
        }
    }
    return ans;
}

void dfs(int node, int vis[], vector<int> &ans, int dest) {
    vis[node] = 1;
    ans.push_back(node);
    if(node == dest) {
        return;
    }
    for(auto it : adj[node]){
        if(!vis[it.second]) {
            dfs(it.second,vis,ans,dest);
        }
    }
}

vector<int> dfsOfGraph(int source, int dest) {
    int vis[31] = {0};
    int start = source;
    vector<int> ans;
    dfs(start,vis,ans,dest);
    return ans;
}

vector<int> shortestPath(int source, int dest)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    // vector<int> dist(n, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }
    // vector<int> path;
    // int node = dest;
    // while (parent[node] != node)
    // {
    //     node = parent[node];
    // }
    // path.push_back(source);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                parent[adjNode] = node;
            }
        }
        if(node == dest) {
            break;
        }
    }
    if (dist[dest] == 1e9)
        return {-1};
    else {
        minDis = dist[dest];
    }
    
    vector<int> path;
    int node = dest;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> time(int source, int dest)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }

    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;
        for (auto it : adj2[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                parent[adjNode] = node;
            }
        }
        if(node == dest) {
            break;
        }
    }
    if (dist[dest] == 1e9)
        return {-1};
    else {
        minTime = dist[dest];
    }
    
    vector<int> path;
    int node = dest;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}



vector<int> primMST(int source, int dest) {
        vector<bool> visited(m, false);
        vector<int> mst;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = source; 
        mst.push_back(src);

        visited[src] = true;

        for (auto& neighbour : adj[src]) {
            pq.push(make_pair(neighbour.second, neighbour.first));
        }

        while (!pq.empty()) {
            int u = pq.top().second;
            // int weight = pq.top().first;
            pq.pop();

            if (visited[u]) continue; 

            visited[u] = true;

            mst.push_back(u);
            if(u == dest) {
                return mst;
            }

            for (auto& neighbour : adj[u]) {
                if (!visited[neighbour.first]) {
                    pq.push(make_pair(neighbour.second, neighbour.first));
                }
            }
        }

        return mst;
}

void places() {

    string poshAreas[] = {
        "Connaught Place  ",
        "Gurgaon          ",
        "Noida            ",
        "Lajpat Nagar     ",
        "Rajouri Garden   ",
        "Karol Bagh       ",
        "Nehru Place      ",
        "Dwarka           ",
        "Chandni Chowk    ",
        "South Extension  ",
        "Janakpuri        ",
        "Pitampura        ",
        "Rohini           ",
        "Kalkaji          ",
        "Saket            ",
        "Vasant Kunj      ",
        "Patel Nagar      ",
        "Vikas Puri       ",
        "Kamla Nagar      ",
        "Paschim Vihar    " ,
        "Shahdara         ",
        "Dilshad Garden   ",
        "Mayur Vihar      ",
        "Model Town       ",
        "Indirapuram      ",
        "Sarita Vihar     ",
        "Green Park       ",
        "Malviya Nagar    ",
        "Okhla            ",
        "Safdarjung       "
    };
    for(int i=1;i<=30;i++) {
        mp[i] = poshAreas[i-1];
    }
    // display places
    cout << "\n----------------------PLACES-----------------------\n" << endl;
    for(int i=1;i<=30;i=i+2) {
        cout << i << ". " << mp[i] << "  \t\t\t" <<  i+1 << ". "<<mp[i+1] << endl;
    }
}

void info() {
    cout << "Enter your Name : " << endl;
    cin >> name;
    cout << "Enter Mobile number : " << endl;
    cin >> number;
}

void displayInfo() {
    info();
    cout << "_________________________________________" << endl;
    cout << "**************ROAD TICKET***************" << endl;
    cout << "NAME   : " << name << endl;
    cout << "MOBILE : " << number << endl;  
    cout << "\n" << endl;
}

void menu() {
    int ch = -1;
    int src, dest;
    cout << "*****************WELCOME TO DELHI*******************" << endl;
    cout << endl;
    cout << "Press 1 to view all possible places to visit." << endl;
    cout << "Press 0 to exit navigation." << endl;
    cin >> ch;
    if(ch == 0) {
        cout << "INVALID CHOICE !!" << endl;
        return;
    } 


    else if(ch == 1) {
        cout << "PLACES : " << endl;
        places();
        cout << "Enter source : " << endl;
        cin >> src;
        cout << "Enter destination : "<< endl;
        cin >> dest;
        
        if(src == dest || src>30 || src<1 || dest>30 || dest<1) {
            cout << "INVALID CHOICE!" << endl;
            return;
        }

        //path options
        cout << endl;
        cout << "\n********MENU********" << endl;
        cout << "Press 1 : To take the shortest path (Distance wise)." << endl;
        cout << "Press 2 : To take the path with least congestion. " << endl;
        cout << "Press 3 : To take the shortest path (Time wise)." << endl;
        cout << "Press 4 : To cover maximum areas. " << endl;
        cout << "Press 5 : To take the path with maximum traffic. " << endl;
        cin >> ch;
        displayInfo();
        if(ch == 1) {
            vector<int> dist = shortestPath(src,dest);
            for(auto i : dist) {
                string result = removeSpaces(mp[i]);
                cout << result << " -> ";
            }
            cout << "REACHED" << endl;
            cout << "DISTANCE COVERED : " << minDis << " units.\n" << endl;
            cout << "___________________________________________\n" << endl;
            
        }

        else if(ch == 2) {
            vector<int> shortDis = primMST(src,dest);
            for(auto i : shortDis) {
                string result = removeSpaces(mp[i]);
                cout << result << " -> ";
            }
            cout << "REACHED" << endl;
            cout << "\n_________________________________________\n" << endl;
        }

        else if(ch == 3) {
            vector<int> disTime = time(src,dest);
            for(auto i : disTime) {
                string result = removeSpaces(mp[i]);
                cout << result << " -> ";
            }
            cout << "REACHED" << endl;
            cout << "TIME TAKEN : " << minTime << " units." << endl;
            cout << "\n_________________________________________\n" << endl;
        }

        else if(ch == 4) {
            vector<int> areas = bfs(src,dest);
            for(auto i : areas) {
                string result = removeSpaces(mp[i]);
                cout << result << " -> ";
            } 
            cout << "REACHED" << endl;
            cout << "\n_________________________________________\n" << endl;
        }

        else if(ch == 5) {
            vector<int> deep = dfsOfGraph(src,dest);
            for(auto i : deep) {
                string result = removeSpaces(mp[i]);
                cout << result << " -> ";
            } 
            cout << "REACHED" << endl;
            cout << "\n_________________________________________\n" << endl;
        }
    }

    else {
        cout << "INVALID INPUT !!!" << endl;
    }

    
}

int main() {

    createGraph();
    // display();
    // vector<int> ans = bfs();
    // cout << "BFS Traversal : " << endl;
    // for(auto i : ans) {
    //     cout << i << ", ";
    // }

    // places();
    menu();
    // vector<int> mst = primMST(22,20);
    return 0;
}