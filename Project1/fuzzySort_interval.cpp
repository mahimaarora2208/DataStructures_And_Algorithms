#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <gnuplot-iostream.h>

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
    Interval pivot = intervals[random];
    swap(intervals[random], intervals[high]); // move the pivot to the end

    int i = low - 1;
    int k = low;
    double a = pivot.start;
    double b = pivot.end;
    for (int j = low + 1; j <= high - 1; j++)
    {
        if (intervals[j].end < a)
        {
            i++;
            k = i + 2;
            swap(intervals[i], intervals[j]);
            swap(intervals[k], intervals[j]);
        }
        if (intervals[j].end >= a || intervals[j].start <= b)
        {
            a = max(intervals[j].start, a);
            b = min(intervals[j].end, b);
            k++;
            swap(intervals[k], intervals[j]);
        }
    }
    swap(intervals[i + 1], intervals[high]);
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

void plot_graph_time_complexity(int n)
{
    Gnuplot gp;
    // set the x and y labels
    gp << "set xlabel 'n'\n";
    gp << "set ylabel 'Time (ms)'\n";

    // create a vector to store the x and y values
    std::vector<std::pair<int, double>> data;

    // loop over a range of n values and measure the execution time of the fibonacci function
    for (int n = 0; n <= 20; n++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        fibonacci(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        data.push_back(std::make_pair(n, duration.count() / 1000.0));
    }

    // plot the data using GNU Plot
    gp << "plot '-' with lines title 'Time Complexity'\n";
    gp.send(data);
    gp.flush();
}

int main()
{
    // vector<Interval> intervals = {{1, 5}, {3, 7}, {6, 10}, {8, 12}, {11, 15}};
    vector<Interval> intervals;
    Interval interval;
    ifstream infile("small_overlap.txt");
    int n = 10;

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