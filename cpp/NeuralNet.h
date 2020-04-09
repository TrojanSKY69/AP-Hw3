//
// Created by Administrator on ۰۷/۰۴/۲۰۲۰.
//
#include "Dataset.h"
#include "Matrix.h"
#include "Result.h"
#include <stdlib.h>
#include<time.h>

using namespace std;
#ifndef AP_HW3_NEURALNET_H
#define AP_HW3_NEURALNET_H


class NeuralNet {

private:

    Matrix w1; // Weights of layer 1
    Matrix w2; // Weights of layer 2
    Matrix b1; // Biases of layer 1
    Matrix b2; // Biases of layer 2
    Matrix a1; // Output of layer 1
    Matrix a2; // Output of layer 2
    Matrix n1; // n vector for layer 1
    Matrix n2; // n vector for layer 2
    Matrix s1; // s vector for layer 1
    Matrix s2; // s vector for layer 2
   // vector<Matrix> out_vec;

   //vector<Matrix> w;
   //vector<Matrix> b;




    const char* af1{"Sigmoid"};
    const char* af2{"Sigmoid"};

    size_t hidden_layer_neurons{3};

    double lr{0.01};

    size_t max_iters{1000};

    double min_loss{0.01};

    Dataset dataset;


public:

    NeuralNet(Dataset dataset,
            size_t hidden_layer_neurons,
            const char* f1 = "Sigmoid",
            const char* f2 = "Linear", double lr = 0.01,
            size_t max_iters = 10000, double min_loss=0.01);


                                Matrix forwardPropagate(Matrix& input);

                                void backPropagate(Matrix& input, Matrix& target);

                                double trainLoss();

                                double testLoss();

                void setW1(Matrix& w);
                void setW2(Matrix& w);
                void setB1(Matrix& b);
                void setB2(Matrix& b);

                Matrix getW1();
    Matrix getW2();
    Matrix getB1();
    Matrix getB2();
    Matrix get_a2();
    size_t get_Hiden_n_num();

    void show();

    Matrix sigmoid(Matrix);

    Matrix linear(Matrix);

    //Matrix sigmoid_d(Matrix);

    //Matrix linear_d(Matrix);

    Result fit();
    
};

#endif //AP_HW3_NEURALNET_H
