#include <vector>
using namespace std;
// time complexity is O(2^N) * O(N)
// space complexity is O(2^N) * O(N)
class Solution
{
public:
    void traverseDAG(vector<vector<int>> &graph, vector<int> &visitedPath, int targetNode, vector<vector<int>> &allPath)
    {
        int currentNode = visitedPath[visitedPath.size() - 1];
        // reach final node
        if (currentNode == targetNode)
        {
            // take care about deep copy
            // it takes O(N)
            allPath.push_back(visitedPath);
            return;
        }
        // choose a next node
        // because it is a DAG graph, we don't need to check loop cases
        // graph[currentNode] is the list which connect currentNode
        for (auto node : graph[currentNode])
        {
            // update visited node
            visitedPath.push_back(node);
            traverseDAG(graph, visitedPath, targetNode, allPath);
            // revert visited node, and try next candicate node
            visitedPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> allPath;
        vector<int> visitedPath;
        int startNode = 0;
        int targetNode = graph.size() - 1;
        // we push start node
        visitedPath.push_back(startNode);
        traverseDAG(graph, visitedPath, targetNode, allPath);
        return allPath;
    }
};
int main()
{
}