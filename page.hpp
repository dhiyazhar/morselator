#include <iostream>
#include "history.hpp"
#include "translator.hpp"
using namespace std;

// main menu
void morselator(char option);
void translate(int i);
void morse_to_text_page();
void text_to_morse_page();
void open_page();
void loading();

void printascii(){
	int i = 0;

	start:
	system("cls");

	string line = "";
	ifstream infile;
	infile.open("art_ascii.txt");
	if(infile.is_open()){
		while(getline(infile,line)){
			cout << line << endl;
		}
	}
	else{
		cout << "File Failed To Load." << endl;
	}
	infile.close();

	cout << "Tekan apapun untuk lanjut... ";
	
	if(i == 0){
		cin.get();
	}
	
	cout << i << '%';
	if(i < 1){
		i++;
	}else{
		i += i;
	}

	if(i <= 100){
		goto start;
	}

	open_page();
}

void open_page(){
	system("cls");
	cout << endl << endl;
	cout << "======================================" << endl;
	cout << "|         SELAMAT DATANG DI          |" << endl;
	cout << "|            MORSELATOR              |" << endl;
	cout << "======================================" << endl;
	cout << endl;
	cout << "1. Translate" << endl;
	cout << "2. History" << endl;
	cout << endl;
	cout << "0. Exit" << endl;
	cout << endl;

	char option;

	cout << "Masukkan pilihan anda: ";
	cin >> option;
	morselator(option);
}

// translate menu
void translate_page(){
	system("cls");
    cout << "======================================" << endl;
	cout << "|              MORSELATOR            |" << endl;
	cout << "======================================" << endl;
    cout << endl;
    cout << "        Pilih Mode Translate :        " << endl << endl;
    cout << "      	  1. Teks  ---> Morse          " << endl;
    cout << "          2. Morse ---> Teks           " << endl;
	cout << endl;
	cout << "      	  3. Menu Awal          " << endl;
    cout << endl;

    int option;

	cout << "Masukkan pilihan anda: ";
	cin >> option;
	translate(option);
}

void translate(int i){
	if(i == 1){
		text_to_morse_page();
	}
	else if(i == 2){
		morse_to_text_page();
	}
	else if(i = 'q') {
		open_page();
	}
	else{
		cout << "Pilihan tidak ada, harap ulangi pilihan anda" << endl << endl;
		cout << "tekan apapun untuk lanjut...";
		cin.get();
		translate_page();
	}
}

//history menu start
void history_header(){
	system("cls");
	cout << "======================================" << endl;
	cout << "|              History               |" << endl;
	cout << "======================================" << endl;
	cout << endl;
}

void history_body(){

	char option;

	ifstream file("history.txt");

	string content;
	while(getline(file, content)){
		cout << content << endl;
	}

	cout << endl << "HAPUS HISTORI?" << endl;
	cout << "y [ya] | n [kembali ke menu awal] : ";
	cin >> option;

	if(option == 'y'){
		delete_history();
	}

	open_page();
}

void history_page(){
	history_header();
	history_body();

} // history menu end


void morselator(char option){
	if(option == '0'){
		return;
	}
	else if(option == '1'){
		translate_page();
	}
	else if(option == '2'){
		history_page();
	}
	else{
		cout << "Pilihan tidak ada, harap ulangi pilihan anda" << endl << endl;
		cout << "tekan apapun untuk lanjut...";
		cin.get();
		cin.get();
		cout << endl;
		open_page();
	}
}

void text_to_morse_page(){
	system("cls");

	string teks;
	string morse;
	char option;

	cout << "======================================" << endl;
	cout << "|              Translator            |" << endl;
	cout << "|          Teks   --->   Morse       |" << endl;
	cout << "======================================" << endl;
	cout << endl;
	coccut << "Masukkan Teks : ";

	cin.ignore();
	getline(cin, teks);
	cout << endl;

	morse = text_to_morse(teks);

	cout << "Hasil translate : " << "\" " << morse << '\"' << endl;

	cout << "y = lanjut translate | n = kembali ke menu awal :";
	cin >> option;

	add_history(1, morse, teks);

	if(option == 'n'){
		open_page();
	}else{
		translate_page();
	}
}

void morse_to_text_page(){
	system("cls");

	string teks;
	string morse;
	char option;

	cout << "======================================" << endl;
	cout << "|              Translator            |" << endl;
	cout << "|         Morse   --->   Teks        |" << endl;
	cout << "======================================" << endl;
	cout << endl;
	cout << "Masukkan Kode Morse : ";

	cin.ignore();
	getline(cin, morse);
	cout << endl;

	teks = morse_to_text(morse, strtok(&morse[0], " "));

	cout << "Hasil translate : " << teks << endl;

	cout << "y = lanjut translate | n = kembali ke menu awal :";
	cin >> option;

	add_history(2, morse, teks);

	if(option == 'n'){
		open_page();
	}else{
		translate_page();
	}
}
