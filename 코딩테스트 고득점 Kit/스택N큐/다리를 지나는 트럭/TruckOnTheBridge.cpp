#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int N = truck_weights.size();
    queue<pair<int, int>> b;
    int sum = 0;
    // calculate current truck entering time
    for(int i = 0; i < N; i++)
    {
        int tw = truck_weights[i];

        // pop first truck in bridge is located end of bridge
        if(!b.empty())
        {
            pair<int,int>p = b.front();
            cout << "ans : " << answer << " p.first : " << p.first << " p.first : " << p.first<< endl;
            if(answer + 1 - p.first >= bridge_length)
            {
                b.pop();
                sum -= p.second;
            }
        }

        if(weight >= sum + tw)
        {
            answer++;
            cout << "1 : " << answer << ":" << tw << endl;
            b.emplace(make_pair(answer, tw));
            sum += tw;
        }
        else
        {
            // Add as much time as the last truck left the bridge
            while(true)
            {
                pair<int, int> p = b.front();
                b.pop();
                sum -= p.second;
                if(weight >= sum + tw)
                {
                    answer = answer + bridge_length - (answer - p.first);
                    cout << "2 : " << answer << ":" << tw << endl;
                    b.emplace(make_pair(answer, tw));
                    sum += tw;
                    break;
                }
            }
        }


    }

    answer += bridge_length;

    return answer;
}
