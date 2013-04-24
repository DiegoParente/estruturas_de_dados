#include "word_list.h"
#include <iostream>




word_list::word_list(string word){
	this->word = word;
	this->next = NULL;
	this->prev = NULL;
}

word_list::word_list(string word, word_list *prev){
	this->word = word;
	this->next = NULL;
	this->prev = prev;
}

word_list::word_list(){
	this->word = "";
	this->next = NULL;
	this->prev = NULL;
}

int word_list::add(string word){
	if(search(word) != NULL){
		return 0;
	}
	else if(this->word == ""){
			this->word = word;
			return 1;
	}
	else{
			//colisao
			word_list *aux =  this;
			while(aux != NULL) aux = aux->next;
			aux = new word_list(word, this);
			this->next = aux;
			return 3;
	}
}

bool word_list::remove(string word){
	word_list *to_remove = search(word);
	if(to_remove == NULL) return false;
	word_list *aux = to_remove->prev;
	to_remove->prev->next = next;
	to_remove->next->prev = aux;
	free(to_remove);
	return true;
}

word_list* word_list::search(string word){
	word_list *aux =  this;
	while(aux != NULL){
		if(aux->word == word) return aux;
		else aux = aux->next; 
	}
	return NULL;
}