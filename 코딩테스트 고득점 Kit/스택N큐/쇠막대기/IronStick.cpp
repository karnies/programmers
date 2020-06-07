#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int length = arrangement.length();

    // The number of sticks increases when the parentheses are opened.
    int nStick = 0;
    for(int i = 0 ; i < length; i++)
    {
        if(arrangement[i] == '(')
            nStick++;
        else
        {
            // When the brackets are closed, the number of sticks decreases.
            nStick--;

            // For lasers, increase the number by the number of sticks, 
            // and for the end of the stick, increase 1.
            if(arrangement[i-1] == '(')
                answer += nStick;
            else
                answer++;
        }
        
    }



    return answer;
}
