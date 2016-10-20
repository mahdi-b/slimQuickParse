    Sequences *pSequencesList = new Sequences(NB_SEQS , NB_BANDS);


// sig0    0.123 = 1,2,3
// sig1    0.45 = 4,5
//
// sig2   1.12 = 1,2
// sig2   1.3 = 3
// sig2   1.45 = 4, 5


// building a list of signatures;


    std::cout << "Creating signatures!" << std::endl;
    Signature *sig0 = new Signature(0.012);
    sig0->addSequence(0);
    sig0->addSequence(1);
    sig0->addSequence(2);
    pSequencesList->items[0]->addSignature(sig0, 0);
    pSequencesList->items[1]->addSignature(sig0, 0);
    pSequencesList->items[2]->addSignature(sig0, 0);


    Signature *sig1 = new Signature(0.34);
    sig1->addSequence(3);
    sig1->addSequence(4);

    pSequencesList->items[3]->addSignature(sig1,0);
    pSequencesList->items[4]->addSignature(sig1,0);


    Signature *sig2 = new Signature(1.01);
    sig2->addSequence(0);
    sig2->addSequence(1);

    pSequencesList->items[0]->addSignature(sig2,1);
    pSequencesList->items[1]->addSignature(sig2,1);

    Signature *sig3 = new Signature(1.2);
    sig3->addSequence(2);
    pSequencesList->items[2]->addSignature(sig3,1);


    Signature *sig4 = new Signature(1.34);
    sig4->addSequence(3);
    sig4->addSequence(4);
    pSequencesList->items[3]->addSignature(sig4,1);
    pSequencesList->items[4]->addSignature(sig4,1);



    int *partitions = findPartitions(pSequencesList, 5, 2);



    cout << "done with the anlysis" << endl;


    delete pSequencesList;

    //delete partitions;

    delete sig0;
    delete sig1;
    delete sig2;
    delete sig3;
    delete sig4;






    // diplay info for first 5 sequences.
    // add this to a function
    for (unsigned int i = 0; i < 6; ++i) {
        for (unsigned short j = 0; j < 2; ++j) {
            cout << pSequencesList->items[i]->signatures[j]->signatureId << "\t";
        }
        cout << endl;
    }
