//
// Created by Mahdi Belcaid on 10/15/16.
//
#include <iostream>
#include "Sequences.h"

using namespace std;

Sequences::Sequences(unsigned int nbSequences, unsigned int nbSigs): nbSequences(nbSequences), nbSigs(nbSigs){
    this->items = new Sequence * [nbSequences];
    for (int i = 0; i < nbSequences; i++) {
        this->items[i] = new Sequence(nbSigs);
    }
}
Sequences::~Sequences(){
    cout << "Destroying " << this->nbSequences << " sequences" << endl;
    for (int i=0; i< this->nbSequences ; i++){
        delete this->items[i];
    }
    delete [] this->items;
}
//Sequence* Sequences::getSeqSignature(unsigned int seqId){
//    return this->items[seqId];
//}



