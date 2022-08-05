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
    // ����׷����̹Ƿ� ���ʿ� �Ѵ� �� �־��ֱ�
    void addLinking(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int s, int n) { 
        //������ ��� �湮 ���ߴٰ� ����
        vector<bool> visited;
        visited.resize(v + 1, false);
        // ���� �迭�� �� ������� ������ �ϱ�
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
        // queue�� �� �ְ� �湮�ߴٰ� ���� 
        list<int> nodes;
        visited[s] = true;
        nodes.push_back(s);

        while (!nodes.empty())
        {
            // �� queue���� ��������
            s = nodes.front();          
            nodes.pop_front();

            for (auto adjecent : adj[s])
            {
                // ������ �湮���� �ʾҴٸ� �湮�ߴٰ� �����ϰ� queue�� �� �ֱ�
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    nodes.push_back(adjecent);
                }
            }
            //��� 
            if (!nodes.empty())
                cout << s << ' ';
            else
                cout << s;

        }
    }
 };

int main()
{
    //������ ���� ������ ���� Ž���� ������ ������ ��ȣ
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

1. ���� �� ť�� �� ������ �ϱ�
2. �迭�� �� ũ�� ������� ������ �ϱ�
3. 1 4 ������ �� 4 1�� �����ؾ� ��
*/