
#include <iostream>
//#include "visual.h"
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
    Disk * disks[];         // This pointer would let me have an array without
                            // declaring the size at the beginning
    int n_disks;

};

//prototypes
void solution(int n_to_move , int source , int destination , int spare);
int get_disks();
void user_menu();
void play_puzzle();
void initialize_towers(Tower tower1, Tower tower2 , Tower tower3 ,int n_disks);

//Main function
int main() {
	int n_disk = get_disks();
  Tower tower1, tower2, tower3;               //Hanoi towers.

  //function calls
	  initialize_towers();
		user_menu();
		solution(n_disk , SOURCE , DESTINATION , SPARE);

  return 0;
}

void initialize_towers(Tower tower1, Tower tower2 , Tower tower3 ,int n_disks){
			tower1.disks = new int[n_disks];

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
				solution(n_disks, SOURCE , DESTINATION, SPARE);
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
  if(n_to_move == 1){
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
