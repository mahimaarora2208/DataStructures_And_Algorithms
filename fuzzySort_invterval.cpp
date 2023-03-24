#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Interval {
    int start;
    int end;
    double overlap; // degree of overlap with reference interval
};

double jaccard_index(Interval a, Interval b, Interval ref) {
    int intersection_start = max(a.start, b.start);
    int intersection_end = min(a.end, b.end);
    int union_start = min(a.start, b.start);
    int union_end = max(a.end, b.end);
    
    double intersection = max(intersection_end - intersection_start + 1, 0);
    double union_ = union_end - union_start + 1;
    double overlap = intersection / union_;
    double ref_overlap = jaccard_index(ref, a, ref) + jaccard_index(ref, b, ref);
    
    return overlap / ref_overlap;
}

bool compare_intervals(Interval a, Interval b) {
    return a.overlap > b.overlap;
}

int partition(vector<Interval>& intervals, int low, int high) {
    int random = low + rand() % (high - low + 1); // choose a random pivot
    Interval pivot = intervals[random];
    swap(intervals[random], intervals[high]); // move the pivot to the end
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (intervals[j].overlap >= pivot.overlap) {
            i++;
            swap(intervals[i], intervals[j]);
        }
    }
    swap(intervals[i + 1], intervals[high]);
    return i + 1;
}

void quicksort(vector<Interval>& intervals, int low, int high) {
    if (low < high) {
        int pi = partition(intervals, low, high);
        quicksort(intervals, low, pi - 1);
        quicksort(intervals, pi + 1, high);
    }
}

void fuzzy_sort(vector<Interval>& intervals) {
    int n = intervals.size();
    if (n == 0) return;
    
    srand(time(NULL)); // seed the random number generator
    
    Interval ref = intervals[0];
    for (int i = 0; i < n; i++) {
        intervals[i].overlap = jaccard_index(intervals[i], ref, ref);
    }
    
    quicksort(intervals, 0, n - 1);
}

int main() {
    vector<Interval> intervals = {{1, 5}, {3, 7}, {6, 10}, {8, 12}, {11, 15}};
    fuzzy_sort(intervals);
    for (Interval i : intervals) {
        cout << "[" << i.start << ", " << i.end << "]" << endl;
    }
    return 0;
}