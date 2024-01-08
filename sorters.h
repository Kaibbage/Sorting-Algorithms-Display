
#pragma once
#include <vector>
#include <iostream>

using namespace std;


class sorters{

public:
    //Constructor and Destructor
    sorters();
    ~sorters();

    //Random function
    void random(int &x, vector <int> &nums);

    //Allegro functions
    void dispmap();
    void dispdata(vector <int> &nums, int &x);

    //Function to check if the vector has been sorted
    bool sorted(vector <int> &nums, int &x);

    //Sorters
    void bubbles(vector <int> &nums, int &x);
    void quicks(vector <int> &nums, int &x, int x0, int x199);
    void inserts(vector <int> &nums, int &x);

    //Getters for switches and comparisons
    int getswitches();
    int getcomparisons();

private:

    //Initializing variables for switches and comparisons
    int switches = 0;
    int comparisons = 0;





};

