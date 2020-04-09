//
// Created by Administrator on ۰۸/۰۴/۲۰۲۰.
//
#include "Dataset.h"
#include "Matrix.h"
//#include "NeuralNet.h"
using namespace std;

#ifndef AP_HW3_RESULT_H
#define AP_HW3_RESULT_H


class Result {

private:

    double train_loss;
    double test_loss;
    size_t no_of_hidden_neurons;
    double lr{};
    size_t iters{};
    const char* af1;
    const char* af2;

public:

    bool operator<(Result r);

    bool operator>(Result r) ;


    bool operator<=(Result r) ;


    bool operator>=(Result r) ;


    bool operator==(Result r) ;

    friend  ostream& operator<<( ostream& outStream, Result &dr );

    Result(double train_loss, double test_loss,
            size_t no_of_hidden_neurons,
            double lr = 0.01, size_t iters = 10000,
            const char* af1 = "Sigmoid",
            const char* af2 = "Linear");


    Result(double train_loss,
           size_t no_of_hidden_neurons,
           double lr = 0.01, size_t iters = 10000,
           const char* af1 = "Sigmoid",
           const char* af2 = "Linear");



    Result(double test_loss);

     Result();

    double getTestLoss();

    void show();

};
#endif //AP_HW3_RESULT_H
