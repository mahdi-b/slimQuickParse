//
// Created by Mahdi Belcaid on 10/15/16.
//

#include <iostream>

#include "Sequence.h"

using namespace std;

//typedef bitset<8> byte;

Sequence::Sequence(unsigned int seqId, unsigned short nbSignatures) : seqId(seqId) {

    this->signatures.resize(nbSignatures);
    for (int i=0; i< nbSignatures; i++){
        this->signatures[i] = NULL;
    }
}


Sequence::~Sequence() {
    //cout << "deleting sequence " << endl;
    //cout << "destroying sequnce id: " << this->seqId<< endl;
    //delete [] this->signatures;
    //cout << "--" << endl;
}
//
void Sequence::addSignature(Signature* &sig, unsigned short bandNumber){
    this->signatures[bandNumber] = sig;
}
void Sequence::addSignature(Signature* &sig){
    this->signatures[this->signatures.size()] = sig;
}

Signature* Sequence::getSignature(unsigned short bandNumber){
    return this->signatures[bandNumber];
}