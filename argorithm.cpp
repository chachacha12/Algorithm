#include <string>
#include <vector>
using namespace std;

// 시간 문자열(mm:ss)을 초 단위로 변환
int timeToSeconds(string timeStr) {
    int minutes = stoi(timeStr.substr(0, 2));
    int seconds = stoi(timeStr.substr(3, 2));
    return minutes * 60 + seconds;
}

// 초 단위 시간을 mm:ss 형식으로 변환
string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    string minutesStr = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
    string secondsStr = (seconds < 10) ? "0" + to_string(seconds) : to_string(seconds);
    
    return minutesStr + ":" + secondsStr;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 각 시간을 초 단위로 변환
    int videoLength = timeToSeconds(video_len);
    int currentPosition = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);
    
    // 오프닝 구간에 있는지 확인하고 처리
    if (currentPosition >= opStart && currentPosition <= opEnd) {
        currentPosition = opEnd;
    }
    
    // 각 명령어 처리
    for (string command : commands) {
        if (command == "prev") {
            // 10초 전으로 이동
            if (currentPosition < 10) {
                currentPosition = 0;
            } else {
                currentPosition -= 10;
            }
        } else if (command == "next") {
            // 10초 후로 이동
            if (currentPosition + 10 > videoLength) {
                currentPosition = videoLength;
            } else {
                currentPosition += 10;
            }
        }
        
        // 명령 후에 오프닝 구간에 있는지 확인하고 처리
        if (currentPosition >= opStart && currentPosition <= opEnd) {
            currentPosition = opEnd;
        }
    }
    
    return secondsToTime(currentPosition);
}