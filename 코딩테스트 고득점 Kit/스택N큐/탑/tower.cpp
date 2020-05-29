#include <string>
#include <vector>
//#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int n = heights.size();

    // vector for last position of height;
    vector<int> pos(100, 0);
    for(int i = 0; i < n ; i++)
    {
        //cout << " i : " << i << " height : " << heights[i] << endl;
        //cout << " pos : " << pos[heights[i] - 1] << endl;
        answer.emplace_back(pos[heights[i] - 1]);

        // update last postion
        if(heights[i]>1)
        {
            for(int t = 0 ; t < heights[i] - 1; t++)
                pos[t] = i + 1;
        }
    }

    return answer;
}
