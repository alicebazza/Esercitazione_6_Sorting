#include <cmath> 
#include <iostream>
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono> 

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

int main(int argc, char *argv[])
{

    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 10;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;
        
   // inizializzazione dei vettori

    vector<int> v1(m);
    std::iota(v1.begin(), v1.end(), -4);

    // cout << "v1: " << endl;
    // cout << ArrayToString(v1) << endl;

    srand(2);
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX);

    // cout << "v2: " << endl;
    // cout << ArrayToString(v2) << endl;

    vector<int> v3(m, 0);
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

    // cout << "v3: " << endl;
    // cout << ArrayToString(v3) << endl;
    
    // valutazione dell'efficienza degli algoritmi
    unsigned int num_experiment = 100;
    
    double time_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_bubble_v1 /= num_experiment;

    cout << "Bubble Sort - v1: " << time_bubble_v1 << endl;

    double time_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_bubble_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_bubble_v2 << endl;

    double time_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_bubble_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_bubble_v3 << endl;

    double time_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_heap_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_heap_v1 << endl;

    double time_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_heap_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_heap_v2 << endl;
    
    double time_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_heap_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_heap_v3 << endl;

    return 0;
}

