#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph
{
    int v;   
    vector<list<int>> adj;
public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void addLinking(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int s, int n) { 
        vector<bool> visited;
        visited.resize(v + 1, false);

        for (int i = 0; i < n + 1; i++)
        {
            auto index = adj[i].begin();
            for (auto k = adj[i].begin(); k != adj[i].end(); k++)
            {
                int min = 1000;
                for (auto j = k; j != adj[i].end(); j++)

                {
                    if (*j < min)
                    {
                        min = *j;
                        index = j;
                    }
                }
                if (k == index)
                    continue;
                int temp = *k;
                *k = *index;
                *index = temp;
            }
        }
        list<int> nodes;
        visited[s] = true;
        nodes.push_back(s);

        while (!nodes.empty())
        {
            s = nodes.front();          
            nodes.pop_front();

            for (auto adjecent : adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    nodes.push_back(adjecent);
                }
            }
            if (!nodes.empty())
                cout << s << ' ';
            else
                cout << s;

        }
    }
 };

int main()
{
    int n, m, v;
    std::cin >> n;
    std::cin >> m;
    std::cin >> v;
    
    // n보다 커야 한다.
    Graph g(n + 1);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        g.addLinking(a, b);
    }
    g.BFS(v, n);
    return 0;
}