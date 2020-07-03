#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    // import maximum supplies in remained period
    int N = dates.size();
    priority_queue<int> max_heap;
    
    if(stock == k)
        return 0;
        
    for(int i=0; i<N; i++)
    {
        if(stock >= dates[i])
        {
            max_heap.emplace(supplies[i]);
            continue;
        }
        
        while(!max_heap.empty())
        {
            int t = max_heap.top();
            max_heap.pop();
            stock += t;
            answer++;

            if(stock >= k)
                return answer;

            if(stock >= dates[i])
                break;
        }
        max_heap.emplace(supplies[i]);
    }

    while(!max_heap.empty())
    {
        int t = max_heap.top();
        max_heap.pop();
        stock += t;
        answer++;

        if(stock >= k)
            break;
    }

    return answer;
}
