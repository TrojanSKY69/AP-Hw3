//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//

#include "aphw3.h"
#include "NeuralNet.h"
#include "Result.h"

Dataset loadFuncDataset(const char* filename)
{
    vector<vector<double> > total_data;

    int p=0;
    int r=0;

    ifstream apfile("APHW3Data1.csv");
    string line="";
    while(getline(apfile,line))
    {
        string line_value;
        vector<double> line_values;
        vector<string >stream;
        stringstream s(line);
        //while(getline(s, line_value, ','))
        while(getline(s, line_value ,','))
        {
            stringstream ss(line_value);
            double val;
            ss >> val;
            line_values.push_back(val);
            r++;
        }
       // line_values.pop_back();
        total_data.push_back(line_values);
        p++;
    }
    apfile.close();


    vector<vector<double> > inputs_matrix_data(total_data.size()-1,vector<double>(total_data[0].size(),0));
    vector<vector<double> > targets_matrix_data(1,vector<double >(total_data[0].size(),0));

    Matrix inputs_;
    Matrix targets_;



    for (int i = 0; i <total_data.size()-1 ; ++i) {
        for (int j = 0; j <(total_data[0]).size() ; ++j) {
            inputs_matrix_data[i][j]=total_data[i][j];
        }
    }

    inputs_.set_matrix_data(inputs_matrix_data);

    //cout<<endl<<"AAA"<<endl;

    for (int k = 0; k <(total_data[0]).size() ; ++k) {
        targets_matrix_data[0][k]=total_data[total_data.size()-1][k];
    }

    targets_.set_matrix_data(targets_matrix_data);

    //cout<<endl<<"AAA"<<endl;

    Dataset d(inputs_,targets_,70);

    return d;

}

vector<Result> testNeuralNets(Dataset& dataset, vector<size_t>& hidden_neurons,
                              double lr, size_t max_iters , const char* af1 , const char* af2 )
{
    Result r;
    vector<Result> vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1

    for (int i = 0; i <hidden_neurons.size() ; ++i) {

        NeuralNet nn(dataset,hidden_neurons[i],af1,af2,lr, max_iters);

        Matrix ll=dataset.getInputs();
        Matrix input_sample=ll.col(0);
        array<size_t,2> input_sample_size =input_sample.getSize();


        Matrix w1;
        vector<vector<double> > ww1(hidden_neurons[i],vector<double >(input_sample_size[0],0.1));//2*1
        for (int m = 0; m < hidden_neurons[i] ; ++m) {
            for (int i = 0; i <input_sample_size[0] ; ++i) {

                ww1[m][i]=dis(gen);

            }
        }
        w1.set_matrix_data(ww1);

        Matrix w2;
        vector<vector<double> > ww2(1,vector<double >(ww1.size(),0.1)); //1*2
        for (int m = 0; m <1; ++m) {
            for (int i = 0; i <ww1.size() ; ++i) {

                ww2[m][i]=dis(gen);

            }
        }
        w2.set_matrix_data(ww2);

        Matrix b1;
        vector<vector<double> > bb1(hidden_neurons[i],vector<double >(input_sample_size[1],0.1));//2*1
        for (int m = 0; m <hidden_neurons[i] ; ++m) {
            for (int i = 0; i <input_sample_size[1] ; ++i) {

                bb1[m][i]=dis(gen);

            }
        }
        b1.set_matrix_data(bb1);

        Matrix b2;
        vector<vector<double> > bb2={{0.1}};     //1*1
        for (int m = 0; m <bb2.size() ; ++m) {
            for (int i = 0; i <bb2.size() ; ++i) {

                bb2[m][i]=dis(gen);

            }
        }
        b2.set_matrix_data(bb2);


        //w1.show();
        //w2.show();
        //b1.show();
        //b2.show();

        nn.setW1(w1);
        nn.setB1(b1);
        nn.setW2(w2);
        nn.setB2(b2);




        Result r(nn.trainLoss(),nn.testLoss(),hidden_neurons[i],lr,max_iters,af1,af2);

        vec.push_back(r);

    }

    return vec;

}

Result findBestNeuralNet(Dataset& dataset, std::vector<size_t>& hidden_neurons,
                         double lr, size_t max_iters , const char* af1 , const char* af2 )
{
    //testNeuralNets(dataset,);

    Result r;
    vector<Result> vec1;
    double min=100;
    int index;

    vec1=testNeuralNets(dataset,hidden_neurons,lr,max_iters,af1,af2);

    for (int i = 0; i <vec1.size() ; ++i) {
            if(vec1[i].getTestLoss()<min)
            {
                min=vec1[i].getTestLoss();
                index=i;
            }

    }

    r=vec1[index];

    return r;

}

