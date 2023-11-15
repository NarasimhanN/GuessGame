#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
string USERNAME = "Simha";
string PASSWORD = "guessgame";

bool authenticateLogin(string username,string password){
	return (username == USERNAME and password == PASSWORD);
}
void printOptions(vector<string> optins){
	cout<<"\n\n\t Options : \n";
	for(auto ele : optins)
		cout<<ele<<" ";
}
void playGame(){
		int r;//No of rounds
		int n;//No of options
		
		//1.Take input on options and rounds
		cout<<"\n\t Enter No of Rounds ";
		cout<<"\n\n   >> ";
		cin>>r;
		cout<<"\n\t Enter No of Options ";
		cout<<"\n\n   >> ";
		cin>>n;
		vector<string> options(n);
		vector<int> freq(n);
		for(int i=0;i<n;i++){
			cout<<"\n\t Enter Option "<<i+1<<" value ";
			cout<<"\n\n   >> ";
			cin>>options[i];
		}
		
		
		for(int i=1;i<=r;i++){
			cout<<"\n\n\t --------------- Round "<<i<<" ---------------- ";
			cout<<"\n\n\t Click Enter to Randomly select a option ";
			getch();
			int randomNo = rand()%n;
			cout<<"\n\n\t\t****** Randomly Generated Option is  :  "<<options[randomNo]<<"\n\n";
			freq[randomNo]++;
			getch();
		}
		
		//3.Find max freq item
		int maxOption = 0;
		for(int i=0;i<n;i++) maxOption = (freq[maxOption]<freq[i])? i : maxOption;
		
		
		//4.Print he max item
		cout<<"\n\n\n\t\t *******((( The MOST Random Item to Choosen is : "<<options[maxOption]<<" with "<<freq[maxOption]<<" times of Occurance )))*******\n\n";
		
		getch();
		getch();
		
		}
int main(){
	string username,password;
	int choice;
	//1.Login
	cout<<"\n\n\t\t ---------- Authenticate Yourself ---------- ";
	while(true){
	cout<<"\n    Enter your Username : \n   >> ";
	cin>>username;
	cout<<"\n    Enter your Password : \n   >> ";
	password="";
	while(true){
		char ch = getch();
		if(ch=='\r' || ch=='\n' || ch==EOF) break;
		
		password += ch;
	}
	if(authenticateLogin(username,password))break;
	cout<<"\n\t\t ERROR : INVALID User !! Try Again !! \n\n";
	
	}
	
	
	//2. Play game
		while(true){
		system("CLS");
		cout<<"\n\n\n\n\t\t************************************************";
		cout<<"\n\t\t\t Hello "<<username<<", welcome TO Guess-Game ";
		cout<<"\n\t\t************************************************";
		cout<<"\n\t Press 1 : To Start the Game ";
		cout<<"\n\t Press 2 : To Exit";
		cout<<"\n\n   >> ";
		cin>>choice;
		if(choice==2) break;
		else if(choice==1)
			playGame();
		else{//Invalid Entry
			cout<<"\n\t Invalid Entry , Try again ...";
			getchar();
			getchar();	
		}
		
		
	}
	cout<<"\n\t\t Bye Bye "<<username<<"............................................\n\n\n\n";

	return 0;
}