#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define TIMES 10

double bench();

int main(){
	system("rm -r instances");
	double measure = 0.0;
	for(int times=0; times < TIMES; times++){
		measure += bench()/TIMES;
	}
	FILE *diagnostic = fopen("diagnostic", "w");
	fprintf(diagnostic, "Todas as instancias foram percorridas %d vezes e a media dos fatores colisoes/insercoes foi avaliada em: %f", TIMES, measure);
	fclose(diagnostic);
	return 0;
}

double bench(){
	system("g++ hashbench.c -o hashbench");
	system("./hashbench");
	FILE *f =  fopen("instances/hashlist", "r");
	string *sv = new string[32];
	float measures[32];
	for(int c=0; c<32; c++){
		char aux[256];
		fscanf(f,"%s" ,aux);
		sv[c] = aux;
	}
	for(int c=0; c<32;c++){
		FILE *instance = fopen(sv[c].c_str(), "r");
		char aux[256];
		int to_add;
		int to_search;
		fscanf(instance, "%s %d", aux, &to_add);
		dictionary *dic = new dictionary(to_add);
		for(int iter=0; iter<to_add;iter++){
			string s_aux;
			char aux_aux[512];
			fscanf(instance, "%s", aux_aux);
			s_aux = aux_aux;
			dic->add_word(s_aux);
		}
		fscanf(instance, "%s %d", aux, &to_search);
		for(int iter=0; iter<to_search;iter++){
			string s_aux;
			char aux_aux[256];
			fscanf(instance, "%s", aux_aux);
			s_aux = aux_aux;
			dic->search(s_aux);
		}
		measures[c] = dic->collision_measure(to_add);
	}
	double mean = 0.0;
	for(int c = 0; c<32;c++){
		mean+=(double)(measures[c]/32);
	}	
	system("rm -r instances");
	return mean;
}