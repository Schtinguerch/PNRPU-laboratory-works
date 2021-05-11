using System;

namespace GraphsVisualization
{
    class GraphNavigator
    {
        public double[] Distance { get; set; }

        private int MinimumDistance(double[] distance, bool[] shortestPathTreeSet, int verticesCount)
        {
            var min = double.MaxValue;
            int minIndex = 0;

            for (int v = 0; v < verticesCount; ++v)
                if (shortestPathTreeSet[v] == false && distance[v] <= min)
                {
                    min = distance[v];
                    minIndex = v;
                }
            
            return minIndex;
        }

        public void FindShortestRanges(double[,] graph, int source, int verticesCount)
        {
            var distance = new double[verticesCount];
            var shortestPathTreeSet = new bool[verticesCount];

            for (int i = 0; i < verticesCount; ++i)
            {
                distance[i] = int.MaxValue;
                shortestPathTreeSet[i] = false;
            }

            distance[source] = 0;

            for (int count = 0; count < verticesCount - 1; ++count)
            {
                int u = MinimumDistance(distance, shortestPathTreeSet, verticesCount);
                shortestPathTreeSet[u] = true;

                for (int v = 0; v < verticesCount; ++v)
                    if (!shortestPathTreeSet[v] && Convert.ToBoolean(graph[u, v]) && Math.Abs(distance[u] - double.MaxValue) > Math.Pow(10, -6) && distance[u] + graph[u, v] < distance[v])
                        distance[v] = distance[u] + graph[u, v];
            }

            Distance = distance;
        }
    }
}
