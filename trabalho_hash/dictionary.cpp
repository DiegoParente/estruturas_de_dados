#include "dictionary.h"
#include <iostream>

float dictionary::collision_measure(unsigned long int added){
	return (float)collisions/added;
}

dictionary::dictionary(size_t size){
	this->size = size;
	words = new word_list[size];
	collisions = 0;
}

unsigned long dictionary::hash(string word){
	unsigned long hash = 5381;
	for(unsigned int it = 0; it<word.length(); it++){
		hash = ((hash << 5) + hash) + word[it];
	}
	return hash;
}

bool dictionary::add_word(string word){
	int k = words[hash(word)%size].add(word);
	if(k==0) return true;
	else if(k==3) collisions++;
	return false;	
}

bool dictionary::remove_word(string word){
	return words[hash(word)%size].remove(word);
}

int dictionary::search(string word){
	int possible_index = hash(word)%size;
	if(words[possible_index].search(word) != NULL) return possible_index;
	else return -1;
}

