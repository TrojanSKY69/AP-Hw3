//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//

#include "Dataset.h"
/*
Matrix& Dataset::operator[](unsigned int index)
{
    Matrix sample_i;
    sample_i=inputs.col(index);

    Matrix sample_o;
    sample_o=targets.col(index);


    vector<vector<double>> v1;
    vector<vector<double>> v2;


    v1=sample_i.getMatrixData();
    v2=sample_o.getMatrixData();


    vector<vector<double>> v3(v1.size()+1,vector<double >(1,0));

    for (int i = 0; i <v1.size() ; ++i) {
        v3.push_back(v1[i]);
    }

    for (int i = 0; i <v2.size() ; ++i) {
        v3.push_back(v2[i]);
    }

    Matrix mat;
    mat.set_matrix_data(v3);

    sample=mat;

    return  mat;

}*/
/*
Matrix &Dataset::operator[](int index)
{
    vector<vector<double> > vec;
    vector<vector<double> > in_vec;
    vector<vector<double> > out_vec;
    Matrix sample_in;
    Matrix sample_o;


    vec=sample.getMatrixData();

    if(index==0)
    {


        for (int i = 0; i <vec.size()-1 ; ++i) {
            in_vec.push_back(vec[i]);
        }
        sample_in.set_matrix_data(in_vec);

        sample_part_selected=sample_in;
        cout<<"swswsw";

        return  sample_part_selected;
    } else{

        for (int i = 0; i <1 ; ++i) {
            out_vec.push_back(vec[vec.size()]);
        }
        sample_o.set_matrix_data(out_vec);

        sample_part_selected=sample_o;
        cout<<"swswsw";
        return  sample_part_selected;
    }

}
*/
/*
vector<double> &Dataset::operator[](double index)
{
vector<vector<double>> dd;
dd=sample_part_selected.getMatrixData();
lp=dd[index];
return lp;
}

double &Dataset::operator[](float index)
{
    return lp[index];
}
*/

