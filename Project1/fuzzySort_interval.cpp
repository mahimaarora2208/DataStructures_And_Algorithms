#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

struct Interval
{
    double start;
    double end;
};

// Uses Fuzzy Partition to find Overlap in Intervals
Interval randomized_partition(vector<Interval> &intervals, int low, int high)
{
    Interval result;
    int random = low + rand() % (high - low + 1); // Generates a random pivot
    Interval pivot = intervals.at(random);
    swap(intervals.at(random), intervals.at(high)); // move the pivot to the end


    swap(intervals.at(low), intervals.at(random)); // move the pivot to the start

    int i = low - 1;
    int k = low;
    double a = pivot.start;
    double b = pivot.end;
    for (int j = low + 1; j <= high - 1; j++)
    {
        if (intervals.at(j).end < a)
        {
            i++;
            k = i + 1;
            swap(intervals.at(i), intervals.at(j));
            swap(intervals.at(k), intervals.at(j));
        }
        if (intervals.at(j).end >= a || intervals.at(j).start <= b)
        {
            a = max(intervals.at(j).start, a);
            b = min(intervals.at(j).end, b);
            k++;
            swap(intervals.at(k), intervals.at(j));
        }
    }
    swap(intervals.at(i + 1), intervals.at(high));
    result.start = i + 1;
    result.end = k + 1;
    return result;
}

void quicksort(vector<Interval> &intervals, int low, int high)
{
    if (low < high)
    {
        Interval pi = randomized_partition(intervals, low, high);
        quicksort(intervals, low, pi.start - 1);
        quicksort(intervals, pi.end + 1, high);
    }
}

void fuzzy_sort(vector<Interval> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return;
    quicksort(intervals, 0, n - 1);
}

int main()
{
    vector<Interval> intervals;
    Interval interval;
    ifstream infile("small_overlap.txt");
    int n = 4;

    if (infile.is_open())
    {
        // Use N intervals for testing - total 10^6
        for (int i = 0; i < n && infile >> interval.start >> interval.end; i++)
        {
            intervals.push_back(interval);
        }
        infile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    fuzzy_sort(intervals);
    for (Interval i : intervals)
    {
        cout << "[" << setprecision(10) << i.start << ", " << setprecision(10) << i.end << "]" << endl;
    }
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <fstream>
// #include <iomanip>
// #include <chrono>
// #include <gnuplot-iostream.h>

// using namespace std;

// struct Interval
// {
//     double start;
//     double end;
// };

// // Uses Fuzzy Partition to find Overlap in Intervals
// Interval randomized_partition_old(vector<Interval> &intervals, int low, int high)
// {
//     Interval result;
//     int random = low + rand() % (high - low + 1); // Generates a random pivot
//     Interval pivot = intervals[random];
//     swap(intervals[random], intervals[high]); // move the pivot to the end

//     int i = low - 1;
//     int k = low;
//     double a = pivot.start;
//     double b = pivot.end;
//     for (int j = low + 1; j <= high - 1; j++)
//     {
//         if (intervals[j].end < a)
//         {
//             i++;
//             k = i + 2;
//             swap(intervals[i], intervals[j]);
//             swap(intervals[k], intervals[j]);
//         }
//         if (intervals[j].end >= a || intervals[j].start <= b)
//         {
//             a = max(intervals[j].start, a);
//             b = min(intervals[j].end, b);
//             k++;
//             swap(intervals[k], intervals[j]);
//         }
//     }
//     swap(intervals[i + 1], intervals[high]);
//     result.start = i + 1;
//     result.end = k + 1;
//     return result;
// }

// // Uses Fuzzy Partition to find Overlap in Intervals
// Interval randomized_partition(vector<Interval> &intervals, int low, int high)
// {
//     Interval result;
//     int random = low + rand() % (high - low + 1); // Generates a random pivot
//     Interval pivot = intervals.at(random);
//     swap(intervals.at(random), intervals.at(high)); // move the pivot to the end
//     swap(intervals.at(low), intervals.at(high)); // move the pivot to the end

//     int i = low - 1;
//     int k = low;
//     double a = pivot.start;
//     double b = pivot.end;
//     for (int j = low + 1; j <= high - 1; j++)
//     {
//         if (intervals.at(j).end < a)
//         {
//             i++;
//             k = i + 1;
//             swap(intervals.at(i), intervals.at(j));
//             swap(intervals.at(k), intervals.at(j));
//         }
//         if (intervals.at(j).end >= a || intervals.at(j).start <= b)
//         {
//             a = max(intervals.at(j).start, a);
//             b = min(intervals.at(j).end, b);
//             k++;
//             swap(intervals.at(k), intervals.at(j));
//         }
//     }
//     swap(intervals.at(i + 1), intervals.at(high));
//     result.start = i + 1;
//     result.end = k + 1;
//     return result;
// }
// void quicksort(vector<Interval> &intervals, int low, int high)
// {
//     if (low < high)
//     {
//         Interval pi = randomized_partition(intervals, low, high);
//         quicksort(intervals, low, pi.start - 1);
//         quicksort(intervals, pi.end + 1, high);
//     }
// }

// void fuzzy_sort(vector<Interval> &intervals)
// {
//     int n = intervals.size();
//     if (n == 0)
//         return;
//     quicksort(intervals, 0, n - 1);
// }

// int main()
// {
//     vector<Interval> intervals_main;
//     Interval interval;
//     ifstream infile("small_overlap.txt");
//     vector<pair<int, double>> plotData;
//     vector<Interval> nth_elements_interval;

//     // Read file
  
//         // Use N intervals for testing - total 10^6
//         while (infile >> interval.start >> interval.end)
//         {
//             intervals_main.push_back(interval);
//         }
//         infile.close();
    
//     int length = intervals_main.size();
   
//     // calculate time interval
//     for (int n = 0; n <= 3; n++)
//     {   
//         // vector<Interval> nth_elements_interval(intervals.begin(), intervals.begin() + n);
       
//         nth_elements_interval.push_back(intervals_main[n]);
        
//         // for (Interval i : nth_elements_interval)
//         // {
//         // cout << "[" << setprecision(10) << nth_elements_interval[n].start << ", " << setprecision(10) << nth_elements_interval[n].end << "]" << endl;
//         // }
//         // cout << nth_elements_interval.at(1) << endl;
//         auto start = chrono::high_resolution_clock::now();
//         fuzzy_sort(nth_elements_interval);
//         auto end = chrono::high_resolution_clock::now();
//         auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//         plotData.push_back(make_pair(n, duration.count() / 1000.0));
//     }
    
//     // print n and duration

//     // for (auto ele : plotData)
//     // {
//     //     cout <<  setprecision(5) << ele.first << " " << setprecision(5) << ele.second << endl; 
//     // }
    
//     for (Interval i : nth_elements_interval)
//     {
//         // cout << "[" << setprecision(7) << i.start << ", " << setprecision(7) << i.end << "]" << endl;
//         cout << "["  << i.start << ", " << i.end << "]" << endl;
//     }
//     return 0;
// }