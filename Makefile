
#choose some options.  by default, compiler optimization is turned off
OPT:= -g -std=c++11 


###
# machine-specific configuration setup
###
INC:=$(INC) -I./ -I/${HOME}/include
CXX:= g++
INSTALLPATH:=$(HOME)/bin



###
# end machine specific configuration
###


# list additional libs here
LIBS:= -L/${HOME}/lib -lmidifile


#a few last definitions
ARGS:= $(OPT) $(INC)


# !!! ATTENTION STUDENT, LIST YOUR OBJECT FILES HERE
OTHER= ClassKey.o Chords.o add_notes.o 
TOMIDI= note_to_midi.o
NOTEFILE= generate_note_file.o
OBJFILES= $(OTHER)


###
#BEGIN MAKE RULES
###

#all comes first, so is the default rule when you `make'
all : generate_note_file note_to_midi


note_to_midi : $(TOMIDI)	
	$(CXX) $(ARGS) -o note_to_midi $(OBJFILES) $(TOMIDI) $(LIBS)

generate_note_file : $(OBJFILES) $(NOTEFILE)
	$(CXX) $(ARGS) -o generate_note_file  $(OBJFILES) $(NOTEFILE) $(LIBS)

#simply copy the executables to the installpath
install : all
	cp generate_note_file $(INSTALLPATH)

# a general rule for generating object files.
%.o : %.cpp
	$(CXX) $(ARGS) -c $*.cpp

clean : 
	rm -f $(OBJFILES) generate_note_file note_to_midi

