/*
  file: hanoi.cpp
  Authors: Alex Martinez Veloz , Brandon Pack
  Date: 02/12/2020
  Description: This file contain the classes that would print the
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bar.h"
#include <sstream>

using namespace std;
using namespace bar;

int const SOURCE = 1;
int const SPARE = 2;
int const DESTINATION = 3;
int const MAX_TOWERS = 3;
bool const  EMPTY = false;
bool const WIN  = true;
bool const FILL = true;
int const NO_DISK = 0;
int const START_TOWER = 0;
int const MIDDLE_TOWER = 1;
int const END_TOWER = 2;

//structures
struct Disk{
    int disk_number;
    char color;              // Might change the data type.
    int width;
    int position;           // This would depend on which tower the disk is
    bool status;
    bar_color b_color;
};

struct Tower{
    Disk disks[1024];         // Array of disks
    int tower_id;
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
bool check_movement(Tower tower[] , int source , int destination , int source_disk , int destination_disk);
bool check_for_win(Tower tower[] , int n_disks);
bool tower_empty(Tower tower[] , int n_disks , int destination);
void print_game(Tower tower[] , int n_disks );
bar_color get_color(bool flag);

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
    return disk_number * 2;       // check this when printing on screen, we might have to change this 
                                // depending on how it looks
}

//This function will check if the user movement is correct or not.
bool check_movement(Tower tower[] , int source , int destination , int source_disk , int destination_disk){
        
        if (tower[source].disks[source_disk].disk_number < tower[destination].disks[destination_disk].disk_number )
              return true;
        else  return false;
}

//this function initialize Tower 1 and fill it up with disks...
void game_initializer(Tower tower[], int n_disks){
    
         //initialize towers.
      srand(time(NULL));
         
	for (int count_tower = 0 ; count_tower < MAX_TOWERS; count_tower ++){
           for (int disk_count = 0 ; disk_count < n_disks ; disk_count ++){
               
		tower[count_tower].disks[disk_count].position = count_tower + 1;                      
                tower[count_tower].tower_id = count_tower + 1;                
                
                //This conditional will assign true if the disks are on tower one.            
                    if (count_tower == 0){  
                        tower[count_tower].disks[disk_count].status = FILL;
                        tower[count_tower].disks[disk_count].disk_number = disk_count + 1;
                        tower[count_tower].disks[disk_count].b_color = get_color(true);
                        tower[count_tower].disks[disk_count].width = get_width(disk_count + 1);
                    }else{
                        tower[count_tower].disks[disk_count].status = EMPTY;
                        tower[count_tower].disks[disk_count].disk_number = NO_DISK;
                        tower[count_tower].disks[disk_count].b_color = get_color(false);
                        tower[count_tower].disks[disk_count].width = get_width(0);
                    }
           }
        }  
      
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
      
    return (source - 1);   
}

//Ask and save destination tower;
int get_destination(){
  int destination;
     //ask the user for the destination tower;
        cout << "Enter the destination tower >> ";
        cin >> destination;

   return (destination - 1); 
}

//Function that checks if the destination tower is empty
bool tower_empty(Tower tower[] , int n_disks , int destination){
    int empty_tower = 0;

        for (int disk_count = n_disks -1 ; disk_count >= 0 ; disk_count --)
            if (!tower[destination].disks[disk_count].status) empty_tower ++;
        
        if (empty_tower == n_disks) return true;
        else return false;

}

//Let the user interact with the game.
void play_puzzle(Tower tower[] , int n_disks){
   
     int source;
     int destination;
     Disk disk_temp;
     bool flag;
     bool win = false;
     
     do{
       source = get_source();
       destination = get_destination();
       flag = false;
    
          if (tower_empty(tower , n_disks , destination)){
     
              int count_disk = 0;
                 while(!flag){
                    
                    //swap disk
                    if(tower[source].disks[count_disk].status){
                      disk_temp = tower[source].disks[count_disk];
                      tower[source].disks[count_disk] = tower[destination].disks[n_disks - 1];
                      tower[destination].disks[n_disks - 1] = disk_temp;
                      
                      tower[destination].disks[n_disks - 1].status = true;
                      tower[source].disks[count_disk].status = false;                      

                      flag = true;
                    }else count_disk ++;
                    
                    if (count_disk == n_disks){
                      flag = true;
                      cout << "Source tower is empty, try again" << endl;
                    }
                 }
   
           }else{
             int source_disk = 0; 
             int destination_disk = n_disks - 1;

               while(!flag){
                  if(tower[source].disks[source_disk].status){ 
                    if(!tower[destination].disks[destination_disk].status){
                      //This conditional makes sure the movement is valid.
                      if (check_movement(tower , source , destination , source_disk , destination_disk + 1)){   
                         //once it checks the movement, swap disks!.
                         disk_temp = tower[source].disks[source_disk];
                         tower[source].disks[source_disk] = tower[destination].disks[destination_disk];
                         tower[destination].disks[destination_disk] = disk_temp;
                         flag = true;
                      }else{
                         cout << "You can't make that move, try again!." << endl;
                         flag = true;
                      }
                    }else destination_disk --;
   	       	
                  }else source_disk ++;
                 
                  if ((source_disk == n_disks) && (destination_disk == 0)){
                     cout << "You can't make that move, try again!." << endl;
                     flag = true;
                  }

               }
           }
          
          //This conditional makes sure the user solve the puzzle
          if (check_for_win(tower , n_disks)){
              cout << "You have solved the puzzle!" << endl;
              win = WIN;
           }

          //print
            print_game(tower , n_disks);
       
           //these couts print the towers (Only works for 3 to print)
        /*cout << tower[0].disks[0].disk_number << setw(10) << tower[1].disks[0].disk_number 
             << setw(10) << tower[2].disks[0].disk_number << endl;
        cout << tower[0].disks[1].disk_number << setw(10) << tower[1].disks[1].disk_number
             << setw(10) << tower[2].disks[1].disk_number << endl;
        cout << tower[0].disks[2].disk_number << setw(10) << tower[1].disks[2].disk_number
             << setw(10) << tower[2].disks[2].disk_number << endl;*/            
 
     }while(!win); 
}

void print_game(Tower tower[] , int n_disks){
 int w_setting = 25; 
  
       for (int disk_count = 0; disk_count < n_disks ; disk_count ++){
         cout << setw(w_setting) 
              << draw_bar(tower[START_TOWER].disks[disk_count].b_color , tower[START_TOWER].disks[disk_count].width) 
              << setw(w_setting * 2)
              << draw_bar(tower[MIDDLE_TOWER].disks[disk_count].b_color , tower[MIDDLE_TOWER].disks[disk_count].width)
	      << setw(w_setting * 2) 
              << draw_bar(tower[END_TOWER].disks[disk_count].b_color, tower[END_TOWER].disks[disk_count].width)
	      << endl;
       } 
    
} 

bar_color get_color(bool flag){
  int pick_color;

  if (flag){
      pick_color = (rand() % 7) +1;  

         switch(pick_color){
           case 1: return BLACK;
           case 2: return RED;
           case 3: return GREEN;
           case 4: return YELLOW;
           case 5: return BLUE;
           case 6: return MAGENTA;
           case 7: return CYAN;
         }
  }else return WHITE;

}


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
                           print_game(tower , n_disks);
                           play_puzzle(tower , n_disks);
		   	}
		   	//show the solution
		   	else if(option == '2'){
		   		//solution(n_disks, SOURCE , DESTINATION, SPARE);
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

