//
// Created by Mahdi Belcaid on 10/15/16.
//

#include <iostream>

#include "Sequence.h"

using namespace std;

//typedef bitset<8> byte;

Sequence::Sequence(unsigned short nbSignatures) {
    this->signatures = new Signature *[nbSignatures];
    for (int i=0; i< nbSignatures; i++){
        this->signatures[i] = NULL;
    }
}


Sequence::~Sequence() {
    //cout << "deleting sequence " << endl;
    delete [] this->signatures;
}

void Sequence::addSignature(Signature* &sig, unsigned short bandNumber){
    this->signatures[bandNumber] = sig;
}

Signature* Sequence::getSignature(unsigned short bandNumber){
    return this->signatures[bandNumber];
}