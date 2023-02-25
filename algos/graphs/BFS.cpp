// Breadth-first search
// https://en.wikipedia.org/wiki/Breadth-first_search
#include "graph.hpp"

#include <queue>

namespace BFS
{
    int vis[GRAPH_SIZE];
    int visc = 0;


    void run(int v)
    {
        visc++;
        BFS(v);
    }

    void BFS(int v)
    {
        std::queue<int> Q;
        Q.push(v);

        while (!Q.empty()) {
            v = Q.front();
            Q.pop();

            // DO STUFF WITH THE NODE

            for (auto &u : G[v]) {
                if (vis[u] < visc) {
                    vis[u] = visc;
                    Q.push(u);
                    // DO STUFF WITH ITS NEIGHTBOURS
                }
            }
        }
    }
}