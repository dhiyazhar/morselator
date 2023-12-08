#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void add_history(int i, string morse, string kata) {
    // Buka file dalam mode baca dan tulis
    fstream file("history.txt", ios::in | ios::out | ios::app);

    string new_history;

    if (i == 1) {
        new_history = "Teks  : " + kata + "\n" + "Morse : " + morse + "\n" + "\n";
    } else if (i == 2) {
        new_history = "Morse : " + morse + "\n" + "Teks  : " + kata + "\n" + "\n";
    }
    
    auto current = chrono::system_clock::now();
    time_t currenTime = chrono::system_clock::to_time_t(current);

    file << ctime(&currenTime);
    file << new_history;

    // Tutup file
    file.close();

}

void delete_history() {
    // Buka file dalam mode tulis
    fstream history("history.txt", ios::out);

    // Tulis karakter null untuk menghapus isi file
    history << "";

    // Tutup file
    history.close();
}