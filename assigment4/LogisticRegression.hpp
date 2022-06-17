#ifndef LOGISTICREGRESSION_HPP
#define LOGISTICREGRESSION_HPP

#include "armadillo.hpp"

class LogisticRegression
{
    private:
        arma::Col<double> mWeights;
    
    public:

        LogisticRegression() {}
            
        void Train(arma::Mat<double> &covariate, arma::Col<int> &response, double learningRate, double error);
        arma::Col<int> Predict(arma::Mat<double> &newdata);
        arma::Col<double> Weights() const {return mWeights;}
};

#endif