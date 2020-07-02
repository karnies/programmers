#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // make min_heap and mix first and second element.
    // and then insert new_food's scoville into vector
    priority_queue <int, vector<int>, greater<int> > min_heap(scoville.begin(), scoville.end()); 

    while(min_heap.size() > 1)
    {
        int min = min_heap.top();
        if(min >= K)
            break;
        min_heap.pop();

        int min2 = min_heap.top();
        min_heap.pop();

        min_heap.emplace(min + min2*2);

        answer++;
    }

    if(min_heap.size() == 1 && min_heap.top() < K)
        return -1;
        
    return answer;
}


// int solution(vector<int> scoville, int K) {
//     int answer = 0;
    
//     // make min_heap and mix first and second element.
//     // and then insert new_food's scoville into vector
//     make_heap(scoville.begin(), scoville.end(), greater<int>());
//     while(!scoville.empty())
//     {
//         pop_heap(scoville.begin(), scoville.end(), greater<int>());
//         int min = scoville.back();
//         if(min >= K)
//             break;
//         scoville.pop_back();

//         pop_heap(scoville.begin(), scoville.end(), greater<int>());
//         int min2 = scoville.back();
//         scoville.pop_back();

//         scoville.emplace_back(min + min2*2);

//         answer++;
//     }
//     return answer;
// }
