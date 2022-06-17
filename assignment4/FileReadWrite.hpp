#ifndef FILEREADWRITE_HPP
#define FILEREADWRITE_HPP
#include "armadillo.hpp"

arma::Mat<double> readFile(std::string fileName)
{
    std::ifstream countfile(fileName);

    std::string line;

    unsigned int nObs = 0;
    unsigned int nVar = 0;

    while(getline(countfile, line))
    {
        std::stringstream lineStream(line);
        double tmp;

        if(nVar == 0)
        {
            while(lineStream >> tmp)
            {
                ++nVar;
            }
        }

        ++nObs;
    }

    arma::Mat<double> result(nVar, nObs);

    std::ifstream readfile(fileName);

    unsigned int row = 0;
    
    while(getline(readfile, line))
    {
        std::stringstream lineStream(line);
        double tmp;
        
        unsigned int col = 0;

        while(lineStream >> tmp)
        {
            result(col, row) = tmp;
            ++col;
        }
        ++row;        
    }

    return result;

}

arma::Col<int> readResponse(std::string fileName)
{
    std::ifstream countfile(fileName);

    std::string line;

    unsigned int nObs = 0;

    while(getline(countfile, line))
    {
        ++nObs;
    }

    arma::Col<int> result(nObs);

    std::ifstream readfile(fileName);

    unsigned int row = 0;
    
    while(getline(readfile, line))
    {
        std::stringstream lineStream(line);
        int tmp;

        while(lineStream >> tmp)
        {
            result[row] = tmp;
        }
        ++row;        
    }

    return result;

}

void WriteResult(std::string filename, arma::Col<int> result)
{
    std::ofstream file;
    file.open(filename);

    for(auto elem : result)
    {
        file << elem << "\n";
    }

    file.close();
}

#endif