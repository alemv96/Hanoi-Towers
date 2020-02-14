/*
  file: hanoi.cpp
  Authors: Alex Martinez Veloz , Brandon Pack
  Date: 02/12/2020
  Description: This file contain the classes that would print the
 */

#include <iostream>
#include "bar.h"

using namespace std;

int const SOURCE = 1;
int const SPARE = 2;
int const DESTINATION = 3;
int const MAX_TOWERS = 3;


//structures
struct Disk{
    int disk_number;
    char color;              // Might change the data type.
    int width;
    int position;           // This would depend on which tower the disk is

};

struct Tower{
    Disk disks[1024];         // Array of disks
                             // declaring the size at the beginning
    int n_disks;

};

//prototypes
void solution(int n_to_move, int source , int destination , int spare);
int get_disks();
void user_menu();
void play_puzzle();
void disk_initializer(Tower tower1, Tower tower2 , Tower tower3, int n_disks);
float get_width(int disk_number);

//Main function
int main() {
  //variables
  int n_disks = get_disks();
  Tower tower1, tower2, tower3;               //Hanoi towers.

  //function calls
        disk_initializer(tower1, tower2, tower3 , n_disks);
	user_menu();
        //solution(n_disk , SOURCE , DESTINATION , SPARE);

  return 0;
}

//This function assigns a width to each disk, based on its number...
float get_width(int disk_number){
    return disk_number*2;       // check this when printing on screen, we might have to change this 
                                // depending on how it looks
}

//this function initialize Tower 1 and fill it up with disks...
void disk_initializer(Tower tower1, Tower tower2, Tower tower3, int n_disks){
    tower1.n_disks = n_disks;                          // Tower 1 will always have the disks at first.
    tower2.n_disks = 0;
    tower3.n_disks = 0;

         //initialize the tower number 1. 
         for (int disk_count = 1 ; disk_count <= n_disks ; disk_count ++){
             tower1.disks[disk_count].n_disk = disk_count;
             tower1.disks[disk_count].color = 'u';       //for now the color it's going to be undefined.
             tower1.disks[disk_count].position = 1;
             tower1.disks[disk_count].width = get_width(disk_count);             
         }

}

void play_puzzle(){

 
}

//Starting menu
void user_menu(){
	char option;

			cout << "1) Play puzzle >> " << endl;
			cout << "2) See solution to puzzle >> " << endl;
			cin >> option;

			//
			if (option = '1') {
				play_puzzle();
			}
			//show the solution
			else if(option = '2'){
				//solution(n_disks, SOURCE , DESTINATION, SPARE);
			}
			else
			    cout << "Not a valid entry";



}

//get disk amount
int get_disks(){
  int disks;
    cout << "Enter number of disks >>";
    cin >> disks;
  return disks;
}

//main loop for solutions
void solution(int n_to_move , int source , int destination , int spare){
  cout << "Algorithm" << endl;
  cout << "==================================" << endl;
//  if(n_to_move == 1){
  //}

}
  /*
	if(n_to_move == 1){
	   cout << "Move from tower " << source << " to tower " << destination << endl;
	   return;
  }
  move(n_to_move - 1 , source , spare, destination);
  move(1 , source , destination , spare);
  move(n_to_move - 1 , spare , destination , source);
}
  */
