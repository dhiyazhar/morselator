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

string text_to_morse(string kata){
    string result;

	for(char word: kata){
		for(int i = 0; i < 37; i++){
			if(toupper(word) == alphabet[i].huruf){
				result += alphabet[i].kode;
                result += ' ';
			}
		}

	}

    return result;
}

string morse_to_text(string morse){
    string result;

    char* token = strtok(&morse[0], " ");
    while(token != NULL){
        for(int i = 0; i < 37; i++){
            if(strcmp(token, alphabet[i].kode) == 0){
                result += alphabet[i].huruf;
            }
        }
        token = strtok(NULL, " ");
    }

    return result;
}