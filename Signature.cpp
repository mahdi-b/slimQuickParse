//
// Created by Mahdi Belcaid on 10/15/16.
//
#include <iostream>
#include "Signature.h"

//TODO CONVERT int to unsigned ints where possible


using namespace std;

short Signature::binary_search(unsigned int array[], int first, int last, int search_key) {
    int index;

    if (first > last) {
        index = -1;
    } else {
        int mid = (first + last) / 2;
        if (search_key == array[mid])
            index = mid;
        else {

            if (search_key < array[mid]) {
                index = binary_search(array, first, mid - 1, search_key);
            }
            else {
                index = binary_search(array, mid + 1, last, search_key);
            }
        }
    } // end if
    return index;
}

Signature::Signature(unsigned int signatureId) :
        signatureId(signatureId), nbSequences(0), visited(false) {
    cout << "creating new signture with sig: " << signatureId << endl;
    this->sequences = new unsigned int [500];
}
Signature::~Signature(){
    cout << "deleting signature " << this->signatureId << endl;
    delete [] this->sequences;
}

void Signature::addSequence(unsigned int seqId) {
    this->sequences[this->nbSequences] = seqId;
    this->nbSequences++;
    cout << "adding seq: " << seqId <<  " to signature: " << this->signatureId << endl;
    cout << "nb of sequence in signature: " << this->signatureId << " is: " <<  this->nbSequences << endl;
}

short Signature::getPositionOfSeqId(unsigned int seqId){
    return binary_search(this->sequences, 0, this->nbSequences-1, seqId);
}