Dataset Dataset::operator+(const Dataset& dataset)
{

                //Dataset d;
                //dataset.getInputs();
                Matrix i1=inputs;
                Matrix i2=dataset.inputs;

                        vector<vector<double> > vec1;
                        vector<vector<double> > vec2;


                                    vec1=i1.getMatrixData();
                                    vec2=i2.getMatrixData();

                                                vector<vector<double> > vec_in_concat(vec1.size()+vec2.size(),vector<double>(no_of_samples,0));

                                                for (int i = 0; i <vec1.size() ; ++i) {
                                                    for (int j = 0; j < no_of_samples; ++j) {
                                                        vec_in_concat[i][j]=vec1[i][j];
                                                    }
                                                }


    for (int i = 0; i <vec2.size() ; ++i) {
        for (int j = 0; j < no_of_samples; ++j) {
            vec_in_concat[i+vec1.size()][j]=vec1[i][j];
        }
    }

                                        //cout<<endl<<"XXXXXXXXXXXXXXXXXXXX";

                                        Matrix mat_in_concat;
                                        mat_in_concat.set_matrix_data(vec_in_concat);


                                        inputs=mat_in_concat;//Set our new Concatinated inputs.

                                                                                                                            //inputs.show();

                                                        Matrix o1=targets;
                                                        Matrix o2=dataset.targets;

                                                        vector<vector<double> > vec3;
                                                        vector<vector<double> > vec4;


                                    vec3=o1.getMatrixData();
                                    vec4=o2.getMatrixData();

                                    vector<vector<double> > vec_o_concat(vec3.size()+vec4.size(),vector<double>(no_of_samples,0));

                                    for (int i = 0; i <vec3.size() ; ++i) {
                                        for (int j = 0; j < no_of_samples; ++j) {
                                            vec_o_concat[i][j]=vec3[i][j];
                                        }
                                    }

    for (int i = 0; i <vec4.size() ; ++i) {
        for (int j = 0; j < no_of_samples; ++j) {
            vec_o_concat[i+vec3.size()][j]=vec3[i][j];
        }
    }

                                    Matrix mat_o_concat;
                                    mat_o_concat.set_matrix_data(vec_o_concat);

                                    targets=mat_o_concat;//Set our new Concatinated targets.
                                                                                                                   // targets.show();
                                    Dataset d_new(inputs,targets,70);

                                    return  d_new;

}



 ostream& operator<<( ostream& outStream, Dataset &d )
{


/*
    friend ostream& operator<<( ostream& outStream, matrix &b ) {
        for(unsigned int i = 0; i < b.matrix_double.size(); i++, outStream << endl)
            for(vector<double>::iterator it = b.matrix_double[i].begin(); it != b.matrix_double[i].end(); it++)
                outStream << *it << ' ';
        outStream.clear();
        return outStream;

    */

/*

    vector<vector<double> > inputs_matrix_data;
    vector<vector<double> > targets_matrix_data;


    inputs_matrix_data=(d.getInputs()).getMatrixData();
    targets_matrix_data=(d.getTargets()).getMatrixData();


    vector<vector<double> > dataset(inputs_matrix_data.size()+1,vector<double>(d.getNoOfSamples(),0));

    for (int i = 0; i <inputs_matrix_data.max_size()+1 ; ++i ,outStream << endl) {
        for (int j = 0; j < d.getNoOfSamples(); ++j) {
            outStream << dataset[i][j] <<' ';
        }
    }

*/
                                         outStream<<endl<<"Dataset :"<<endl;
                                         outStream<<setw(5)<<"No of samples: "<<d.no_of_samples<<endl;
                                         outStream<<setw(5)<<"Train samples: "<<d.getNoOfTrainSamples()<<endl;
                                         outStream<<setw(5)<<"Test  samples: "<<d.getNoOfTestSamples()<<endl;
                                         outStream<<setw(5)<<"Input dimensions : "<<d.input_dim<<endl;
                                         outStream<<setw(5)<<"Target dimensions "<<d.target_dim<<endl;


                                        //outStream.clear();
                                        return  outStream;

}

