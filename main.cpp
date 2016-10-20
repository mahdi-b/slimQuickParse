#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "Signature.h"
#include "Sequence.h"
#include "Sequences.h"



using namespace std;


// require a: delete partitions
// returns NULL a sequence is not fund in a signature
unsigned int *findPartitions(const Sequences *pSequencesList, unsigned int nbSequences, unsigned short nbBands) {
    cout << "Working on NB_SEQS=" <<  nbSequences << "\n";
    unsigned int *partitions = new unsigned int[nbSequences];

    queue<unsigned int> myQueue;
    set<unsigned int> neighborsSet;

//    // diplay info for first 5 sequences.
//    // add this to a function
//    for (int i =0; i< 5; i++) {
//        cout << "Sequence " << i << endl;
//        for (int j = 0; j < 2; ++j ){
//            cout << pSequencesList->items[i]->signatures[j] << "\t";
//        }
//        cout << endl;
//    }

    // Initialize all the sequences partitions to -1
    for (unsigned int i = 0; i < nbSequences; ++i) {
        partitions[i] = -1;
    }
    // We start with partitionId 0 and we increment the number for each new partition

    int nextPartitonId = -1; // nbPartitions > max int value??

    for (unsigned int i = 0; i < nbSequences; ++i) {
        if (partitions[i] == -1) {
            // Assign it to its own cluster
            // Cannot belong to a previous cluster, or else it would have been labeled through another sequence
            partitions[i] = ++nextPartitonId;
        } else {
            // Was already assigned as part of another sequence
            continue;
        }
        // Add the sequence to a queue so as to inspect its children
        myQueue.push(i);
        cout << "Queueing sequence " << i << endl;

        while (!myQueue.empty()) {

            unsigned int newSeqId = myQueue.front();
            // dequeue the element
            myQueue.pop();

            // For each signature that this sequence is involved in
            // get all the other sequences that are in the same signature
            for (unsigned short bandNumber = 0; bandNumber < nbBands; bandNumber++) {
                Signature *sig = pSequencesList->items[newSeqId]->getSignature(bandNumber);

                // if signature is visited, (or if null  (had only one read in it)?)
                // we do not need to process it further
                if (sig->visited)
                    continue;

                // search for the position of the sequence of the dequeued sequence

                short newSeqIdPosition = sig->getPositionOfSeqId(newSeqId);
                if (newSeqIdPosition == -1) {
                    cout << "Couldn't find sequence: " << newSeqId << "in Signature" << sig->signatureId << endl;
                    return NULL;
                }
                unsigned int seqSig;

                // We start at the position where we found the sequence,  since all sequences
                // before it would have been assigned already.
                // Given that seqIds are incremental we are sure
                // that any sequence before it has already been assigned to a partition
                for (unsigned short seqIdx = (newSeqIdPosition+1); seqIdx < sig->nbSequences; seqIdx++) {
                    seqSig = sig->sequences[seqIdx];
                    // We check if it is -1, in case this was already changed by another sequence in the same components
                    if (partitions[seqSig] == -1) {
                        // if sequence was not assigned to a cluster
                        // then add it to the queue to process other sequences in its cluster
                        neighborsSet.insert(seqSig);
                    }
                }
                sig->visited = true;
            }

            // Now that we have all the neighbors in the same signature as this one,
            // Assign them all to the same signature as sequence i
            // and add them to the queue so that we can process their neighbors
            set<unsigned int>::iterator it;
            for (it = neighborsSet.begin(); it != neighborsSet.end(); ++it) {
                partitions[*it] = partitions[i];
                cout << *it << endl;
                myQueue.push(*it);
            }
            queue<unsigned int> myQueue2 = myQueue;
            while (!myQueue2.empty()){
                cout << myQueue2.front() << "\t";
                myQueue2.pop();
            }
            cout << endl;
            neighborsSet.clear();
            //if ((queue.size() % 1000)==0)
            //System.out.println(" queue is: "+queue.size()+" in size");
        }


    }
    cout << "partitions are:" << endl;
    for (int i = 0; i < nbSequences; ++i) {
        cout << partitions[i] << " ";
    }
    cout << endl << endl << endl;

    return partitions;
}


void parseInputFile (string filePath, unsigned int &NB_SEQS, unsigned short &NB_BANDS,
                     Sequences* &pSequencesList, vector<Signature *> &pSignaturesList){

    ifstream input("/tmp/testfile.txt_");

    vector<string> lineTokens;
    vector<string> sequences;

    int bandNumber = 0;
    for (string l; getline(input, l);) {
        // line is signatureNumber  bandId  comma separated list of sequences in this signature
        boost::split(lineTokens, l, boost::is_any_of("\t"));
        Signature *sig = new Signature(boost::lexical_cast<unsigned int>(lineTokens[0]));


        boost::split(sequences, lineTokens[1], boost::is_any_of(","));
        for (vector<string>::iterator it = sequences.begin(); it != sequences.end(); ++it) {
            unsigned int seqId = boost::lexical_cast<unsigned int>(*it);
            unsigned short bandNumber = boost::lexical_cast<unsigned short>(lineTokens[2]);

            sig->addSequence(seqId);
            pSequencesList->items[seqId]->signatures[bandNumber] = sig;

        }
        pSignaturesList.push_back(sig);
    }




}



int main() {
    // NB_BANDS at most 255 (unsigned short)
    unsigned int NB_SEQS = 6;
    unsigned short NB_BANDS = 2;

    std::cout << "Starting analysis" << std::endl;


    // this is not needed. Unless we need to trverse the signatures...
    // We can just assign the signature to its first sequence
    // and copy the pointer in the other sequences
    vector<Signature *> pSignaturesList;

    Sequences * pSequencesList = new Sequences(NB_SEQS, NB_BANDS);





    cout << "Loading signatures files " << endl;
    parseInputFile("/tmp/testfile.txt_", NB_SEQS, NB_BANDS, pSequencesList, pSignaturesList);


    cout << "Finding partiotns " << endl;
    //unsigned int* partitions = findPartitions(pSequencesList, NB_SEQS, NB_BANDS);


    cout << "Cleaning data structures" << endl;
    delete pSequencesList;
    for (int i = 0; i < pSignaturesList.size(); i++) {
        delete pSignaturesList[i];
    }


    return 0;


}

