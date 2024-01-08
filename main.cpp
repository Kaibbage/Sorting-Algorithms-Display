//Kai Sundararaj
//June 18, 2021
//ICS4U
//Mrs. Cullum
//This program generates 200 random numbers from 1 to 100
//The user can then select 3 different ways to sort the numbers
//The program will show the user the numbers sorted at the end
//While they are being sorted, instead of showing the changes in the numbers each time (too hard to see anything, too many numbers)
//The user will see an allegro picture using lines and colours to represent the sizes of the numbers being sorted in their different ways
//The program will also show the user the number of swaps and comparisons made

#include <iostream>
#include <vector>
#include "sorters.h"

using namespace std;

int main()
{
    //Initializing variables for the numbers, what sort to do, and how many numbers
    int type = 0;
    int x = 200;
    vector <int> nums(x);


    //Asking user and taking down answer
    cout << "What type of sorting would you like to do?" << endl;
    cout << "1. Quick sort:" << endl;
    cout << "2. Bubble sort:" << endl;
    cout << "3. Insertion sort:" << endl;
    cin >> type;

    //Declaring class
    sorters sorters1;

    //Randomizing all the numbers
    sorters1.random(x, nums);

    //Displaying the basic blank map
    sorters1.dispmap();

    //Choosing which sort to do
    if(type == 1){
        sorters1.quicks(nums, x, 0, x-1);
    }
    else if(type == 2){
        sorters1.bubbles(nums, x);
    }
    else if(type == 3){
        sorters1.inserts(nums, x);
    }

    int i = 0;

    cout << "List:" << endl;

    //Showing the user the sorted numbers, I figured it would be a waste to show all the numbers after each step, 200 numbers is so many, you won't be able to see anything
    while(i < x/5){
        if(nums[i] < 10){
            cout << " " << nums[i] << "       " << nums[x/5 + i] << "       " << nums[2*x/5 +i] << "       " << nums[3*x/5 + i] << "       " << nums[4*x/5 +i] << "       " << endl;
        }
        else{
            cout << nums[i] << "       " << nums[x/5 + i] << "       " << nums[2*x/5 +i] << "       " << nums[3*x/5 + i] << "       " << nums[4*x/5 +i] << "       " << endl;
        }
        i++;
    }

    //Telling user how many comparisons done
    cout << "Number of comparisons done:" << sorters1.getcomparisons() << endl;
    cout << "Number of swaps done:" << sorters1.getswitches() << endl;


    return 0;


}