Dataset::Dataset()
{

}
                                        Dataset::Dataset(Matrix  inputs, Matrix targets, double percentage)
                                        {

                                            //(this->inputs).getMatrixData()=inputs.getMatrixData();
                                            //(this->targets).getMatrixData()=targets.getMatrixData();

                                            vector<vector<double> > inputs_matrix_data;
                                            vector<vector<double> > targets_matrix_data;



                                            inputs_matrix_data=(inputs).getMatrixData();

                                            //cout<<inputs_matrix_data.size()<<"    "<<inputs_matrix_data[0].size();

                                                                targets_matrix_data=(targets).getMatrixData();

                                                                //this->targets.getMatrixData()=targets_matrix_data;
                                                              // this->inputs.getMatrixData()=inputs_matrix_data;

                                                                this->inputs.set_matrix_data(inputs_matrix_data);

                                                                //this->inputs.show();

                                                                this->targets.set_matrix_data(targets_matrix_data);

                                                               // inputs.show();


                                                              //  targets.show();



    no_of_samples=(inputs_matrix_data[0]).size();



    input_dim=(inputs_matrix_data).size();




    target_dim=(targets_matrix_data).size();

    size_t train_samples_number=getNoOfTrainSamples();


    size_t test_samples_number=getNoOfTestSamples();


                                    vector<vector<double> > inputs_matrix_train_data(inputs_matrix_data.size(),vector<double >(train_samples_number,0));

                                    for (int i = 0; i <inputs_matrix_data.size() ; ++i) {
                                        for (int j = 0; j < train_samples_number ; ++j) {

                                            inputs_matrix_train_data[i][j]=inputs_matrix_data[i][j];
                                        }
                                    }


    //train_inputs.getMatrixData()=inputs_matrix_train_data;  //Assigning
    this->train_inputs.set_matrix_data(inputs_matrix_train_data);


                            vector<vector<double> > targets_matrix_train_data(targets_matrix_data.size(),vector<double >(train_samples_number,0));
                            for (int i = 0; i <targets_matrix_data.size() ; ++i) {
                                for (int j = 0; j < train_samples_number ; ++j) {

                                    targets_matrix_train_data[i][j]=targets_matrix_data[i][j];
                                }
                            }

   // train_targets.getMatrixData()=targets_matrix_train_data;//Assigning
    this->train_targets.set_matrix_data(targets_matrix_train_data);


                                    vector<vector<double> > inputs_matrix_test_data(inputs_matrix_data.size(),vector<double >(test_samples_number,0));

                                    for (int l = 0; l <inputs_matrix_data.size() ; ++l) {
                                        for (int i = 0; i <test_samples_number ; ++i) {
                                            inputs_matrix_test_data[l][i]=inputs_matrix_data[l][i+train_samples_number];
                                        }
                                    }



                                    //test_inputs.getMatrixData()=inputs_matrix_test_data;//Assigning

                                    this->test_inputs.set_matrix_data(inputs_matrix_test_data);

                                    vector<vector<double> > targets_matrix_test_data(targets_matrix_data.size(),vector<double >(test_samples_number,0));

                                  //  for (int m = 0 ; m <test_samples_number ; ++m) {
                                  //      targets_matrix_test_data[targets_matrix_data.size()-1][m]=targets_matrix_data[targets_matrix_data.size()-1][m+train_samples_number];
                                 //   }


    for (int l = 0; l <targets_matrix_data.size() ; ++l) {
        for (int i = 0; i <test_samples_number ; ++i) {
            targets_matrix_test_data[l][i]=targets_matrix_data[l][i+train_samples_number];
        }
    }


    //test_targets.getMatrixData()=targets_matrix_test_data;

    this->test_targets.set_matrix_data(targets_matrix_test_data);
}


                                                    //  this function at first load data in to 2d vector and after that it returns the number of samples.

                                                    size_t Dataset::getNoOfSamples()
                                                    {
                                                        vector<vector<double> > inputs_matrix_data;
                                                        vector<vector<double> > targets_matrix_data;

                                                        inputs_matrix_data=inputs.getMatrixData();
                                                        targets_matrix_data=targets.getMatrixData();

                                                        no_of_samples=(inputs_matrix_data[0]).size();

                                                        return no_of_samples;
                                                    }

size_t Dataset::getNoOfTrainSamples()
{
    size_t no_of_train_samples;
    double per=percentage/100;
    double num=per*no_of_samples;
    no_of_train_samples=static_cast<size_t>(ceil(num));
    return no_of_train_samples;
}

                                size_t Dataset::getNoOfTestSamples()
                                {
                                    size_t no_of_test_samples;
                                    double per=(100-percentage)/100;
                                    double num=per*no_of_samples;
                                    no_of_test_samples=static_cast<size_t>(num);
                                    return no_of_test_samples;
                                }

                                Matrix  Dataset::getInputs()
                                {
                                    return inputs;
                                }

Matrix Dataset::getTargets()
{
    return  targets;
}

size_t Dataset::getInputDim()
{
    vector<vector<double> > inputs_matrix_data;

    inputs_matrix_data=inputs.getMatrixData();

    input_dim=(inputs_matrix_data).size();

    return input_dim;
}

                            size_t Dataset::getTargetDim()
                            {
                                vector<vector<double> > targets_matrix_data;

                                targets_matrix_data=targets.getMatrixData();

                                target_dim=(targets_matrix_data).size();

                                return target_dim;
                            }

Matrix Dataset::getTrainInputs()
{
    /*
    vector<vector<double> > inputs_matrix_train_data;

    vector<vector<double> > inputs_matrix_data;


    inputs_matrix_data=inputs.getMatrixData();

    for (int i = 0; i <inputs_matrix_data.size()-1 ; ++i) {
        for (int j = 0; j <getNoOfTrainSamples() ; ++j) {

            inputs_matrix_train_data[i][j]=inputs_matrix_data[i][j];
        }
    }

    train_inputs.getMatrixData()=inputs_matrix_train_data;
*/
    return train_inputs;
}

