#include "aphw3.h"
#include "Matrix.h"
using namespace std;
int main()
{

    ///////////////////////////////////////////// Matrix Class testing
    //default matrix for first constructor
    vector<vector<double> > vect{ { 1, 2, 1,5,788}, { 1, 3, 1,2,654},{ 1, 1, 7,4,342},{2,3,1,0,4565},{0.45,30,56,34,45}};

    //constructor pass by value  2d vector    constructor number1
    Matrix a(vect);

    Matrix b{a};//copy constructor

////////////////////////////////////////////////////////////////This part is for testing additional operations

    vector<vector<double> > vect5{ {1,2,3},{2,3,4},{4,6,4} };
    vector<vector<double> > vect6{ {100,100,100},{2,3,4},{4,6,4} };

    //Rectangular Analaysis
    vector<vector<double> > vect7{ {1,2},{4,7},{2,2},{4,5} };
    vector<vector<double> > vect8{ {1,2,3,44},{4,65,34,5} };
    vector<vector<double> > vect9{ {1,2,3,-44},{-4,65,34,-5} };
    vector<vector<double> > vect10{ {1,2},{-4,65} };

    Matrix z1(vect10);
    (z1.inv()).show();
    Matrix e1(vect8);
    Matrix e2(vect9);
    Matrix e3 = e1 + e2;
    Matrix e4 = e1 - e2;
    (e1.inv()).show();
    e3.show();
    e4.show();
    Matrix r1(vect5);
    Matrix r2(vect6);
    Matrix r3 = r2 + r1;
    r3.show();
    Matrix r10 = r2  -  r1;
    r10.show();
    Matrix r4 = r2 * r1;
    r4.show();
    Matrix r5(vect7);
    Matrix r6(vect8);
    Matrix r9 =  r5 * r6;
    r9.show();
    //show the matrix
    a.show();

                                            a.save("Matrix_Resotre_File.csv");

    array<size_t,2> arr =a.getSize();
    //For showing the size of the matrix  in console.
    cout<<endl<<"Matrix row size is "<<arr[0]<<" Matrix coloumn size is "<<arr[1]<<endl;
    (a.col(1)).show();
    (a.T()).show();
    (a.delCol(2)).show();
    (a.delCol(0)).show();

                                            a.load("Matrix_Resotre_File.csv");

    array<size_t,2> arr2 =a.getSize();
    cout<<endl<<"Matrix row size is "<<arr2[0]<<" Matrix coloumn size is "<<arr2[1]<<endl;
    a.show();
    cout<<a.det();
    (a.inv()).show();


    Matrix m;
    double c=10000;
    m= a.inv()*c;
    m.show();

    //////////////////////////////// Dataset class testing

    /*
    Matrix Inputs();
    Matrix Targets();
    Dataset dataset();
     */

   //// vector<vector<double> > input_Vec(1, vector<double> (3, 1));

   //// vector<vector<double> > target_Vec(1, vector<double> (3, 0.5));


    vector<vector<double> > input_Vec;
    vector<vector<double> > target_Vec;

    input_Vec={{1,2,3,45,4,45,5,6},{4,5,6,4,5,3,4,5},{7,8,9,4,5,6,5,4},{56,45,5,45,5,4,5,6}};

    target_Vec={{0.23,0.34,0.245,45,5,4,3,4},{0.323,0.434,0.84,45,45,45,45,5},{0.33,0.34,0.54,4,5,3,6,9}};

    Matrix inputs_(input_Vec);



    Matrix targets_(target_Vec);


    Dataset dat(inputs_,targets_,70);
    cout<<endl<<dat.getTrainInputs()[0][10]<<endl;
    dat.show();


    //////Testing the public function of Dataset class
    cout<<endl<<"targets is :"<<endl;
    (dat.getTargets()).show();
    cout<<endl<<"inputs is :"<<endl;
    (dat.getInputs()).show();
    cout<<endl<<"train inputs  is :"<<endl;
    (dat.getTrainInputs()).show();
    cout<<endl<<"train target is :"<<endl;
    (dat.getTrainTargets()).show();
    cout<<endl<<"test input is :"<<endl;
    (dat.getTestInputs()).show();
    cout<<endl<<"test target is :"<<endl;
    (dat.getTestTargets()).show();

    cout<<endl<<"num of samples is :"<<endl;
    cout<<dat.getNoOfSamples();
    cout<<endl<<"num of train sample is :"<<endl;
    cout<<dat.getNoOfTrainSamples();
    cout<<endl<<"num of test sample  is :"<<endl;
    cout<<dat.getNoOfTestSamples();
    cout<<endl<<"input dimension  is :"<<endl;
    cout<<dat.getInputDim();
    cout<<endl<<"target dimension  is :"<<endl;
    cout<<dat.getTargetDim();

    ////Shuffle testing

    cout<<endl<<endl;

    (dat.getInputs()).show();
    dat.shuffle();
    (dat.getInputs()).show();

    cout<<endl<<endl;

    (dat.getTargets()).show();
    dat.shuffle();
    (dat.getTargets()).show();

    cout<<endl<<endl;

    (dat.getTestInputs()).show();
    dat.shuffle();
    (dat.getTestInputs()).show();

    cout<<endl<<endl;

    (dat.getTestTargets()).show();
    dat.shuffle();
    (dat.getTestTargets()).show();


    cout<<endl<<endl;

    (dat.getTrainInputs()).show();
    dat.shuffle();
    (dat.getTrainInputs()).show();

    cout<<endl<<endl;

    (dat.getTrainTargets()).show();
    dat.shuffle();
    (dat.getTrainTargets()).show();


    cout<<endl<<"************************************************"<<endl;


    ///////////////////////////////////////////////////////////////////// Neural net testing on real dataset

    Dataset d=loadFuncDataset("APHW3Data1.csv");

    //cout<<endl<<"AAA"<<endl;

   d.show();

   //////////////////////cout<<endl<<"<< Operator oveloading ..."<<d<<endl;

   cout << d;
   //////////////////////////////////////////////////////////////


   (d.getInputs()).show();
   d.getTargets().show();

   d.getTrainInputs().show();
   d.getTrainTargets().show();
   d.getTestInputs().show();
   d.getTestTargets().show();

   /*
    NeuralNet(Dataset dataset,
            size_t hidden_layer_neurons,
    const char* f1 = "Sigmoid",
    const char* f2 = "Linear", double lr = 0.1,
    size_t max_iters = 10000, double min_loss=0.01);
    */

   //d.shuffle();

   //NeuralNet nn(d,3,"Sigmoid","Sigmoid",0.1,10000,0.01);

    NeuralNet nn(d,2);
   nn.show();

   Matrix w1;
   vector<vector<double> > ww1={{-0.27},{-0.42}};//2*1
   // vector<vector<double> > ww1={{1},{1}};//2*1
   w1.set_matrix_data(ww1);

    Matrix w2;
    vector<vector<double> > ww2={{-0.09,-0.17}};  //1*2
    //vector<vector<double> > ww2={{1,1}};  //1*2
    w2.set_matrix_data(ww2);

    Matrix b1;
    vector<vector<double> > bb1={{-0.48},{-0.13}};//2*1
    //vector<vector<double> > bb1={{1},{1}};//2*1
    b1.set_matrix_data(bb1);

    Matrix b2;
    vector<vector<double> > bb2={{0.48}};     //1*1
    //vector<vector<double> > bb2={{1}};     //1*1
    b2.set_matrix_data(bb2);

    nn.setW1(w1);
    nn.setB1(b1);
    nn.setW2(w2);
    nn.setB2(b2);

    //nn.

    Result r;

    r=nn.fit();

    r.show();

    Matrix er{2,2};/////     NOtice this notation is used in google test

    //(nn.getW1()).show();

    /*
    vector<vector<double> > oop{{1,2,3}};
    Matrix L1(oop);

    vector<vector<double> > oop1{{9},{9}};
    Matrix L2(oop1);

    Matrix L3=L2*L1;

    L3.show();

    */


////// findbestneuralnet

    vector<size_t> hid_n={1,2,3,4,5,6,7};

    Result RR= findBestNeuralNet(d , hid_n,
            0.01, 10000, "Sigmoid",
            "Linear");

    RR.show();
/////////////////////////////////////////////////"<< oerator overloading for result class"
    cout<<RR;
///////////////////////////



  /// / ///// we sholud set a weight       final parts       TestNeuralNets  function


    //vector<size_t> hid_n={1,2,3,4,5,6,7};

    cout<<endl<<"*******************************************************************************"<<endl;

    vector<Result> res_vec= testNeuralNets( d, hid_n);

    for (int i = 0; i <res_vec.size() ; ++i) {
        res_vec[i].show();
    }

    ///////////test camparison operator overloading

    cout<<endl<<(res_vec[0]<res_vec[1])<<endl;
    cout<<endl<<(res_vec[0]<=res_vec[1])<<endl;


///////////////Estimating the function

//    estimateFunction("APHW3Data1.csv",2);

//////////////////////////////////////
  ///////////////////////  //Operator overloading Matrix Part
    /*
    Matrix m9{3,3};

    m9[1][2]=85;

    cout<<m9[1][2];
     */
/////////////////////////////// + concating operator for Dataset

    vector<vector<double> > input_Vec1;
    vector<vector<double> > target_Vec1;
    vector<vector<double> > target_Vec2;
    vector<vector<double> > input_Vec2;

    input_Vec1={{1,2,3,45,4,45,5,6},{1,2,3,45,4,45,5,6}};
    input_Vec2={{1,2,3,95,4,45,5,6},{1,2,3,45,4,45,5,6}};
    //input_Vec1={{1,2,3,45,4,45,5,6},{4,5,6,4,5,3,4,5},{7,8,9,4,5,6,5,4},{56,45,5,45,5,4,5,6}};

    target_Vec1={{0.23,0.34,0.245,45,5,4,3,4}};
    target_Vec2={{0.23,0.34,0.245,45,5,4,3,4}};

    Matrix inputs_1(input_Vec1);
    Matrix targets_1(target_Vec1);

    Matrix inputs_2(input_Vec2);
    Matrix targets_2(target_Vec2);

    Dataset dat1(inputs_1,targets_1,70);
    Dataset dat2(inputs_2,targets_2,70);
    Dataset dat3;

    //cout<<endl<<"AAAAAAAAAAA"<<endl;

    dat3=dat1+dat2;

    dat3.show();
/////////////////////////////////////////////////

    //Matrix cc;
    //dat1[4][0];


}
