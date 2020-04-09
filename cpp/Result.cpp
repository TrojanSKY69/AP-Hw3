//
// Created by Administrator on ۰۸/۰۴/۲۰۲۰.
//

#include "Result.h"


bool Result::operator<(Result r) {
    return getTestLoss() < r.getTestLoss();
}

bool Result::operator>(Result r) {
    return getTestLoss() > r.getTestLoss();
}

bool Result::operator<=(Result r) {
    return getTestLoss() <= r.getTestLoss();
}

bool Result::operator>=(Result r) {
    return getTestLoss() >= r.getTestLoss();
}

bool Result::operator==(Result r) {
    return getTestLoss() == r.getTestLoss();
}


ostream& operator<<( ostream& outStream, Result &r )
{
    outStream<<endl<<"Result :"<<endl;
    outStream<<setw(5)<<"Train loss : "<<r.train_loss<<endl;
    outStream<<setw(5)<<"Test loss : "<<r.test_loss<<endl;
    outStream<<setw(5)<<"No of hidden neurons : "<<r.no_of_hidden_neurons<<endl;
    outStream<<setw(5)<<"Layer 1 activation function is : "<<r.af1<<endl;
    outStream<<setw(5)<<"Layer 2 activation function is : "<<r.af2<<endl;

    return outStream;


}
Result::Result()
{

}
Result::Result(double train_loss,
               double test_loss,
               size_t no_of_hidden_neurons,
               double lr , size_t iters,
               const char* af1 ,
               const char* af2 )
{
            this->train_loss=train_loss;
            this->test_loss=test_loss;
            this->no_of_hidden_neurons=no_of_hidden_neurons;
            this->lr=lr;
            this->iters=iters;
            this->af1=af1;
            this->af2=af2;

}


Result::Result(double train_loss,
       size_t no_of_hidden_neurons,
       double lr , size_t iters ,
       const char* af1 ,
       const char* af2 )
{
    this->train_loss=train_loss;
   // this->test_loss=test_loss;
    this->no_of_hidden_neurons=no_of_hidden_neurons;
    this->lr=lr;
    this->iters=iters;
    this->af1=af1;
    this->af2=af2;

}

Result::Result(double test_loss) : Result(-1,0,0.01,10000,"Sigmoid","Linear")
{
    this->test_loss=test_loss;
}

double Result::getTestLoss()
{
    return  test_loss;
}

void Result::show()
{
    cout<<endl<<"Result :"<<endl;
    cout<<setw(5)<<"Train loss : "<<train_loss<<endl;
    cout<<setw(5)<<"Test loss : "<<test_loss<<endl;
    cout<<setw(5)<<"No of hidden neurons : "<<no_of_hidden_neurons<<endl;
    cout<<setw(5)<<"Layer 1 activation function is : "<<af1<<endl;
    cout<<setw(5)<<"Layer 2 activation function is : "<<af2<<endl;
}