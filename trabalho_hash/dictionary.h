#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include "word_list.h"
using namespace std;

class dictionary{

public:
	dictionary(size_t size);//a constructor the intializes the array of word_list with the size of choice
	int search(string word); //returns -1 if the word is not in the dictionary, else it returns the index of it
	bool add_word(string word);//returns false if the word is already inside the dictionary, else, it inserts the word and returns true
	bool remove_word(string word);// returns false if the word isn't inside the dictionary, else, it removes the word and returns true 
	float collision_measure(unsigned long int added);
private:
	unsigned long int collisions;
	size_t size;//word_list array size
	unsigned long hash(string word);
	word_list *words;// word_list array
};

#endif