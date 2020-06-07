#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int N = priorities.size();
    // make queue for  priorities and index
    queue<pair<int, int>> q;
    for(int i = 0; i<N; i++)
    {
        q.emplace(make_pair(priorities[i], i));
    }
    // sort priorities
    sort(priorities.begin(), priorities.end(), greater<int>());
    // for all elements in queue
    int idxPrio = 0;
    int mx = priorities[idxPrio];
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        // compare current maximum priority
        if(mx > p.first)
        {
            // if smaller, go back
            q.emplace(p);
        }    
        else
        {
            // if equal, answer++ and compare with location
            answer++;
            if(p.second == location)
                break;
            // delete current maximum prior
            idxPrio++;
            mx = priorities[idxPrio];
        }
        
    }

    return answer;
}
