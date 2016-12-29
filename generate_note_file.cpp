/*
 *generate_note_file.cpp
 *
 *This file functions as a "main" in the sense that it creates 
 *the notes.txt file for later compilation by the library. It includes
 *the Key class, Chord functions, and other appropriate functions, which are
 *all called from within this folder.
*/

#include "ClassKey.hpp"
#include "Chords.hpp"
#include <map>
#include "add_notes.hpp"

using note = int; //tells compiler to recognize "note" as "int"

int main(){

string keyletter; //holds input from user
srand(time(0));

//Pairs the name of a key to its tonic note
map<string, int> tonic_notes = {{"C", 60}, {"c", 60}, {"D", 62}, {"d", 62}, {"E", 64}, {"e", 64}, {"F", 65}, {"f", 65}, {"G", 67}, {"g", 67}, {"A", 69}, {"a", 69}, {"B", 71}, {"b", 71}};

cout << "Please enter a key. Choose between C, D, E, F, G, A, B" << endl;

cin >> keyletter;

//Ensures that input is valid. Continues asking user until valid input given
while (tonic_notes.find(keyletter) == tonic_notes.end() || keyletter.length() != 1) {
	cout << "Please enter a valid key: ";
	cin >> keyletter;
}

int tonic = 60;

tonic = tonic_notes[keyletter];

//creates a vector of vector of ints, which holds the series of chords returned
//by the add_notes funtiot
vector<vector<int>> end_product;
end_product = add_notes(tonic);

//creates output operator
ofstream ost{"notes.txt"};

//Writes out all of the integers corresponding to the notes in order
for(int i = 0; i < end_product.size(); i++){
	vector<int> temp;
	temp = end_product[i];
	for(int i = 0; i < temp.size(); i++){
		ost << temp[i] << endl;
	}
}

int end_value = -1;
ost << end_value << endl << end_value << endl << end_value << endl;

}

