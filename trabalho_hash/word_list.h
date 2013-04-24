#ifndef WORD_LIST_H
#define WORD_LIST_H
#include<string>
using namespace std;

class word_list{
public:
	word_list();
	word_list(string word);
	word_list(string word, word_list *prev);
	string word;
	word_list *next;
	word_list *prev;
	int add(string word);
	bool remove(string word);
	word_list *search(string word);
};


#endif