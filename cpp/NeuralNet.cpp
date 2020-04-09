//
// Created by Administrator on ۰۷/۰۴/۲۰۲۰.
//

#include "NeuralNet.h"

NeuralNet::NeuralNet(Dataset dataset, size_t hidden_layer_neurons, const char* f1 ,
const char* f2 , double lr , size_t max_iters , double min_loss)
{
    this->dataset=dataset;
    this->hidden_layer_neurons=hidden_layer_neurons;
    this->af1=f1;
    this->af2=f2;
    this->lr=lr;
    this->max_iters=max_iters;
    this->min_loss=min_loss;
}

 Result NeuralNet::fit()
 {

    Matrix in_sample;
    Matrix tr_sample;
    Matrix forward_out;
    size_t random_num;

     srand(time(0));

     for (int i = 0; i < max_iters ; ++i) {

         //cout<<endl<<trainLoss()<<endl;
         //cout<<endl<<testLoss();

         //w1.show();
         //w2.show();

         if (trainLoss()<=min_loss)
         {

             break;
         }


                                 //dataset.shuffle();


                                 random_num=rand()%dataset.getNoOfTrainSamples();

                                //cout<<random_num<<endl;

                                 in_sample=(dataset.getTrainInputs()).col(random_num);               //a train sample
                                 tr_sample=(dataset.getTrainTargets()).col(random_num);             //a target sample

                                 a2=forwardPropagate(in_sample);  // the out put of forward NN a2 1*1 matrix

                                 //cout<<"target and a2 "<<endl;
                                 //tr_sample.show();
                                 //a2.show();


         backPropagate(in_sample,tr_sample);  //  for updating biass and weights

     }

                                                  //a2_vec;
                                               /*  for (int j = 0; j < dataset.getNoOfSamples(); ++j) {


                                                     Matrix dd = dataset.getInputs();
                                                     Matrix ee = dd.col(j);
                                                     Matrix out = forwardPropagate(ee);

                                                     out_vec.push_back(out);
                                                 }*/

    Result R(trainLoss(),testLoss(),hidden_layer_neurons,lr,max_iters,af1,af2);
        //Result R(testLoss());
     return R;

 }

void NeuralNet::backPropagate(Matrix& input, Matrix& target)
{
    double c=-2;

    Matrix I;

                                    vector<vector<double> > n_;
                                    //vector<vector<double> > i_;
                                    n_=n2.getMatrixData();
                                    vector<vector<double > >i_(n_.size(),vector<double >(n_[0].size(),0));

                                    for (int i = 0; i <n_.size() ; ++i) {
                                        for (int j = 0; j <n_[0].size() ; ++j) {
                                            i_[i][j]=1;
                                        }
                                    }

    I.set_matrix_data(i_);


    if (af2=="Sigmoid")
    {
        s2=sigmoid(n2)*(I-sigmoid(n2))*(target-a2)*c;
    }
    else{

        s2=linear(n2)*(target-a2)*c;
    }

                            if (af1=="Sigmoid")
                            {
                                s1=sigmoid(n1)*(I-sigmoid(n1))*(w2.T())*s2;
                            }
                            else
                            {
                                s1=linear(n1)*(w2.T())*s2;
                            }


    //////Weights and biases updates

    w1=w1-s1*(input.T())*lr;

    b1=b1-s1*lr;

    w2=w2-s2*(a1.T())*lr;

    b2=b2-s2*lr;

}

Matrix NeuralNet::forwardPropagate(Matrix& input)
{

    n1=(w1*input+b1);  //the out put of layer 1  before entering activation function      //2*1

    //n1.show();

                                    if (af1=="Sigmoid")
                                    {
                                        a1=sigmoid(n1);  // the out put of layer one and the input of layer 2         //2*1
                                        //a1.show();
                                    }
                                    else {

                                        a1=linear(n1);
                                       // a1.show();
                                    }

    //a1.show();

    n2=(w2*a1+b2);     //the out put of layer 2  before entering activation function 1*1

    //array<size_t,2> arr =n2.getSize();
    //cout<<endl<<arr[0]<<arr[1];
    //n2.show();

    if (af2=="Sigmoid")
    {
        a2=sigmoid(n2);  // the out put of layer 2 and the final output
    }
    else {

        a2=linear(n2);
    }
    //a2.show();
    return a2;
}


