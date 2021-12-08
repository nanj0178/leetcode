class Solution
{
public:
    // example
    // 4,2,3,0,3,1,2
    // 0 1 2 3 4 5 6
    bool canReach(vector<int> &arr, int start)
    {
        // record step path;
        // queue<idx>
        queue<int> stepQueue;
        unordered_set<int> stepVisited;
        stepQueue.push(start);
        stepVisited.insert(start);
        int n = arr.size();
        if (0 > start && start > n)
        {
            return false;
        }
        while (!stepQueue.empty())
        {
            int cur_idx = stepQueue.front();
            stepQueue.pop();
            // check if reach goal
            if (arr[cur_idx] == 0)
            {
                return true;
            }
            // update next step
            int directions[] = {1, -1};
            for (auto direction : directions)
            {
                int nextStep = cur_idx + arr[cur_idx] * direction;
                if (0 <= nextStep && nextStep < n &&
                    stepVisited.find(nextStep) == stepVisited.end())
                {
                    stepVisited.insert(nextStep);
                    stepQueue.push(nextStep);
                }
            }
        }
        return false;
    }
};