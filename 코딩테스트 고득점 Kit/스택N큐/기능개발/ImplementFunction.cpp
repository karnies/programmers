#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int N = progresses.size();

    // calculate date of all task complete
    queue<int> q;
    for(int i =0; i < N ; i++)
    {
        q.emplace((100 - progresses[i] + speeds[i] - 1) / speeds[i]);
    }

    while(true)
    {
        int num_task = 1;
        int d = q.front();
        q.pop();
        while(!q.empty())
        {
            int td = q.front();
            if(d >= td)
            {
                q.pop();
                num_task++;
            }
            else
            {
                break;
            }
            
        }

        answer.emplace_back(num_task);
        if(q.empty())
            break;
    }
    return answer;
}
