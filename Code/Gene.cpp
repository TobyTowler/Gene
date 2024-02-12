//
// Created by Student on 18/01/2024.
//

#include "Gene.h"

#include <utility>
#include <iomanip>
#include <iostream>
#include <algorithm>

Gene::Gene(std::string id, std::string sequence, double propensity) : ID(std::move(id)), sequence(std::move(sequence)),
                                                                                    propensity(propensity) {}

Gene::Gene() : propensity(0.0) {}

std::string Gene::getId() const {
    return ID;
}

std::string Gene::getSequence() const {
    return sequence;
}

double Gene::getPropensity() const {
    return propensity;
}

void Gene::setPropensity(double propensity) {
    Gene::propensity = propensity;
}

bool Gene::operator<(const Gene &rhs) const {
    return this->propensity < rhs.propensity;
}

bool Gene::operator>(const Gene &rhs) const {
    return rhs.propensity < this->propensity;
}

bool Gene::operator<=(const Gene &rhs) const {
    return rhs.propensity >= this->propensity;
}

bool Gene::operator>=(const Gene &rhs) const {
    return this->propensity >= rhs.propensity;
}

std::ostream &operator<<(std::ostream &os, Gene &gene) {
    os <<  std::quoted(gene.ID) << "," << std::quoted(gene.sequence) << "," << gene.propensity;
    return os;
}

std::istream& operator>>(std::istream& is, Gene& gene){
        std::string id, sequence, propensity;

        //get paramaters from input line
        std::getline(is, id, ',');
        std::getline(is, sequence, ',');
        std::getline(is, propensity, '\n');

        //remove " from id and sequence
        id.erase(std::remove(id.begin(), id.end(), '"'), id.end());
        sequence.erase(std::remove(sequence.begin(), sequence.end(), '"'), sequence.end());

        //Create gene object
        gene.ID = id;
        gene.sequence = sequence;
        gene.propensity = std::stoi(propensity);


        return is;
}

