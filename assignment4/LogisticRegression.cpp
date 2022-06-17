#include "LogisticRegression.hpp"
#include "FileReadWrite.hpp"

int main()
{
    // LOAD DATA
    arma::Mat<double> X = readFile("dataX.dat");
    arma::Col<int> Y = readResponse("dataY.dat");

    arma::Mat<double> Test = readFile("dataXtest.dat");

    // TRAINING
    LogisticRegression logistic_regression;
    logistic_regression.Train(X, Y, 0.1, 10e-7);

    // PREDICTION
    arma::Col<int> logistic_result = logistic_regression.Predict(Test);

    // WRITE RESULTS
    WriteResult("LogReg.dat", logistic_result);

    return 0;
}

void LogisticRegression::Train(arma::Mat<double> &covariate, arma::Col<int> &response, double learningRate, double error)
{
    unsigned int covariate_dim = covariate.n_rows;
    unsigned int nObs = covariate.n_cols;

    arma::Col<double> working_weights(covariate_dim);
    arma::Col<double> gradient(covariate_dim);
    working_weights.randu();

    do
    {
        gradient.zeros();

        for(int i = 0; i < nObs; ++i)
        {
            gradient += covariate.col(i) * (response[i] / (1 + std::exp(response[i] * arma::dot(working_weights, covariate.col(i)))));
        }

        working_weights += learningRate * gradient / nObs; 

    } while (arma::norm(gradient) >= error);
    
    mWeights = working_weights;
}

arma::Col<int> LogisticRegression::Predict(arma::Mat<double> &newdata)
{
    arma::Col<int> result(newdata.n_cols);

    for(int i = 0; i < newdata.n_cols; ++i)
    {
        double tmp = arma::dot(mWeights, newdata.col(i));

        if(tmp < 0)
        {
            result[i] = -1;
        } else {
            result[i] = 1;
        }
    }

    return result;
}