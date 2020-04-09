//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//
#include "Dataset.h"
#include "Result.h"
#include "NeuralNet.h"
#include <random>

#ifndef AP_HW3_APHW3_H
#define AP_HW3_APHW3_H

Dataset loadFuncDataset(const char* filename);

vector<Result> testNeuralNets(Dataset& dataset, vector<size_t>& hidden_neurons,
        double lr=0.01, size_t max_iters = 10000, const char* af1 = "Sigmoid", const char* af2 = "Linear");

Result findBestNeuralNet(Dataset& dataset, std::vector<size_t>& hidden_neurons,
        double lr=0.01, size_t max_iters = 10000, const char* af1 = "Sigmoid", const char* af2 = "Linear");

void estimateFunction(const char* filename, size_t hidden_neurons_no);


#endif //AP_HW3_APHW3_H
