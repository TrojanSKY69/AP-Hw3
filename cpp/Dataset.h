//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//
#include "Matrix.h"

#include <bits/stdc++.h>

#include <ctime>

#include <vector>

#include<fstream>

#include <sstream>

#include <string>

#include<algorithm>

#include <iomanip>

#include<cmath>

#include<array>
using namespace std;

#ifndef AP_HW3_DATASET_H
#define AP_HW3_DATASET_H
class Dataset {

    private:

                    Matrix inputs;     //aphw3

                    Matrix targets;   //aphw3

                    Matrix train_inputs; //used

                                    Matrix train_targets;

                                    Matrix test_inputs;

                                    Matrix test_targets;

                                                double percentage=70;    // used

                                                size_t no_of_samples;   // used

                                                size_t input_dim;     //used

                                                size_t target_dim; //used

                                                Matrix sample;

                                    Matrix sample_input;

                                    Matrix sample_output;

                                    Matrix sample_part_selected;

                                    vector<double> lp;

                    public:

                                            Matrix &operator[](unsigned int index);
                                            Matrix &operator[](int index);
                                            vector<double> &operator[](double index);
                                            double &operator[](float index);

                                            Dataset operator+(const Dataset& dataset);

                                            friend  ostream& operator<<( ostream& outStream, Dataset &d );

                                            Dataset();

                                                                        Dataset(Matrix, Matrix , double percentage=70);

                                                                        size_t getNoOfSamples();   // created

                                                                        size_t getNoOfTrainSamples();    // created

                                                                        size_t getNoOfTestSamples();     // created

                                                    size_t getInputDim();      // created

                                                    size_t getTargetDim();      // created

                                                    Matrix getInputs();  // created

                                                    Matrix getTargets();   // created

                                                    Matrix getTrainInputs();

                                    Matrix getTrainTargets();

                                    Matrix getTestInputs();

                                    Matrix getTestTargets();

                                    void shuffle();

                                    void show();


};
#endif //AP_HW3_DATASET_H
