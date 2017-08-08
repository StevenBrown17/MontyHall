//(c) Made by Steven Brown 2015

#include <iomanip>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>


using namespace std;

//declare methods
void randomizeDoors();
void openDoor();
void displayOpenedDoor();
void swapDoor();
void finalDoor();
void doorDrawing();
void openDoorArt();
void winningDoorArt();
void losingArt();


//global vars
int randNum, pick, x, openedDoor, unopenedDoor, winCount;
int door0, door1, door2;//picked door will be assigned a 1 value, others a 0 value
bool win;
char YN, again;

int main(){
	srand(time(NULL));//
	win = false;//at runtime, declare win as false

	cout <<"(c) steven brown";
	cout << "\n\n********************* Welcome to the Monty Hall Problem *********************";//decorative intro

	do{

		cout << "\n\nPress 1 to PLAY, or 2 to GENERATE multiple results: "; cin >> x;// play or generate
		win = false;
		winCount = 0;

		if (x == 1){

			doorDrawing();//display doors
			cout << "\n\n                Choose a door: 0, 1, 2: "; cin >> pick;//user picks door
			randomizeDoors();//randomize winning door
			Sleep(10);
			cout << "You chose door " << pick << endl;//display door

			openDoor();//open  a goat door
			displayOpenedDoor();//display doors
			cout << "\n\nThere are 2 doors left, you can keep door " << pick << ",  or swap with door " << unopenedDoor;
			cout << "\nWould you like to swap doors? (Y/N): "; cin >> YN;
			if (YN == 'y' || YN == 'Y'){
				swapDoor();
				cout << "\nYour new door is " << pick;//if door swap, dispay new door
			}
			cout << "\nLets see whats behind your door!\n";
			finalDoor();
			if (win){
				winningDoorArt();
				cout << "\n\nYOU WIN!! THERE IS CASH BEHIND DOOR " << pick;
			}
			else{
				losingArt();
				cout << "\n\nYou lose!!, You chose door "<<pick <<", the cash was behind door " << unopenedDoor <<"\nBetter luck next time!";
			}

		}//end if

		if (x == 2){
			long long int count;
			winCount = 0;
			do{
				cout << "\nHow many times would you like to simulate the game? (0 - 10000000)"; cin >> count;
				if (count > 10000000)cout << "\nPlease choose a number less than 10000000";
			} while (count > 10000000);
			cout << "\nCalculating........";
			for (long long int i = 0; i < count; i++){
				pick = (rand() % 3);
				randomizeDoors();
				openDoor();
				finalDoor();
			}
			cout <<"\n\n" << winCount << " out of " << count << " games won WITHOUT swapping doors.";
			cout << "\n\nCalculating........";
			winCount = 0;
			for (long long int i = 0; i < count; i++){
				pick = (rand() % 3);
				randomizeDoors();
				openDoor();
				swapDoor();
				finalDoor();
			}
			cout << "\n\n" << winCount << " out of " << count << " games won WITH swapping doors.";
		}

		cout << "\n\nWould you like to play again?(Y/N)"; cin >> again;

	} while (again == 'y' || again == 'Y');

	cout << "\nThanks for playing!! press any key to exit.....";
	_getch();
}

void randomizeDoors(){
	door0 = 0; door1 = 0; door2 = 0;
	randNum = (rand() % 3);
	if (randNum == 0)door0 = 1;
	else if (randNum == 1)door1 = 1;
	else door2 = 1;
}