double NeuralNet::trainLoss()
{

    /*
    double j_train=0;
    double m=dataset.getNoOfTrainSamples();
    double m1=2*m;

    Matrix train_target=dataset.getTrainTargets();
    Matrix train_inputs=dataset.getTrainInputs();//



    vector<vector<double > > train_t;
    vector<vector<double > > nn_t;

    train_t=train_target.getMatrixData();//train target in dataset

    nn_t=a2.getMatrixData(); // output from NN

    for (int i = 0; i <m ; ++i) {
        for (int j = 0; j <train_t.size() ; ++j) {
            j_train=pow(nn_t[i][j]-train_t[i][j],2);
        }
    }
    j_train=j_train/m1;
    return j_train;

    */

    /*
    Matrix train_inputs=dataset.getTrainInputs();

    Matrix input_samples=train_inputs.T();

    Matrix input_sample;

    vector<vector<double > > in_sample=input_samples.getMatrixData();

    //input_sample.set_matrix_data(in_sample[][0]);

    for (int i = 0; i < in_sample.size() ; ++i) {

        input_sample.set_matrix_data();
        Matrix NN_out=forwardPropagate(input_sample);

    }

*/

    double j_train=0;
    double m=dataset.getNoOfTrainSamples();
    double m1=2*m;


    Matrix train_inputs=dataset.getTrainInputs();
    Matrix train_target=dataset.getTrainTargets();
    double sum=0;
    Matrix  sample_output;
    //vector<vector<double > > vec(1,vector<double >(1,0));
                               // Matrix diff(vec);
                                for (int i = 0; i <dataset.getNoOfTrainSamples() ; ++i) {
                                    Matrix m=train_inputs.col(i);
                                    sample_output=forwardPropagate(m);

                                     //diff =sample_output-train_target.col(i)+diff;
                                    vector<vector<double > > s1  =sample_output.getMatrixData();
                                    vector<vector<double > > s2  =train_target.col(i).getMatrixData();


                                    sum=pow(s1[0][0]-s2[0][0],2)+sum;

                                     //sum= static_cast<double >(pow(sample_output-train_target.col(i),2))+sum
                                }

    j_train=sum/m1;


    return  j_train;

}

double NeuralNet::testLoss()
{

    /*
    double j_test=0;
    double m=dataset.getNoOfTestSamples();
    double m1=2*m;

                                    Matrix test_target=dataset.getTestTargets();

                                    vector<vector<double > > test_t;
                                    vector<vector<double > > nn_t;

                                    test_t=test_target.getMatrixData();//test target in dataset

                                    nn_t=a2.getMatrixData(); // output from NN

                                    for (int i = 0; i <m ; ++i) {
                                        for (int j = 0; j <test_t.size() ; ++j) {
                                            j_test=pow(nn_t[i][j]-test_t[i][j],2);
        }
    }
    j_test=j_test/m1;
    return j_test;
*/


    double j_test=0;
    double m=dataset.getNoOfTestSamples();
    double m1=2*m;


    Matrix test_inputs=dataset.getTestInputs();
    Matrix test_target=dataset.getTestTargets();
    double sum=0;
    Matrix  sample_output;
    //vector<vector<double > > vec(1,vector<double >(1,0));
    // Matrix diff(vec);
                                        for (int i = 0; i <dataset.getNoOfTestSamples() ; ++i) {
                                            Matrix m=test_inputs.col(i);
                                            sample_output=forwardPropagate(m);

                                            //diff =sample_output-train_target.col(i)+diff;
                                            vector<vector<double > > s1  =sample_output.getMatrixData();
                                            vector<vector<double > > s2  =test_target.col(i).getMatrixData();


                                            sum= static_cast<double_t >(pow(s1[0][0]-s2[0][0],2))+sum;

                                            //sum= static_cast<double >(pow(sample_output-train_target.col(i),2))+sum
                                        }

    j_test=sum/m1;


    return  j_test;




}



Matrix NeuralNet::sigmoid(Matrix n_)
{
    vector<vector<double> > N;
    Matrix sig_out;
    double exp_value;
    N=n_.getMatrixData();
    vector<vector<double > >sigmoid_output(N.size(),vector<double >(N[0].size(),0));

                                        for (int i = 0; i <N.size() ; ++i) {
                                            for (int j = 0; j <N[0].size() ; ++j) {
                                                exp_value = exp(-N[i][j]);
                                                sigmoid_output[i][j]=1 / (1 + exp_value);

                                            }
                                        }
                                        sig_out.set_matrix_data(sigmoid_output);
                                        return sig_out;
}

Matrix NeuralNet::linear(Matrix n_)
{
    vector<vector<double> > N;
    Matrix lin_out;
    N=n_.getMatrixData();
    vector<vector<double > >linear_output(N.size(),vector<double >(N[0].size(),0));

                                for (int i = 0; i <N.size() ; ++i) {
                                    for (int j = 0; j <N[0].size() ; ++j) {

                                        linear_output[i][j]=N[i][j];
                                    }
                                }
    lin_out.set_matrix_data(linear_output);
    return  lin_out;
}



                            void NeuralNet::show()
                            {
                                cout<<endl<<"Neural Network :"<<endl;
                                cout<<setw(5)<<"No of hidden neurons : "<<hidden_layer_neurons<<endl;
                                cout<<setw(5)<<"Input dimension : "<<dataset.getInputDim()<<endl;
                                cout<<setw(5)<<"Output dimension : "<<dataset.getTargetDim()<<endl;
                                cout<<setw(5)<<"Layer 1 activation function is : "<<af1<<endl;
                                cout<<setw(5)<<"Layer 2 activation function is : "<<af2<<endl;
                            }

void NeuralNet::setW1(Matrix& w)
{
    w1=w;
}

void NeuralNet::setW2(Matrix& w)
{
    w2=w;
}

void NeuralNet:: setB1(Matrix& b)
{
    b1=b;
}

void NeuralNet::setB2(Matrix& b)
{
    b2=b;
}
Matrix NeuralNet:: getW1()
{
    return  w1;
}
Matrix NeuralNet::getW2()
{
    return  w2;
}

Matrix NeuralNet::getB1()
{
    return b1;
}

Matrix NeuralNet::getB2()
{
    return  b2;
}
size_t NeuralNet::get_Hiden_n_num()
{
    return  hidden_layer_neurons;
}

Matrix NeuralNet::get_a2()
{
    return a2;
}