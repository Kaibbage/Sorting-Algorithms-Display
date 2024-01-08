#include "sorters.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>

using namespace std;

//Constructor and Deconstructor
sorters::sorters(){
}

sorters::~sorters(){
}

//Variable to randomize numbers
void sorters::random(int &x, vector <int> &nums){
    srand(time(nullptr));
    int i = 0;

    while(i < x){
        //Randomizing for all 200 numbers, values range from 1 to 100
        nums[i] = rand() % 100 + 1;
        i++;
    }

}

//Bubble sort
void sorters::bubbles(vector <int> &nums, int &x){
    int a = 0;
    int b = 0;

    //200 runthroughs
    while(b < x){
    a = 0;
    //Displaying data in allegro
    dispdata(nums, x);
        //Switching if they need to be switched each time, keeping track of switches and comparisons
        while(a < x - 1){
            comparisons++;
            if(nums[a] >= nums[a+1]){
                swap(nums[a], nums[a+1]);
                switches++;
            }
            a++;

        }

        b++;
    }
    //Displaying data one last time to see last frame in allegro
    dispdata(nums, x);
}

//Quicksort
void sorters::quicks(vector <int> &nums, int &x, int x0, int x199){
    int a = x0;
    int b = x0;
    int pivot = nums[x199];
    static bool stop = false;

    //Displaying data in allegro
    dispdata(nums, x);


    //Quicksorting if it is not yet done
    if(x0 < x199 && stop == false){
        while(a < x199){
            comparisons++;
            //Finding a point at the end and organizing everything lower to be lower than that point (everything higher will be then higher at the end naturally)
            if(nums[a] < pivot){
                swap(nums[a], nums[b]);
                switches++;
                b++;
            }
            a++;
        }
        //Moving point used as reference for higher or lower to its rightful spot
        swap(nums[b], nums[x199]);
        switches++;

        //Outputting pivot information and what place in vector the pivot is at
        cout << pivot << "  " << x199 << endl;

        //Recursive function for new quicksort in the top part (and then the next top part and the next top part until it has sorted that part) then it moves on to bottom of top top top part and so on
        //Until bottom of bottom bottom bottom part
        quicks(nums, x, b+1, x199);

        //Recursive function for bottom part, comes after top part
        quicks(nums, x, 0, b-1);
    }

    //Stopping the recursive function if the vector is sorted
    if(sorted(nums, x) == true){
        stop = true;
    }


}

//Insertion sorting, sees each new point and compares it to where it should go in all the points behind it
void sorters::inserts(vector <int> &nums, int &x){
    int a = 0;
    int b = 0;
    int mover;
    while(a < x){
        //Setting point being moved to its rightful place so far as the lowest number, then increasing
        mover = nums[a];
        //Setting comparing point to start one point below the number being compared to, then moves down from there
        b = a-1;

        //Displaying data in allegro
        dispdata(nums, x);

        //Outputting the line it is currently moving
        cout << a << endl;

        //Checking while nums[b] is still a comparable value
        while (b >= 0){
            comparisons++;
            //Checking if value being compared should be moved up, therefore moving value mover to its rightful spot so far
            //If statement works because everything below the mover has already been sorted, once it reaches end, it is the rightful spot
            if(nums[b] > mover){
                swap(nums[b], nums[b+1]);
                switches++;
            }
            //Setting b lower
            b--;
        }
        //Setting a higher
        a++;
    }

    //Displaying data again one last time to see last frame
    dispdata(nums, x);
}

static ALLEGRO_COLOR white;

//Displaying basic map
void sorters::dispmap(){
    al_init();
    al_init_primitives_addon();

    white = al_map_rgb(255, 255, 255);

    ALLEGRO_DISPLAY *display = al_create_display(800, 602);
    al_clear_to_color(white);

    al_flip_display();

}

static ALLEGRO_COLOR yellow;
static ALLEGRO_COLOR orange;
static ALLEGRO_COLOR red;
static ALLEGRO_COLOR green;
static ALLEGRO_COLOR blue;

//Displaying lines for value in allegro, colour changes too
void sorters::dispdata(vector <int> &nums, int &x){
    int x1 = 0;

    white = al_map_rgb(255, 255, 255);
    yellow = al_map_rgb(255, 219, 0);
    orange = al_map_rgb(255, 150, 0);
    red = al_map_rgb(255, 0, 0);
    green = al_map_rgb(0, 255, 0);
    blue = al_map_rgb(0,0,255);


    //from smallest to biggest: yellow, orange, red, green, blue
    while(x1 < x){
        al_draw_line(4*x1+1, 600, 4*x1+1, 0, white, 1);
        if(nums[x1] < 20){
            al_draw_line(4*x1+1, 600, 4*x1+1, 600 - 4 *nums[x1], yellow, 1);
        }
        else if(nums[x1] < 40){
            al_draw_line(4*x1+1, 600, 4*x1+1, 600 - 4 *nums[x1], orange, 1);
        }
        else if(nums[x1] < 60){
            al_draw_line(4*x1+1, 600, 4*x1+1, 600 - 4 *nums[x1], red, 1);
        }
        else if(nums[x1] < 80){
            al_draw_line(4*x1+1, 600, 4*x1+1, 600 - 4 *nums[x1], green, 1);
        }
        else if(nums[x1] <=100){
            al_draw_line(4*x1+1, 600, 4*x1+1, 600 - 4 *nums[x1], blue, 1);
        }

        x1++;
    }
    //Showing the display
    al_flip_display();
    al_rest(0.03);
}

//Checking if the data is properly sorted
bool sorters::sorted(vector <int> &nums, int &x){
    int a = 0;
    bool isSorted = true;

    while(a < x-1){
        if(nums[a] > nums[a+1]){
            isSorted = false;
        }
        a++;
    }
    return isSorted;
}

//Getters for comparisons and switches
int sorters::getcomparisons(){
    return comparisons;
}

int sorters::getswitches(){
    return switches;
}
