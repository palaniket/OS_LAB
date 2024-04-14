#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;
// LRU Page Replacement Algorithm
int LRU(const vector<int>& pages, int capacity) {
    unordered_set<int> s;
    list<int> indexes;

    int pageFaults = 0;
    for (int page : pages) {
        if (s.size() < capacity) {
            if (s.find(page) == s.end()) {
                s.insert(page);
                indexes.push_front(page);
                pageFaults++;
            } else {
                indexes.remove(page);
                indexes.push_front(page);
            }
        } else {
            if (s.find(page) == s.end()) {
                int val = indexes.back();
                indexes.pop_back();
                s.erase(val);
                s.insert(page);
                indexes.push_front(page);
                pageFaults++;
            } else {
                indexes.remove(page);
                indexes.push_front(page);
            }
        }
    }
    return pageFaults;
}
int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;

    
    cout << "LRU Page Faults: " << LRU(pages, capacity) << endl;
    

    return 0;
}