void openDoor(){
	openedDoor = rand() % 2;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (door0 == 1 && pick == 0){//if pick = winning door, randomly open one of the other doors
		if (openedDoor == 0){ openedDoor = 1, unopenedDoor = 2; }
		else { openedDoor = 2, unopenedDoor = 1; }
		return;
	}
	if (door1 == 1 && pick == 1){//if pick = winning door, randomly open one of the other doors
		openedDoor = rand() % 2;
		if (openedDoor == 0){ openedDoor = 0, unopenedDoor = 2; }//code for correct pick scenario
		else { openedDoor = 2, unopenedDoor = 0; }
		return;
	}
	if (door2 == 1 && pick == 2){//if pick = winning door, randomly open one of the other doors
		openedDoor = rand() % 2;
		if (openedDoor == 0){ openedDoor = 0, unopenedDoor = 1; }
		else { openedDoor = 1, unopenedDoor = 0; }
		return;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//if incorrect door chosen, need to open other incorrct door

	if (door0 == 1 && pick == 1){
		openedDoor = 2; unopenedDoor = 0;
		return;
	}
	if (door0 == 1 && pick == 2){
		openedDoor = 1; unopenedDoor = 0;
		return;
	}
	if (door1 == 1 && pick == 0){
		openedDoor = 2; unopenedDoor = 1;
		return;
	}
	if (door1 == 1 && pick == 2){
		openedDoor = 0; unopenedDoor = 1;
		return;
	}
	if (door2 == 1 && pick == 0){
		openedDoor = 1; unopenedDoor = 2;
		return;
	}
	if (door2 == 1 && pick == 1){
		openedDoor = 0; unopenedDoor = 2;
		return;
	}
}
void displayOpenedDoor(){
	cout << "\nYou chose door number " << pick << ". Lets open door number " << openedDoor;
	Sleep(1250);
	cout << "\n\n                    ITS A GOAT!!!!\n\n";
	openDoorArt();

}
void swapDoor(){
	int temp;
	temp = pick;
	pick = unopenedDoor;
	unopenedDoor = temp;
}
void finalDoor(){
	if (pick == randNum){
		win = true;
		winCount++;
	}
	else{
		win = false;
	}
}


void doorDrawing(){

	cout << "\n           DOOR 0      DOOR 1       DOOR 2\n";
	cout << "        __________   __________   __________";
	cout << "\n	| __  __ |   | __  __ |   | __  __ |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	|     () |   |     () |   |     () |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| | || | |   | | || | |   | | || | |";
	cout << "\n	| ______ |   | ______ |   | ______ |";

}
void openDoorArt(){

	if (openedDoor == 0){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||       |   | __  __ |   | __  __ |";
		cout << "\n	||       |   | | || | |   | | || | |";
		cout << "\n	||   G   |   | | || | |   | | || | |";
		cout << "\n	||   O   |   | | || | |   | | || | |";
		cout << "\n	||   A   |   |     () |   |     () |";
		cout << "\n	||   T   |   | | || | |   | | || | |";
		cout << "\n	||   !   |   | | || | |   | | || | |";
		cout << "\n	||   !   |   | | || | |   | | || | |";
		cout << "\n	||   !   |   | | || | |   | | || | |";
		cout << "\n	||       |   | | || | |   | | || | |";
		cout << "\n	||______ |   | ______ |   | ______ |";

	}
	if (openedDoor == 1){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	| __  __ |   ||       |   | __  __ |";
		cout << "\n	| | || | |   ||       |   | | || | |";
		cout << "\n	| | || | |   ||   G   |   | | || | |";
		cout << "\n	| | || | |   ||   O   |   | | || | |";
		cout << "\n	|     () |   ||   A   |   |     () |";
		cout << "\n	| | || | |   ||   T   |   | | || | |";
		cout << "\n	| | || | |   ||   !   |   | | || | |";
		cout << "\n	| | || | |   ||   !   |   | | || | |";
		cout << "\n	| | || | |   ||   !   |   | | || | |";
		cout << "\n	| | || | |   ||       |   | | || | |";
		cout << "\n	| ______ |   ||______ |   | ______ |";
	}
	if (openedDoor == 2){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	| __  __ |   | __  __ |   ||       |";
		cout << "\n	| | || | |   | | || | |   ||       |";
		cout << "\n	| | || | |   | | || | |   ||   G   |";
		cout << "\n	| | || | |   | | || | |   ||   O   |";
		cout << "\n	|     () |   |     () |   ||   A   |";
		cout << "\n	| | || | |   | | || | |   ||   T   |";
		cout << "\n	| | || | |   | | || | |   ||   !   |";
		cout << "\n	| | || | |   | | || | |   ||   !   |";
		cout << "\n	| | || | |   | | || | |   ||   !   |";
		cout << "\n	| | || | |   | | || | |   ||       |";
		cout << "\n	| ______ |   | ______ |   || _____ |";

	}

}
void winningDoorArt(){

	if (pick == 0 && pick == randNum){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||        |   ||       |   ||       |";
		cout << "\n	|| $$$$$$ |   ||       |   ||       |";
		cout << "\n	|| $$$$$$ |   ||   G   |   ||   G   |";
		cout << "\n	|| $$$$$$ |   ||   O   |   ||   O   |";
		cout << "\n	|| $$$$$$ |   ||   A   |   ||   A   |";
		cout << "\n	|| $$$$$$ |   ||   T   |   ||   T   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||       |   ||       |";
		cout << "\n	|| ______ |   || _____ |   || _____ |";
	}
	if (pick == 1 && pick == randNum){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||       |   ||        |   ||       |";
		cout << "\n	||       |   || $$$$$$ |   ||       |";
		cout << "\n	||   G   |   || $$$$$$ |   ||   G   |";
		cout << "\n	||   O   |   || $$$$$$ |   ||   O   |";
		cout << "\n	||   A   |   || $$$$$$ |   ||   A   |";
		cout << "\n	||   T   |   || $$$$$$ |   ||   T   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||       |   || $$$$$$ |   ||       |";
		cout << "\n	|| _____ |   || ______ |   || _____ |";
	}
	if (pick == 2 && pick == randNum){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||       |   ||       |   ||        |";
		cout << "\n	||       |   ||       |   || $$$$$$ |";
		cout << "\n	||   G   |   ||   G   |   || $$$$$$ |";
		cout << "\n	||   O   |   ||   O   |   || $$$$$$ |";
		cout << "\n	||   A   |   ||   A   |   || $$$$$$ |";
		cout << "\n	||   T   |   ||   T   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||       |   ||       |   || $$$$$$ |";
		cout << "\n	||______ |   ||______ |   || ______ |";
	}
}
void losingArt(){
	if (!win && randNum == 0){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||        |   ||       |   ||       |";
		cout << "\n	|| $$$$$$ |   ||       |   ||       |";
		cout << "\n	|| $$$$$$ |   ||   G   |   ||   G   |";
		cout << "\n	|| $$$$$$ |   ||   O   |   ||   O   |";
		cout << "\n	|| $$$$$$ |   ||   A   |   ||   A   |";
		cout << "\n	|| $$$$$$ |   ||   T   |   ||   T   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||   !   |   ||   !   |";
		cout << "\n	|| $$$$$$ |   ||       |   ||       |";
		cout << "\n	|| ______ |   || _____ |   || _____ |";
	}
	if (!win && randNum == 1){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||       |   ||        |   ||       |";
		cout << "\n	||       |   || $$$$$$ |   ||       |";
		cout << "\n	||   G   |   || $$$$$$ |   ||   G   |";
		cout << "\n	||   O   |   || $$$$$$ |   ||   O   |";
		cout << "\n	||   A   |   || $$$$$$ |   ||   A   |";
		cout << "\n	||   T   |   || $$$$$$ |   ||   T   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||   !   |   || $$$$$$ |   ||   !   |";
		cout << "\n	||       |   || $$$$$$ |   ||       |";
		cout << "\n	|| _____ |   || ______ |   || _____ |";
	}
	if (!win && randNum == 2){
		cout << "           DOOR 0      DOOR 1       DOOR 2\n";
		cout << "        __________   __________   __________";
		cout << "\n	||       |   ||       |   ||        |";
		cout << "\n	||       |   ||       |   || $$$$$$ |";
		cout << "\n	||   G   |   ||   G   |   || $$$$$$ |";
		cout << "\n	||   O   |   ||   O   |   || $$$$$$ |";
		cout << "\n	||   A   |   ||   A   |   || $$$$$$ |";
		cout << "\n	||   T   |   ||   T   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||   !   |   ||   !   |   || $$$$$$ |";
		cout << "\n	||       |   ||       |   || $$$$$$ |";
		cout << "\n	||______ |   ||______ |   || ______ |";
	}


}