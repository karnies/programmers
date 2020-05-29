#include <string>
#include <vector>
#include <stack>
//#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int n = heights.size();

    // make stack for height and idx
    stack<pair<int,int>> st;

    for(int i = 0; i < n ; i++)
    {
        int hgt = heights[i];
        while(!st.empty())
        {
            pair<int, int> p = st.top();
            st.pop();

            if(hgt < p.first)
            {
                answer.emplace_back(p.second);
                st.emplace(p);
                st.emplace(make_pair(hgt, i + 1));
                break;
            }
        }

        if(st.empty())
        {
            answer.emplace_back(0);
            st.emplace(make_pair(hgt, i+1));
        }
    }

    return answer;
}