void estimateFunction(const char* filename, size_t hidden_neurons_no)
{
    vector<vector<double> > total_data;

    int p=0;
    int r=0;

    ifstream apfile("APHW3Data1.csv");
    string line="";
    while(getline(apfile,line))
    {
        string line_value;
        vector<double> line_values;
        vector<string >stream;
        stringstream s(line);
        //while(getline(s, line_value, ','))
        while(getline(s, line_value ,','))
        {
            stringstream ss(line_value);
            double val;
            ss >> val;
            line_values.push_back(val);
            r++;
        }
        // line_values.pop_back();
        total_data.push_back(line_values);
        p++;
    }
    apfile.close();


    vector<vector<double> > inputs_matrix_data(total_data.size()-1,vector<double>(total_data[0].size(),0));
    vector<vector<double> > targets_matrix_data(1,vector<double >(total_data[0].size(),0));

    Matrix inputs_;
    Matrix targets_;



    for (int i = 0; i <total_data.size()-1 ; ++i) {
        for (int j = 0; j <(total_data[0]).size() ; ++j) {
            inputs_matrix_data[i][j]=total_data[i][j];
        }
    }

    inputs_.set_matrix_data(inputs_matrix_data);

    //cout<<endl<<"AAA"<<endl;

    for (int k = 0; k <(total_data[0]).size() ; ++k) {
        targets_matrix_data[0][k]=total_data[total_data.size()-1][k];
    }

    targets_.set_matrix_data(targets_matrix_data);

    //cout<<endl<<"AAA"<<endl;

    Dataset d(inputs_,targets_,70);


    std::random_device rd;

    std::mt19937 gen(rd());


    std::uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1


    //double r2=dis(gen);



    NeuralNet nn(d,hidden_neurons_no,"Sigmoid","Sigmoid",0.01,10000,0.01);

    Matrix ll=d.getInputs();
    Matrix input_sample=ll.col(0);
    array<size_t,2> input_sample_size =input_sample.getSize();


    Matrix w1;
    vector<vector<double> > ww1(hidden_neurons_no,vector<double >(input_sample_size[0],0.1));//2*1
    for (int m = 0; m <hidden_neurons_no ; ++m) {
        for (int i = 0; i <input_sample_size[0] ; ++i) {

            ww1[m][i]=dis(gen);

        }
    }
    w1.set_matrix_data(ww1);





    Matrix w2;
    vector<vector<double> > ww2(1,vector<double >(ww1.size(),0.1)); //1*2
    for (int m = 0; m <1; ++m) {
        for (int i = 0; i <ww1.size() ; ++i) {

            ww2[m][i]=dis(gen);

        }
    }
    w2.set_matrix_data(ww2);

    Matrix b1;
    vector<vector<double> > bb1(hidden_neurons_no,vector<double >(input_sample_size[1],0.1));//2*1
    for (int m = 0; m <hidden_neurons_no ; ++m) {
        for (int i = 0; i <input_sample_size[1] ; ++i) {

            bb1[m][i]=dis(gen);

        }
    }
    b1.set_matrix_data(bb1);

    Matrix b2;
    vector<vector<double> > bb2={{0.1}};     //1*1
    for (int m = 0; m <bb2.size() ; ++m) {
        for (int i = 0; i <bb2.size() ; ++i) {

            bb2[m][i]=dis(gen);

        }
    }
    b2.set_matrix_data(bb2);


    //w1.show();
    //w2.show();
    //b1.show();
    //b2.show();

    nn.setW1(w1);
    nn.setB1(b1);
    nn.setW2(w2);
    nn.setB2(b2);


    nn.fit();

    Matrix dd=d.getInputs();

    Matrix out=nn.forwardPropagate(dd);

    cout<<endl<<setw(15)<<"No"<<setw(15)<<"Target"<<setw(15)<<"Estimated"<<endl;

    for (int l = 0; l <d.getNoOfSamples() ; ++l) {

        Matrix ee=dd.col(l);
        Matrix out=nn.forwardPropagate(ee);

        vector<vector<double> >  vm1;

        vm1=out.getMatrixData();


        vector<vector<double> >  vm;

        vm=(d.getTargets()).col(l).getMatrixData();

        //Matrix mm=nn.get_a2();

        //vector<vector<double> >  vm1;

        //vm1=mm.getMatrixData();

        cout<<setw(15)<<l+1<<setw(15)<<vm[0][0]<<setw(15)<<vm1[0][0];

        cout<<endl;
    }

}