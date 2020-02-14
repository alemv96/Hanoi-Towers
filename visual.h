
#include<iostream>
using namespace std;

//constants
const int MAX_TOWERS = 3;

//structures

struct Disk{
    int disk_number;
    char color;              // Might change the data type.
    int width;
    int position;           // This would depend on which tower the disk is
};

struct Tower{
    Disk * disks[];         // This pointer would let me have an array without
                            // declaring the size at the beginning
    int n_disks;

};


int main(){
  Tower tower1, tower2, tower3;  // No matter what we will always have 3 towers
  return;
}
