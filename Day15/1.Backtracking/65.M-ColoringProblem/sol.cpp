class Solution
{
public:
    bool isValid(bool graph[101][101], int node, int colour[], int n, int rang)
    {

        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[i][node] == 1 && colour[i] == rang)
                return false;
        }
        return true;
    }

    bool Coloring(bool graph[101][101], int m, int n, int colour[], int node)
    {
        if (node == n)
        {
            return true;
        }

        for (int i = 1; i <= m; i++)
        {
            if (isValid(graph, node, colour, n, i))
            {
                colour[node] = i;
                if (Coloring(graph, m, n, colour, node + 1))
                    return true;
                colour[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {

        int colour[n] = {0};

        if (Coloring(graph, m, n, colour, 0))
            return true;
        return false;
    }
};