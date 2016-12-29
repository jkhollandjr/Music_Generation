#pragma once

#include "std_lib_facilities.h"
#include "Chords.hpp"
using note = int;

class Keys{

	private:

	vector<note> notes;
	vector<vector<int>> chords;

	public:

	Keys(int tonic_note);

	vector<int> get_notes();
	vector<vector<int>> get_chords();
};
