#include <iostream>
using namespace std;

// main menu
void open_page(){
	cout << "======================================" << endl;
	cout << "|              MORSELATOR            |" << endl;
	cout << "======================================" << endl;
	cout << endl;
	cout << "1. Translate" << endl;
	cout << "2. History" << endl;
	cout << endl;
	cout << "0. Exit" << endl;
	cout << endl;

	int option;
	cin >> option;
	morselator(option);
}

// translate menu
void translate_page(){
    cout << "======================================" << endl;
	cout << "|         SELAMAT DATANG DI          |" << endl;
	cout << "|            MORSELATOR              |" << endl;
	cout << "======================================" << endl;
    cout << endl;
    cout << "        Pilih Mode Translate :        " << endl << endl;
    cout << "      	  1. Teks  ---> Morse          " << endl;
    cout << "         2. Morse ---> Teks           " << endl;
    cout << endl; 
}

//history menu start
void history_header(){
	cout << "======================================" << endl;
	cout << "|              History               |" << endl;
	cout << "======================================" << endl;
	cout << endl;
}

void history_body(){

	ifstream file("history.txt");

	string content;
	while(getline(file, content)){
		cout << content << endl;
	}	
}

void history_page(){
	history_header();
	history_body();

} // history menu end


void morselator(int i){
	if(i == 1){
		translate_page();
	}
	else if(i == 2){
		history_page();
	}
	else{
		cout << "pilihan tidak ada, harap ulangi pilihan anda";
		open_page();
	}
}

void text_to_morse_page(){
	
}