#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <list>
#include <algorithm>
#include<unordered_map>
#include<limits>

using namespace std;



// Optimal Page Replacement Algorithm
int optimal(const vector<int>& pages, int capacity) {
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int pageFaults = 0;
    for (int i = 0; i < pages.size(); ++i) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                pageFaults++;
            }
            indexes[pages[i]] = i;
        } else {
            if (s.find(pages[i]) == s.end()) {
                int lru = INT16_MIN, val;
                for (auto it = s.begin(); it != s.end(); ++it) {
                    if (indexes[*it] > lru) {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                pageFaults++;
            }
            indexes[pages[i]] = i;
        }
    }
    return pageFaults;
}
int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;

 
    cout << "Optimal Page Faults: " << optimal(pages, capacity) << endl;

    return 0;
}