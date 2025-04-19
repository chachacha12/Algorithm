#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    unordered_map<string, int> idx;
    idx.reserve(n);
    for (int i = 0; i < n; ++i) {
        idx[friends[i]] = i;
    }

    vector<vector<int>> gifts_count(n, vector<int>(n, 0));
    vector<int> total_given(n, 0), total_received(n, 0);

    for (auto &s : gifts) {
        auto space_pos = s.find(' ');
        string a = s.substr(0, space_pos);
        string b = s.substr(space_pos + 1);
        int i = idx[a], j = idx[b];
        gifts_count[i][j]++;
        total_given[i]++;
        total_received[j]++;
    }

    // Compute gift index = given - received
    vector<int> gift_index(n);
    for (int i = 0; i < n; ++i) {
        gift_index[i] = total_given[i] - total_received[i];
    }

    // Next month receive counts
    vector<int> next_receive(n, 0);

    // For each unordered pair
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a_to_b = gifts_count[i][j];
            int b_to_a = gifts_count[j][i];
            if (a_to_b != b_to_a) {
                // One gave more
                if (a_to_b > b_to_a) {
                    // i gave more to j => i receives one
                    next_receive[i]++;
                } else {
                    // j gave more to i => j receives one
                    next_receive[j]++;
                }
            } else {
                // No direct bias or no history: compare gift index
                if (gift_index[i] != gift_index[j]) {
                    if (gift_index[i] > gift_index[j]) {
                        next_receive[i]++;
                    } else {
                        next_receive[j]++;
                    }
                }
            }
        }
    }

    return *max_element(next_receive.begin(), next_receive.end());
}
