This program makes use of the Midifile external library, which can be found at "github.com/craigsapp/midifile". We have written, compiled, and tested our program on the CRC and in the terminal on one of our computers (MacBook, using bash). To compile on the CRC or your own computer, you will first need to move the include folder that we provided to your home directory. If you prefer to have the include folder in a different location, you will need to specify a change of path in the Makefile.

To use the libary, clone from github by running the following command:
git clone https://github.com/craigsapp/midifile
Then cd into the midifile/ folder you have just cloned, and run the following command:
make library
You will have a lib/ folder that contains libmidifile.a. Either move this lib/ folder to your home directory, as you did with the include/ folder, or change its path in the Makefile. After you move the lib/ folder, you will not need any of the contents from the midifile/ folder you cloned. 

To compile the program, simply run the "make" command from within the project folder. Our makefile has specified the location of the include directory and which .o files to link. If you encounter any issues, you may need to run "make clean" first, and double check your paths in the Makefile for the lib/ and include/ folders are correct. 

Once the "make" command has been run, two executables will appear. The first is "generate_note_file". This program should be run first. It will the user to specify a musical key, and then create a .txt file with integers corresponding to MIDI note values. The .txt file will be located in the same directory as the other files. Next, the user should run the note_to_midi executable, which creates a .mid file using the specified notes in the notes.txt file.

The .mid file may then be easily played in a midi file player.  
