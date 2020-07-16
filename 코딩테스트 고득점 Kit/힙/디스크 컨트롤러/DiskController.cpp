#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // sort jobs by start_time
    std::sort(jobs.begin(), jobs.end());

    // use min_heap
    priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > min_heap;

    int curr_time = 0;
 //   min_heap.emplace(vector<int>{jobs[0][1], jobs[0][0]});
    int i = 0;
    int N = jobs.size();
    while(true)
    {
        if(!min_heap.empty())
        {
            vector<int> t = min_heap.top();
            min_heap.pop();

            curr_time += t[0];
            answer += (curr_time - t[1]);
        }
        // insert all jobs until current job's end time
        for(;i<N; i++)
        {
            if(jobs[i][0] <= curr_time)
                min_heap.emplace(vector<int>{jobs[i][1], jobs[i][0]});
            else
                break;
        }

        if(min_heap.empty() && i < N)
        {
            min_heap.emplace(vector<int>{jobs[i][1], jobs[i][0]});
            curr_time = jobs[i][0];
            i++;
        }
        else if(!min_heap.empty())
        {
            continue;
        }
        else
        {
            break;            
        }
        
    }

    return answer / N;
}
