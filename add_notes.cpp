/*
 *add_notes.cpp
 *
 *This function uses a matrix of probabilities to add the possible chords in an
 *alrorithmic/random manner. To do this, it uses the key class to create the set of 
 *possible chords. Then, it adds them until a specific criteria is met, and returns
 *the final vector of chords.
 *
 *The function defined here is called from the generate_note_file.cpp file 
 *
 */


#include "add_notes.hpp"

vector<vector<int>> add_notes(int tonic){

//initializes a scale based on tonic notes
Keys scale(tonic);

//Holds set of chords, which is return later
vector<vector<int>> set_of_chords;


//set_of_chords = example.get_chords();

//2D array of probabilities for markov chain. It is 5x5 because there are 5 possible chords per octave
double probabilities[5][5];


//chord I
probabilities[0][0] = .3;
probabilities[0][1] = .6;
probabilities[0][2] = .1;
probabilities[0][3] = 0;
probabilities[0][4] = 0;

//chord IV
probabilities[1][0] = .1;
probabilities[1][1] = .2;
probabilities[1][2] = .5;
probabilities[1][3] = 0;
probabilities[1][4] = .2;

//chord V
probabilities[2][0] = .2;
probabilities[2][1] = .1;
probabilities[2][2] = .3;
probabilities[2][3] = .4;
probabilities[2][4] = 0;

//chord VI
probabilities[3][0] = 0;
probabilities[3][1] = 0;
probabilities[3][2] = 0;
probabilities[3][3] = 0;
probabilities[3][4] = 1;

//chord flatVI
probabilities[4][0] = 0;
probabilities[4][1] = 1;
probabilities[4][2] = 0;
probabilities[4][3] = 0;
probabilities[4][4] = 0;

//adds the first two chords. Without this, the next while() loop cannot make comparisons, as the set of chords will be empty
set_of_chords.push_back(scale.get_chords()[0]);
set_of_chords.push_back(scale.get_chords()[0]);

int counter = 1;
double random = 0;

//Specifies that chords will be added until a 5-1 progression given the song is at least 20 chords long
while(set_of_chords.size() < 20 || !(set_of_chords[counter-1] == scale.get_chords()[2] && set_of_chords[counter] == scale.get_chords()[0])){

	//random number between 0 and 1. Used with decimal probabilites to pick next chord
	random = (double)rand() / RAND_MAX;	

	//This part basically finds the probability from the matrix, and uses the randomly generated number to pick the chords based on these probabilities
	if(set_of_chords[counter] == scale.get_chords()[0]){
		
		if(random < probabilities[0][0]){
			set_of_chords.push_back(scale.get_chords()[0]);
		}
		else if(random < (probabilities[0][0] + probabilities[0][1])){
			set_of_chords.push_back(scale.get_chords()[1]);
		}
		else if(random < (probabilities[0][0] + probabilities[0][1] + probabilities[0][2])){
			set_of_chords.push_back(scale.get_chords()[2]);
		}
		else if(random < (probabilities[0][0] + probabilities[0][1] + probabilities[0][2]) + probabilities[0][3]){
			set_of_chords.push_back(scale.get_chords()[3]);
		}
		else{
			set_of_chords.push_back(scale.get_chords()[4]);
		}
	}
	//Probabilities of added chord are based on previous chord
	else if(set_of_chords[counter] == scale.get_chords()[1]){
		
		if(random < probabilities[1][0]){
			set_of_chords.push_back(scale.get_chords()[0]);
		}
		else if(random < (probabilities[1][0] + probabilities[1][1])){
			set_of_chords.push_back(scale.get_chords()[1]);
		}
		else if(random < (probabilities[1][0] + probabilities[1][1] + probabilities[1][2])){
			set_of_chords.push_back(scale.get_chords()[2]);
		}
		else if(random < (probabilities[1][0] + probabilities[1][1] + probabilities[1][2]) + probabilities[1][3]){
			set_of_chords.push_back(scale.get_chords()[3]);
		}
		else{
			set_of_chords.push_back(scale.get_chords()[4]);
		}

	}
	else if(set_of_chords[counter] == scale.get_chords()[2]){
		
		if(random < probabilities[2][0]){
			set_of_chords.push_back(scale.get_chords()[0]);
		}
		else if(random < (probabilities[2][0] + probabilities[2][1])){
			set_of_chords.push_back(scale.get_chords()[1]);
		}
		else if(random < (probabilities[2][0] + probabilities[2][1] + probabilities[2][2])){
			set_of_chords.push_back(scale.get_chords()[2]);
		}
		else if(random < (probabilities[2][0] + probabilities[2][1] + probabilities[2][2]) + probabilities[2][3]){
			set_of_chords.push_back(scale.get_chords()[3]);
		}
		else{
			set_of_chords.push_back(scale.get_chords()[4]);
		}

	}
	
	else if(set_of_chords[counter] == scale.get_chords()[3]){
		
		if(random < probabilities[3][0]){
			set_of_chords.push_back(scale.get_chords()[0]);
		}
		else if(random < (probabilities[3][0] + probabilities[3][1])){
			set_of_chords.push_back(scale.get_chords()[1]);
		}
		else if(random < (probabilities[3][0] + probabilities[3][1] + probabilities[3][2])){
			set_of_chords.push_back(scale.get_chords()[2]);
		}
		else if(random < (probabilities[3][0] + probabilities[3][1] + probabilities[3][2]) + probabilities[3][3]){
			set_of_chords.push_back(scale.get_chords()[3]);
		}
		else{
			set_of_chords.push_back(scale.get_chords()[4]);
		}

	}

	else if(set_of_chords[counter] == scale.get_chords()[4]){
		
		if(random < probabilities[4][0]){
			set_of_chords.push_back(scale.get_chords()[0]);
		}
		else if(random < (probabilities[4][0] + probabilities[4][1])){
			set_of_chords.push_back(scale.get_chords()[1]);
		}
		else if(random < (probabilities[4][0] + probabilities[4][1] + probabilities[4][2])){
			set_of_chords.push_back(scale.get_chords()[2]);
		}
		else if(random < (probabilities[4][0] + probabilities[4][1] + probabilities[4][2]) + probabilities[4][3]){
			set_of_chords.push_back(scale.get_chords()[3]);
		}
		else{
			set_of_chords.push_back(scale.get_chords()[4]);
		}

	}


	//counter tracks number of chords added, as one is added per iteration of the loop
	counter += 1;
}

return set_of_chords;
}
