#include "NearestNeighbours.hpp"
#include "FileReadWrite.hpp"

int main()
{
    // LOAD DATA
    arma::Mat<double> X = readFile("dataX.dat");
    arma::Col<int> Y = readResponse("dataY.dat");

    arma::Mat<double> Test = readFile("dataXtest.dat");

    // TRAINING
    KNN nearest_neighbors(X, Y);

    // PREDICTION
    arma::Col<int> KNN_result = nearest_neighbors.Predict(Test, 5);

    // WRITE RESULTS
    WriteResult("NN.dat", KNN_result);

    return 0;
}

arma::Col<int> KNN::Predict(arma::Mat<double> &observed, unsigned int mK)
{
    arma::Col<int> result(observed.n_cols);

    for(int i = 0; i < observed.n_cols; ++i)
    {
        arma::Col<double> normvector(mObs);

        for(int j = 0; j < mObs; ++j)
        {
            normvector[j] = arma::norm(mCovariate.col(j) - observed.col(i));
        }

        arma::uvec T = arma::sort_index(normvector);

        int count = 0;

        for(int k = 0; k < std::min(mVar, mK); ++k)
        {
            if(mResponse[T[k]] == -1)
            {
                ++count;
            }
        }


        if(count > std::min(mVar, mK) - count)
        {
            result[i] = -1;
        } else {
            result[i] = 1;
        }

    }

    return result;

}