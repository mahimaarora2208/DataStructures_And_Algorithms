#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

struct Interval
{
    double start;
    double end;
};

int partition_right(vector<Interval>& A,int piv_start,int p,int r){
    int i = p - 1;
    for (int j = p;j < r;j++){
        if (A.at(j).start <= piv_start){
            i++;
            swap(A.at(i),A.at(j));
        }
    }
    swap(A.at(i+1),A.at(r));
    return i+1;
}

int partition_left(vector<Interval>&A,int piv_end,int p,int r){
    int i = p-1;
    for (int j{p};j<r;j++){
        if (A[j].end < piv_end){
            i++;
            swap(A.at(i),A.at(j));
        }
    }
    swap(A.at(i+1),A.at(r));
    return i+1;
}



// Uses Fuzzy Partition to find Overlap in Intervals
Interval find_intersection(vector<Interval> &intervals, int low, int high)
{
    int random = low + rand() % (high - low + 1); // Generates a random pivot
    Interval pivot = intervals.at(random);

    swap(intervals.at(random), intervals.at(high)); // move the pivot to the end

    for (int j = low; j < high - 1; j++)
    {
        if (intervals.at(j).start <= pivot.end && intervals.at(j).end >= pivot.start)
        {
            if(intervals.at(j).start > pivot.start){
                pivot.start = intervals.at(j).start;
            }
            if(intervals.at(j).end < pivot.end){
                pivot.end = intervals.at(j).end;
            }
        }
    }
      
    return pivot;
}

void quicksort(vector<Interval> &intervals, int low, int high)
{
    if (low < high)
    {
        Interval piv = find_intersection(intervals, low, high);
        auto t = partition_right(intervals, piv.start, low, high);
        auto q = partition_left(intervals, piv.end, low, t);
        quicksort(intervals, low, q - 1);
        quicksort(intervals, t + 1, high);
    }
}

void fuzzy_sort(vector<Interval> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return;
    quicksort(intervals, 0, n - 1);
}

// vector<Interval> read_file(string filename, int size) {
//     ifstream infile;
//     vector<Interval> data;
//     int num = 0;
//     infile.open(filename);
//     if (infile.fail()) {
//         cout << "error" << '\n';
//         return {};
//     }
//     while (!infile.eof() && num < size) {
//         Interval x;
//         infile >> x.start >> x.end;
//         data.push_back(x);
//         ++num;
//     }
//     infile.close();
//     return data;
// }

int main()
{ 
    for (int i = 1; i < 1000; i++)
    {
        vector<Interval> intervals_all;
        vector<pair<int, double>> plotData;
        Interval interval;
        int num = 0;
        int size = 10 * i;

        ifstream infile("all_overlap.txt");
            if (infile.is_open())
        {
            // Use first n intervals to run fuzzy-sort
            while(infile >> interval.start >> interval.end && num < size)
            {
                intervals_all.push_back(interval);
                num++;
            }
            infile.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
            return 1;
        }
        auto start = chrono::high_resolution_clock::now();
        fuzzy_sort(intervals_all);   
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        plotData.push_back(make_pair(size, duration.count() / 1000.0));
        
        
        // for (Interval i : intervals_all)
        // {
        //     cout << "[" << setprecision(10) << i.start << ", " << setprecision(10) << i.end << "]" << endl;
        // }
        
        // print n and duration
        for (auto ele : plotData)
        {
            // cout <<  setprecision(5) << ele.first << " " << setprecision(5) << ele.second << endl; 
            // cout <<  setprecision(5) << ele.first << endl; 
            cout <<  setprecision(5) << ele.second << endl; 
        }
    }
        
        return 0;
    // print all data
    
}