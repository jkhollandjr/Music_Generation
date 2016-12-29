// Classkey.cpp
// This file defines the class Keys. It creates a major scale of notes for the key that the user will choose.
// All other notes in the key are based on the starting position: the tonic_note. So if the key of G is chosen, the tonic_note will be G = 67.
// Please see http://www.midimountain.com/midi/midi_note_numbers.html for further explanation.
// These notes are pushed back to the chord vectors from Chords.cpp  

#include "ClassKey.hpp"

using note = int;   // we define our notes as int values since MIDI reads them this way. Ex: Middle C = 60, the E above middle C = 64, etc.


Keys::Keys(int tonic_note){

		notes.push_back(tonic_note);            // if tonic note chosen is G = 67
		notes.push_back(notes[0] + 2);          // A = 69
		notes.push_back(notes[1] + 2);          // B = 71
		notes.push_back(notes[2] + 1);          // C = 72
		notes.push_back(notes[3] + 2);          // D = 74
		notes.push_back(notes[4] + 2);          // E = 76
		notes.push_back(notes[5] + 2);          // F# = 78

		chords.push_back(chordI(notes));
		chords.push_back(chordIV(notes));
		chords.push_back(chordV(notes));
		chords.push_back(chordVI(notes));
		chords.push_back(chordflatVI(notes));
	}

vector<int> Keys::get_notes(){return notes;}            // Allows you to directly access notes if needed by the following command: Keys.get_notes()
vector<vector<int>> Keys::get_chords(){return chords;}  // same as above but for chords

