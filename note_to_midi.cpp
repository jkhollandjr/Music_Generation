// note_to_midi.cpp
//
// Writes a midifile using the notes.txt file and the functions from the Midifile library.
// 
// NOTE: This code has been adapted from an example provided by the Midifile library
//The original code described how to create a track from arrays of integers corresponding to
//the rythm and midi notes.
//
//Our specific contribution includes the input and output operator and separation of vector into 
//multiple other vectors, which are added to the musical tracks separately. We also created a method
//of randomly generating the rythm, rather that hard-coding it. 
#include "MidiFile.h"
#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

typedef unsigned char uchar;

///////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
   MidiFile outputfile;        // create an empty MIDI file with one track
   outputfile.absoluteTicks();  // time information stored as absolute time
                               // (will be coverted to delta time when written)
   outputfile.addTrack(3);     // Add another three tracks to the MIDI file
   vector<uchar> midievent;     // temporary storage for MIDI events
   midievent.resize(3);        // set the size of the array to 3 bytes
   int tpq = 120;              // default value in MIDI file is 48
   outputfile.setTicksPerQuarterNote(tpq);

   //input operates that reads in the notes from notes.txt, and sends them to a vector
   ifstream ist {"notes.txt"};
   vector<int> note_values;
   int tmp;
   while (ist >> tmp) {
	note_values.push_back(tmp);
   }

   vector<int> voice1;
   vector<int> voice2;
   vector<int> voice3;

   //Vector of integers (notes) is split into three differet vectors, or "voices" such that every third
   //note is added to a specific vector, given different starting points 
   for (unsigned i=2; i<note_values.size(); i+=3)
   voice1.push_back(note_values[i]);

   for (unsigned i=1; i<note_values.size(); i+=3)
   voice2.push_back(note_values[i]);

   for (unsigned i=0; i<note_values.size(); i+=3)
   voice3.push_back(note_values[i]);

   //vector will hold the rythm information
   vector<double> rhythm1(voice1.size());
   vector<double> note_lengths{0.5, 1.0, 2.0};

   for (unsigned i=0; i<rhythm1.size()-2; i++)
   rhythm1[i] = note_lengths[rand() % 2]; // randomly generate eight, quarter or half note
   rhythm1[rhythm1.size()-2] = 4.0;  // end on whole note
   rhythm1[rhythm1.size()-1] = -1.0; // -1 to stop reading

   vector<double> rhythm2 = rhythm1;
   vector<double> rhythm3 = rhythm1;

   // store a melody line in track 1 (track 0 left empty for conductor info)
   int i=0;
   int actiontime = 0;      // temporary storage for MIDI event time
   midievent[2] = 64;       // store attack/release velocity for note command
   while (voice1[i] >= 0) {
      midievent[0] = 0x90;     // store a note on command (MIDI channel 1)
      midievent[1] = voice1[i];
      outputfile.addEvent(1, actiontime, midievent);
      actiontime += tpq * rhythm1[i];
      midievent[0] = 0x80;     // store a note on command (MIDI channel 1)
      outputfile.addEvent(1, actiontime, midievent);
      i++;
   }

   // store a base line in track 2
   i=0;
   actiontime = 0;          // reset time for beginning of file
   midievent[2] = 64;
   while (voice2[i] >= 0) {
      midievent[0] = 0x90;
      midievent[1] = voice2[i];
      outputfile.addEvent(2, actiontime, midievent);
      actiontime += tpq * rhythm2[i];
      midievent[0] = 0x80;
      outputfile.addEvent(2, actiontime, midievent);
      i++;
   }

   // store a base line in track 3
   i=0;
   actiontime = 0;          // reset time for beginning of file
   midievent[2] = 64;
   while (voice3[i] >= 0) {
      midievent[0] = 0x90;
      midievent[1] = voice3[i];
      outputfile.addEvent(3, actiontime, midievent);
      actiontime += tpq * rhythm3[i];
      midievent[0] = 0x80;
      outputfile.addEvent(3, actiontime, midievent);
      i++;
   }

   outputfile.sortTracks();         // make sure data is in correct order
   outputfile.write("song.mid"); // write Standard MIDI File
   return 0;

}
