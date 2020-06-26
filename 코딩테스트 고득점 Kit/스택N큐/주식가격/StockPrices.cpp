#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> st;
    int N = prices.size();
    answer.resize(N);
    // Stack until a price smaller than the previous price comes out.
    // If a current price smaller than the top of the stack appears, 
    // the price larger than the current price is removed from the stack.
    st.emplace(0);
    for(int i = 1; i < N - 1; i++)
    {
        while(!st.empty())
        {
            int t = st.top();
            if(prices[t] > prices[i])
            {
                answer[t] = i - t;
                st.pop();
            }
            else
            {
                break;
            }
        }

        st.emplace(i);
    }

    // process remains on stack
    while(!st.empty())
    {
        int t = st.top();
        answer[t] = N - 1 - t;
        st.pop();
    }
    answer[N-1] = 0;

    return answer;
}
