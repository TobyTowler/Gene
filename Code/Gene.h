//
// Created by Student on 18/01/2024.
//

#ifndef GENECW_GENE_H
#define GENECW_GENE_H

#include <string>
#include <iostream>
#include <fstream>


class Gene {
private:
    std::string ID;
    std::string sequence;
    double propensity;

public:
    Gene(std::string id, std::string sequence, double propensity);

    Gene();

    [[nodiscard]] std::string getId() const;

    [[nodiscard]] std::string getSequence() const;

    [[nodiscard]]double getPropensity() const;

    void setPropensity(double propensity);

    bool operator<(const Gene &rhs) const;

    bool operator>(const Gene &rhs) const;

    bool operator<=(const Gene &rhs) const;

    bool operator>=(const Gene &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, Gene &gene);

    friend std::istream& operator>>(std::istream& is, Gene& gene);

};


#endif //GENECW_GENE_H