Matrix Dataset::getTrainTargets()
{
    /*
    vector<vector<double> > targets_matrix_train_data;

    vector<vector<double> > targets_matrix_data;
    
    targets_matrix_data=targets.getMatrixData();

    for (int i = 0; i <getNoOfTrainSamples() ; ++i) {
        targets_matrix_train_data[targets_matrix_data.size()-1][i]=targets_matrix_data[targets_matrix_data.size()-1][i];
    }

   // train_targets.getMatrixData()=targets_matrix_train_data;
    train_targets.set_matrix_data(targets_matrix_train_data);
*/
    return  train_targets;
}

Matrix Dataset::getTestInputs()
{
    /*
    vector<vector<double> > inputs_matrix_test_data;

    vector<vector<double> > inputs_matrix_data;


                            inputs_matrix_data=inputs.getMatrixData();

                            for (int i = 0; i <inputs_matrix_data.size()-1 ; ++i) {
                                for (int j = getNoOfTrainSamples(); j <(inputs_matrix_data[0]).size(); ++j) {

                                    inputs_matrix_test_data[i][j]=inputs_matrix_data[i][j];
                                }
                            }

    test_inputs.getMatrixData()=inputs_matrix_test_data;
*/
    return test_inputs;
}

Matrix Dataset::getTestTargets()
{
    /*
    vector<vector<double> > targets_matrix_test_data;

                        vector<vector<double> > targets_matrix_data;

                        targets_matrix_data=targets.getMatrixData();

                        for (int i = getNoOfTrainSamples(); i <(targets_matrix_data[0]).size() ; ++i) {
                            targets_matrix_test_data[targets_matrix_data.size()-1][i]=targets_matrix_data[targets_matrix_data.size()-1][i];
                        }

    test_targets.getMatrixData()=targets_matrix_test_data;
*/
    return  test_targets;
}

