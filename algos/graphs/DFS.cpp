// Depth-first search
// https://en.wikipedia.org/wiki/Depth-first_search
#include <graph.hpp>


namespace DFS
{
    bool vis[GRAPH_SIZE];
    int visc = 0;
    
    void run(int v)
    {
        visc++;
        DFS(v);
    }

    void DFS(int v)
    {
        vis[v] = true;

        // DO STUFF WITH THE NODE

        for (auto &u : G[v]) {
            if (vis[u] < visc) {
                vis[u] = visc;
                DFS(u);
                // DO STUFF WITH IT'S NEIGHTBOURS
            }
        }
    }
}
