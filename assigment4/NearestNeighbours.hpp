#ifndef NEARESTNEIGHBOURS_HPP
#define NEARESTNEIGHBOURS_HPP

#include "armadillo.hpp"

class KNN
{
    private:
        arma::Mat<double> mCovariate;
        arma::Col<int> mResponse;
        unsigned int mObs;
        unsigned int mVar;
    
    public:
        explicit KNN(arma::Mat<double> &covariate, arma::Col<int> &response) : 
            mCovariate(covariate), 
            mResponse(response),
            mObs(covariate.n_cols),
            mVar(covariate.n_rows) {}

        arma::Col<int> Predict(arma::Mat<double>&, unsigned int mK);
};

#endif