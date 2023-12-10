#pragma once

#include <bits/stdc++.h>
using namespace std;

struct MorseCode {

    char huruf;
    const char* kode;

};

MorseCode alphabet[] {

        {'A', ".-" },
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-.--"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {' ', "/"},  // spasi
        {'0', "-----"},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."}

};

string text_to_morse(string kata, int index = 0){
	if(index >= kata.length()){
        return "";
    }
    for(int i = 0; i < 37; i++){
        if(toupper(kata[index]) == alphabet[i].huruf){
            string kode(alphabet[i].kode);
            return kode + " " + text_to_morse(kata, index+1);
        }
    }

}

string morse_to_text(string morse, char* token){
    if(token == NULL){
        return "";
    }

    for(int i = 0; i < 37; i++){    
        if(strcmp(token, alphabet[i].kode) == 0){
            return alphabet[i].huruf + morse_to_text(morse, strtok(NULL, " "));
        }
    }
}