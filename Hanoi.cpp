/*
  file: hanoi.cpp
  Authors: Alex Martinez Veloz , Brandon Pack
  Date: 02/12/2020
  Description: This file contain the classes that would print the
 */

#include <iostream>
#include "bar.h"
#include <iomanip>
#include <cmath>

using namespace std;

int const SOURCE = 1;
int const SPARE = 2;
int const DESTINATION = 3;
int const MAX_TOWERS = 3;
bool const  EMPTY = false;
bool const WIN  = true;
bool const FILL = true;
int const NO_DISK = 0;

//structures
struct Disk{
    int disk_number;
    char color;              // Might change the data type.
    int width;
    int position;           // This would depend on which tower the disk is
    bool status;
};

struct Tower{
    Disk disks[1024];         // Array of disks
                             // declaring the size at the beginning
    int n_disks;

};

//prototypes
void solution(int n_to_move, int source , int destination , int spare);
int get_disks();
void user_menu(Tower tower[] , int n_disks);
void play_puzzle(Tower tower[] , int n_disks);
void game_initializer(Tower tower[] , int n_disks);
float get_width(int disk_number);
int get_source();
int get_destination();
bool check_for_win(Tower tower[] , int n_disks);

//Main function
int main() {
  //variables
  int n_disks = get_disks();
  Tower tower[MAX_TOWERS];               //Hanoi towers.

  //function calls
        game_initializer(tower, n_disks);
        user_menu(tower , n_disks);
        //solution(n_disk , SOURCE , DESTINATION , SPARE);

  return 0;
}

//This function assigns a width to each disk, based on its number...
float get_width(int disk_number){
    return disk_number*2;       // check this when printing on screen, we might have to change this 
                                // depending on how it looks
}

//this function initialize Tower 1 and fill it up with disks...
void game_initializer(Tower tower[], int n_disks){
    
         //initialize towers.
         
	for (int count_tower = 0 ; count_tower < MAX_TOWERS; count_tower ++){
           for (int disk_count = 0 ; disk_count < n_disks ; disk_count ++){
                
                tower[count_tower].disks[disk_count].width = get_width(disk_count);
                tower[count_tower].disks[disk_count].color = 'u'; //for now the color it's going to be undefined
		tower[count_tower].disks[disk_count].position = count_tower + 1;                      
   
                //This conditional will assign true if the disks are on tower one.            
                    if (count_tower == 0){  
                        tower[count_tower].disks[disk_count].status = FILL;
                        tower[count_tower].disks[disk_count].disk_number = disk_count + 1;
                    }else{
                        tower[count_tower].disks[disk_count].status = EMPTY;
                        tower[count_tower].disks[disk_count].disk_number = NO_DISK;
                    }
           }
        }
         
        //these couts print the towers (Only works for 3 to print)
        cout << tower[0].disks[0].status << setw(10) << tower[1].disks[0].status 
             << setw(10) << tower[2].disks[0].status << endl;
        cout << tower[0].disks[1].status << setw(10) << tower[1].disks[1].status
             << setw(10) << tower[2].disks[1].status << endl;
        cout << tower[0].disks[2].status << setw(10) << tower[1].disks[2].status
             << setw(10) << tower[2].disks[2].status << endl;   
      
}

//this function will verify the third tower to check if it is in order.
bool check_for_win(Tower tower[] , int n_disks){
 
   int counter = 0;  
 
    //Loop to check tower 3
    for (int check_order = 0 ; check_order < n_disks ; check_order ++){
        //check if the array is organized
        if(check_order == tower[MAX_TOWERS - 1].disks[check_order].disk_number - 1){
          counter ++ ;
        }
    }  
     

    if (counter == n_disks) return WIN;
    else return false;

}

//Functions that ask and save source tower;
int get_source(){
  int source;
     //ask the user for the source tower;    
        cout << "Enter source tower >> " ;
        cin >> source;
      
    return source;   
}

//Ask and save destination tower;
int get_destination(){
  int destination;
     //ask the user for the destination tower;
        cout << "Enter the destination tower >> ";
        cin >> destination;

   return destination; 
}
/*
void play_puzzle(Tower tower[] , int n_disks){
   
     int source;
     int destination;
     int exit;
     
     do{
       source = get_source();
       destination = get_destination();

          if (check_for_win(tower)){
              cout << "You have completed the puzzle!" << endl;
          }else {
              if (check_availability(tower)){

              }else
              // loop to check towers and make the movement.
          }
   
          cout << "Enter 1 to exit the game" << endl;
          cout << "Enter 0 to keep playing" << endl;
          cin >> exit;

     }while((check_for_win(tower)) || (exit == 1));
}
*/
//Starting menu
void user_menu(Tower tower[] , int n_disks){
    char option;

                  do{
		  	cout << "1) Play puzzle >> " << endl;
		  	cout << "2) See solution to puzzle >> " << endl;
                        cout << "3) Exit >> " << endl;
		  	cin >> option;
                  
		   	//
      			if (option == '1') {
                           //print_game(tower);
          //                 play_puzzle(tower , n_disks);
		   	}
		   	//show the solution
		   	else if(option == '2'){
		   		solution(n_disks, SOURCE , DESTINATION, SPARE);
			}
                        else if(option == '3')
                            cout << "GoodBye! " << endl;
		   	else
		   	    cout << "Not a valid entry";
       
                  }while(option != '3');
                    
}

//get disk amount
int get_disks(){
  int disk;
   
    cout << "Enter number of disks >>";
    cin >> disk;

  return disk;
}

//main loop for solutions
void solution(int n_to_move , int source , int destination , int spare){
	if(n_to_move == 1){
//	   cout << "Move from tower" << source << " to tower " << destination << endl;
//	   cout << "\t(" << source << ", " << destination << ')' << endl;
	   cout << "N     Src   Dest  Spare Step " << endl;
	   cout << "===== ===== ===== ===== =====" << endl;


	   cout << left << setw(6) <<n_to_move << setw(6) << source << setw(6)
		<< destination << setw(6) << spare << setw(6) << "0"
	  	<< "\t(" << source << ", " << destination << ')' << endl;
	   return;
  }

  solution(n_to_move - 1 , source , spare, destination);
//	if(n_to_move == 2)
	cout << left << setw(6) << n_to_move << setw(6) << source << setw(6)
	     << destination << setw(6) << spare << setw(6) << "0" << endl;
  solution(1 , source , destination , spare);
	cout << left << setw(6) << n_to_move << setw(6) << source << setw(6)
	     << destination << setw(6) << spare << setw(6) << "0" << endl;
  solution(n_to_move - 1 , spare , destination , source);
	cout << left << setw(6) << n_to_move << setw(6) << source << setw(6)
	     << destination << setw(6) << spare << setw(6) << "0" << endl;
/*
	if(n_to_move == 1){
	   cout << "\t(" << source << ", " << destination << ')' << endl;
	   cout << left << setw(6) << n_to_move << setw(6) << source << setw(6)
		<< destination << setw(6) << spare << setw(6) << "0" <<endl;
	   return;
	}
*/
}
  
