#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> orders(n);
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        orders[i] = make_pair(s, d);
    }

    sort(orders.begin(), orders.end());

    vector<int> end_times;
    for (int i = 0; i < n; i++) {
        int s = orders[i].first;
        int d = orders[i].second;

        bool assigned = false;
        for (int j = 0; j < end_times.size(); j++) {
            if (end_times[j] <= s) {
                end_times[j] = d;
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            end_times.push_back(d);
        }
    }

    cout << end_times.size() << endl;

    return 0;
}
