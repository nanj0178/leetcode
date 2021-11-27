#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class FirstUnique
{
public:
    FirstUnique(vector<int> &nums)
    {
        // O(nums.size())
        // init data
        for (auto num : nums)
        {
            add(num);
        }
    }

    int showFirstUnique()
    {
        // O(1) amortized
        // get first candidate value and the total count of candidate value
        int candidateValue = candidateQueue.front();
        int valueCount = numberCountMap[candidateValue];
        // clear invalid value till valueCount is 1 or queue is empty
        while (!candidateQueue.empty() && valueCount != 1)
        {
            // remove invalid value
            candidateQueue.pop();
            // update next possible candidate
            candidateValue = candidateQueue.front();
            valueCount = numberCountMap[candidateValue];
        }
        // check if there is still a value in the queue.
        // Yes: return candidateValue
        // No: return -1
        if (candidateQueue.empty())
        {
            return -1;
        }
        return candidateValue;
    }

    void add(int value)
    {
        // O(1)
        // update the count of value
        numberCountMap[value]++;
        int valueCount = numberCountMap[value];
        // only consider count equal 1
        if (valueCount == 1)
        {
            candidateQueue.push(value);
        }
    }

private:
    queue<int> candidateQueue;
    unordered_map<int, int> numberCountMap;
};
int main()
{
}