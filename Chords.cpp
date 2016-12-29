// Chords.cpp
// This file defines the functions that create the different type of chords we use: I, IV, V, VI and flatIV.
// Each returns a vector of integers and takes as a parameter a vector of possible notes.
// Each function chooses from the possible note in the key within two octaves.  

#include "Chords.hpp"
using note = int;

//function that creates the I chord
vector<int> chordI(vector<int> notes){      // example: if key chosen is C, the notes would be:
	
	vector<int> c;
	c.push_back(notes[0]);              // C
	c.push_back(notes[2]);              // E
	c.push_back(notes[4]);              // G
	
	c.push_back(notes[0]-12);           // C an octave lower
	c.push_back(notes[2]-12);           // E an octave lower
	c.push_back(notes[4]-12);           // G an octave lower

	return c;
}

//function that creates the IV chord
vector<int> chordIV(vector<int> notes){
	
	vector<int> c;
	c.push_back(notes[3]);
	c.push_back(notes[5]);
	c.push_back(notes[0]);

	c.push_back(notes[3]-12);
	c.push_back(notes[5]-12);
	c.push_back(notes[0]-12);

	return c;
}

//function that creates the V chord
vector<int> chordV(vector<int> notes){
	
	vector<int> c;
	c.push_back(notes[4]);
	c.push_back(notes[6]);
	c.push_back(notes[1]);

	c.push_back(notes[4]-12);
	c.push_back(notes[6]-12);
	c.push_back(notes[1]-12);

	return c;
}

//function that creates the VI chord
vector<int> chordVI(vector<int> notes){
	
	vector<int> c;
	c.push_back(notes[5]);
	c.push_back(notes[0]);
	c.push_back(notes[2]);

	c.push_back(notes[5]-12);
	c.push_back(notes[0]-12);
	c.push_back(notes[2]-12);

	return c;
}

//function that creates the flatVI chord
vector<int> chordflatVI(vector<int> notes){
	
	vector<int> c;
	c.push_back(notes[5]);
	c.push_back(notes[0]);
	c.push_back(notes[1]);

	c.push_back(notes[5]-12);
	c.push_back(notes[0]-12);
	c.push_back(notes[1]-12);

	return c;
}
