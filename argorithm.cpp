#include <string>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int row = (num - 1) / w;
    int col = (num - 1) % w;
    
    if (row % 2 == 1) {
        col = w - 1 - col;
    }
    
    int count = 1;
    
    for (int i = num + 1; i <= n; i++) {
        int curr_row = (i - 1) / w;
        int curr_col = (i - 1) % w;
        
        if (curr_row % 2 == 1) {
            curr_col = w - 1 - curr_col;
        }
        
        if (curr_col == col) {
            count++;
        }
    }
    
    return count;
}