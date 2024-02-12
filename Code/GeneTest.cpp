//
// Created by Student on 18/01/2024.
//
#include <iostream>
#include "GeneTest.h"
#include "Gene.h"


using namespace std;

bool testGene(){
    //I tried doing test individually, but it said the values were never used, so I changed to larger
    //general if statement tests

    //constructors
    Gene gene0;
    Gene gene1 ("g1", "Sequence 1", 1);
    Gene gene2 ("g2", "Sequence 2", 2.0);
    if(gene0.getId()!="" && gene0.getSequence()!="" &&gene0.getPropensity()==0.0){
        cerr << "Default constructor error" << endl;
        return false;
    }

    //testing setter method
    gene1.setPropensity(1.0);
    if(gene1.getPropensity() != 1.0){
        cerr << "Setter error" << endl;
        return false;
    }

    //testing relational operators
    if(!(gene1<gene2 && gene0<=gene1 && gene2>gene1 && gene1>=gene0)){
        cerr << "Relational operator error" << endl;
        return false;
    }

    //testing getter methods
    if(!(gene1.getId() == "g1" && gene0.getPropensity() == 0.0 && gene2.getSequence() ==  "Sequence 2")){
        cerr << "Accessor error" << endl;
        return false;
    }

    //testing << >> overloading
        // << output to file
        ofstream os("GeneTestFile.csv");
        os << gene1 << endl;
        os.close();

        // >> read from file
        ifstream is("GeneTestFile.csv", ifstream::in);
        //cancels if the file cannot be opened
        if (!is.is_open()) {
            std::cerr << "Error opening file." << std::endl;;
        }
        Gene gene3;
        is >> gene3;
        is.close();
        //if the read and written objects match, the formats are compatible
        if(gene1.getPropensity()!=gene3.getPropensity() && gene1.getSequence()!=gene3.getSequence() &&
        gene1.getId()!=gene3.getId()){
            cerr << "<<  >> error" << endl;
            return false;
        }

    //if no test failed, return true
    return true;
}