void Dataset::shuffle()
{

    //srand(unsigned(time(0)));


                                    //put both inputs and targets into a 2d vector step#1
                                    //cout<<endl<<"Dataset is shuffled . . .. "<<endl;

                                    vector<vector<double> > dataset;

                                    vector<vector<double> > inputs_matrix;
                                    inputs_matrix=inputs.getMatrixData();

                                    vector<vector<double> > targets_matrix;
                                    targets_matrix=targets.getMatrixData();



    for (int i = 0; i <input_dim ; ++i) {

        dataset.push_back(inputs_matrix[i]);
        }

    for (int j = 0; j <target_dim ; ++j) {
        dataset.push_back(targets_matrix[j]);
    }
////////////////////////////////////////////////Showing inputs and targets together   dataset
/*
for (int k = 0; k <dataset.size() ; ++k) {
        for (int i = 0; i < dataset[0].size(); ++i) {
            cout<<setw(5)<<dataset[k][i];
        }
        cout<<endl;
    }
                                    */
                                ///////////////////////////////////////////////////////////////////////////////////////////////

                                Matrix m;
                                Matrix m_transpose;
                                Matrix m_shuffle;
                                m.set_matrix_data(dataset);

                                // Show the matrix formation of a dataset
                                //m.show();

                                m_transpose=m.T();

                                //(m_transpose).show();

            srand(unsigned(time(0)));

            //cout<<endl<<"AAA";

            vector<vector<double> > d1=((m_transpose).getMatrixData());

            random_shuffle(d1.begin(), d1.end());
                // To obtain a time-based seed
            //    unsigned seed = 0;

                // Use of shuffle
                //random_shuffle(((m_transpose).getMatrixData()).begin() , ((m_transpose).getMatrixData()).end() , default_random_engine(seed));

               // cout<<endl<<"AAA";

//m_shuffle=m_transpose.T();
m_shuffle.set_matrix_data(d1);
Matrix m_tt=m_shuffle.T();
//cout<<endl<<"Dataset matrix after shuffling...."<<endl;
//m_tt.show();
dataset.clear();
dataset=m_tt.getMatrixData();

    for (int l = 0; l <inputs_matrix.size() ; ++l) {
        for (int i = 0; i <inputs_matrix[0].size() ; ++i) {
            inputs_matrix[l][i]=dataset[l][i];

        }
    }

                                                        inputs.set_matrix_data(inputs_matrix);

                                                                    //cout<<endl<<"The inputs after shuffling .. .. .. "<<endl;
                                                                   // inputs.show();

                                                        for (int l = 0; l <targets_matrix.size() ; ++l) {
                                                            for (int i = 0; i <targets_matrix[0].size() ; ++i) {
                                                                targets_matrix[l][i]=dataset[l+input_dim][i];

        }
    }

                                        targets.set_matrix_data(targets_matrix);

                                                    //cout<<endl<<"The targets after shuffling .. .. .. "<<endl;
                                                   // targets.show();

                                        vector<vector<double> > inputs_matrix_train(inputs_matrix.size(),vector<double>(getNoOfTrainSamples(),0));
                                        vector<vector<double> > targets_matrix_train(targets_matrix.size(),vector<double>(getNoOfTrainSamples(),0));
                                        //vector<vector<double> > inputs_matrix_train_data(inputs_matrix_data.size(),vector<double >(train_samples_number,0));
                                        vector<vector<double> > inputs_matrix_test(inputs_matrix.size(),vector<double>(getNoOfTestSamples(),0));
                                        vector<vector<double> > targets_matrix_test(targets_matrix.size(),vector<double>(getNoOfTestSamples(),0));

    for (int n = 0; n <input_dim ; ++n) {
        for (int i = 0; i <getNoOfTrainSamples() ; ++i) {
            inputs_matrix_train[n][i]=inputs_matrix[n][i];
        }
    }

    train_inputs.set_matrix_data(inputs_matrix_train);


                           // cout<<endl<<"The input train samples after shuffling .. .. .. "<<endl;
                            //train_inputs.show();


    for (int i1 = 0; i1 <target_dim ; ++i1) {
        for (int i = 0; i <getNoOfTrainSamples() ; ++i) {
            targets_matrix_train[i1][i]=targets_matrix[i1][i];
        }
    }

    train_targets.set_matrix_data(targets_matrix_train);


                    //cout<<endl<<"The target train samples after shuffling .. .. .. "<<endl;
                    //train_targets.show();



    for (int n = 0; n <input_dim ; ++n) {
        for (int i = 0; i <getNoOfTestSamples() ; ++i) {
            inputs_matrix_test[n][i]=inputs_matrix[n][i+getNoOfTrainSamples()];
        }
    }

test_inputs.set_matrix_data(inputs_matrix_test);

                           // cout<<endl<<"The input test samples after shuffling .. .. .. "<<endl;
                           // test_inputs.show();


    for (int i1 = 0; i1 <target_dim ; ++i1) {
        for (int i = 0; i <getNoOfTestSamples() ; ++i) {
            targets_matrix_test[i1][i]=targets_matrix[i1][i+getNoOfTrainSamples()];
        }
    }

    test_targets.set_matrix_data(targets_matrix_test);

                        //cout<<endl<<"The target test samples after shuffling .. .. .. "<<endl;
                        //test_targets.show();

}

void Dataset::show()
{
cout<<endl<<"Dataset :"<<endl;
cout<<setw(5)<<"No of samples: "<<no_of_samples<<endl;
cout<<setw(5)<<"Train samples: "<<getNoOfTrainSamples()<<endl;
cout<<setw(5)<<"Test  samples: "<<getNoOfTestSamples()<<endl;
cout<<setw(5)<<"Input dimensions : "<<input_dim<<endl;
cout<<setw(5)<<"Target dimensions "<<target_dim<<endl;
}
