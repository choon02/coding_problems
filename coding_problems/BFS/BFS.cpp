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
    // 무향그래프이므로 양쪽에 둘다 값 넣어주기
    void addLinking(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int s, int n) { 
        //정점들 모두 방문 안했다고 설정
        vector<bool> visited;
        visited.resize(v + 1, false);
        // 정렬 배열에 값 순서대로 들어오게 하기
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
        // queue에 값 넣고 방문했다고 설정 
        list<int> nodes;
        visited[s] = true;
        nodes.push_back(s);

        while (!nodes.empty())
        {
            // 값 queue에서 내보내기
            s = nodes.front();          
            nodes.pop_front();

            for (auto adjecent : adj[s])
            {
                // 정점에 방문하지 않았다면 방문했다고 설정하고 queue에 값 넣기
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    nodes.push_back(adjecent);
                }
            }
            //출력 
            if (!nodes.empty())
                cout << s << ' ';
            else
                cout << s;

        }
    }
 };

int main()
{
    //정점의 개수 간선의 개수 탐색을 시작할 정점의 번호
    int n, m, v;
    std::cin >> n;
    std::cin >> m;
    std::cin >> v;
    
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
/*
8 7 1

1 2
1 5
1 6
2 3
2 7
6 8
3 4

1 2 5 6 3 7 8 4

9 12 1

1 2
1 3
2 4
2 5
3 5
3 6
4 7
5 7
5 8
6 8
7 9
8 9

1 2 3 4 5 6 7 8 9

4 4 1

4 1
3 2
3 1
3 4

1 3 4 2

1. 같은 값 큐에 못 들어오게 하기
2. 배열에 값 크기 순서대로 들어오게 하기
3. 1 4 저장할 때 4 1도 저장해야 함
*/