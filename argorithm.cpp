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

    vector<int> gift_index(n);
    for (int i = 0; i < n; ++i) {
        gift_index[i] = total_given[i] - total_received[i];
    }

    vector<int> next_receive(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a_to_b = gifts_count[i][j];
            int b_to_a = gifts_count[j][i];
            if (a_to_b != b_to_a) {
                if (a_to_b > b_to_a) {
                    next_receive[i]++;
                } else {
                    next_receive[j]++;
                }
            } else {
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
