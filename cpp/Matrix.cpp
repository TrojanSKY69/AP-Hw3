//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//

#include "Matrix.h"


Matrix::Matrix()
{
    p= new Array[data.size()];
    //vector<vector<double> > v(1,vector<double >(1,999));
    //data=v;
   //size[0]=1;
  // size[1]=1;

}

Matrix::Matrix(size_t a1 , size_t a2)
{
    p= new Array[a1];


    Matrix mat;
a1=size[0];
a2=size[1];

mat.size[0]=a1;
mat.size[1]=a2;

    for (int i = 0; i <data.size() ; ++i) {
        for (int j = 0; j <data[0].size() ; ++j) {
            mat.data[i][j]=0;
            //data[i][j]=0;
        }
    }

}



void Matrix::set_matrix_data(vector<vector<double > > d)
{
data=d;
}
vector<vector<double > > Matrix::getMatrixData()
{
    /*
    vector<vector<double > > Matrix_Data;

    for (int i = 0; i<(data).size() ; i++) {
        for (int j = 0; j<(data[0]).size() ; j++) {
            Matrix_Data[i][j]=data[i][j];
        }
    }
*/
    //return Matrix_Data;
    return data;
}

                            Matrix Matrix::operator*(double scalar)
                            {
                                vector<vector<double> > vec(data.size(), vector<double> (data[0].size(), 1));
                                Matrix m(vec);

                                for (int i = 0; i < data.size(); i++)
                                {
                                    for (int j = 0; j < data[0].size(); j++)
                                    {
                                        m.data[i][j] = data[i][j] * scalar;
                                    }
                                }
                                return m;

                            }

Matrix Matrix::operator+(const Matrix &b){

    vector<vector<double> > vec(data.size(), vector<double> (data[0].size(), 1));
    Matrix m(vec);

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            m.data[i][j] = data[i][j] + b.data[i][j];
        }
    }
    return m;
}
/*
vector<double > Matrix::operator[](double n)
{

    return data[static_cast<int>(n)];
}
*/
                        Matrix Matrix::operator-(const Matrix &b){

                            vector<vector<double> > vec(data.size(), vector<double> (data[0].size(), 1));
                            Matrix m(vec);

                            for (int i = 0; i < data.size(); i++)
                            {
                                for (int j = 0; j < data[0].size(); j++)
                                {
                                    m.data[i][j] = data[i][j] - b.data[i][j];
                                }
                            }
                            return m;
                        }

            Matrix Matrix::operator*(const Matrix &b){
                // if((data[0].size())==((b.data).size()))
                // {
                vector<vector<double> > vec(data.size(), vector<double> ((b.data[0]).size(), 0));
                Matrix m(vec);

                for (int i = 0; i < (m.data).size(); i++) //OK  final ok
                {
                    for (int j = 0; j < (b.data[0]).size(); j++) //
                    {
                        m.data[i][j] = 0;

                        for (int k = 0; k < (b.data).size(); k++) //
                            m.data[i][j] += data[i][k] *  b.data[k][j];
                    }
                }
                return m;

            }





// Function to get adjoint of A[N][N] in adj[N][N].
vector<vector<double > > Matrix::adjoint(vector<vector<double > > A,vector<vector<double > >adj)
{

    double sign = 1;
    vector<vector<double> > vec1(data.size()-1, vector<double> (data[0].size()-1, 1));

    vector<vector<double > >  temp(vec1);

    vector<vector<double> > vec(temp.size(), vector<double> (temp[0].size(), 1));

    Matrix mat1(vec);




    vector<vector<double> > vec4(data.size(), vector<double> (data[0].size(), 1));

    vector<vector<double > > adj_transpose(vec4);

    for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<A.size(); j++)
        {
            // Get cofactor of A[i][j]

            temp=getCofactor(A, temp, i, j, A.size());

            for (int m = 0; m < temp.size() ; m++)
            {
                for (int n = 0; n < temp[0].size(); n++)
                {

                    mat1.data[m][n]=temp[m][n];
                }

            }

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix

            adj[i][j]=(sign)*(mat1.det())*(A[i][j]);

        }
    }


                                //this part is for transposing

                                for (int i = 0; i < adj.size(); i++)
                                {
                                    for (int j = 0; j < adj.size(); j++)
                                    {
                                        adj_transpose[i][j]=adj[j][i];
                                    }
                                }

                                return adj_transpose;

}



Matrix Matrix::inv()
{
// Find determinant of A[][]

    vector<vector<double> > vec(data.size(), vector<double> (data[0].size(), 10));
    vector<vector<double> > VEC(data.size(), vector<double> (data[0].size(), 0));// for returning zero

    Matrix control(VEC);

    Matrix mat(vec);   //mat is the matrix that we want to get its inv()


    Matrix inverse(vec);//The inverse of mat


    for (int i = 0; i < data.size() ; i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {

            mat.data[i][j]=data[i][j];
        }

    }

    double det=mat.det();

    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        //return control;                                           when it is not commented it falls to not showing the inverse

    }
    else
    {

        // Find adjoint


                                        vector<vector<double> > vec2(data.size(), vector<double> (data[0].size(), 0));

                                        vector<vector<double> > adj(vec2);

                                        vector<vector<double> > adj1(vec2);

                                        adj1=adjoint(mat.data, adj);


                                        // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
                                        for (int i=0; i<(mat.data).size(); i++)

                                        {
                                            for (int j=0; j<(mat.data).size(); j++)

                                            {
                                                inverse.data[i][j] = adj1[i][j]/det;
                                            }
                                        }

        return inverse;

    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//this part works correctly
vector<vector<double > > Matrix:: getCofactor(vector<vector<double > > A, vector<vector<double > > temp, int p, int q, int n) //it gives cofactor of A[p][q] and store it in temp
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
                                for (int col = 0; col < n; col++)
                                {
                                    //  Copying into temporary matrix only those element
                                    //  which are not in given row and column
                                    if (row != p && col != q)
                                    {
                                        temp[i][j++] = A[row][col];

                                        // Row is filled, so increase row index and
                                        // reset col index
                                        if (j == n - 1)
                                        {
                                            j = 0;
                    i++;
                }
            }
        }

    }

    return temp;
}

Matrix::Matrix(const Matrix& mat) //:Matrix(mat.data,mat.size)          //Copy constructor
{
    data=mat.data;
    p= new Array[data.size()];
}




Matrix::Matrix(vector<vector<double> > d )
{
    data=d;
    p= new Array[data.size()];
}

///show the matrix
void Matrix::show()
{
    cout<<endl<<"Your matrix is :"<<endl<<endl;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[0].size() ; j++)
        {

            cout<<setw(20)<<data[i][j];
        }

        cout<<endl;
    }
}
////  The function for giving the size of matrix
array<size_t, 2> Matrix::getSize()
{

    array<size_t,2> MyArray={data.size(),data[0].size()};

    return MyArray;

}

Matrix Matrix::col(size_t i)
{

    //we should create vector with a same row size as a  data row size  because we want a column

    vector<vector<double>> vec(data.size(), vector<double> (1, 0));

    Matrix m(vec);

    for (int k = 0 ; k < data.size() ; k++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            if(j==i)
            {
                //(m.data[k]).push_back(data[k][j]);
                m.data[k][0]=data[k][j];
            }

        }

    }

    return m;

}


// function for transposing matrix
Matrix Matrix::T()
{

    //creating the 2d vector like   data    and initialize it with zero

                                    vector<vector<double>> vec(data[0].size(), vector<double> (data.size(), 0));
                                    Matrix m(vec);

                                    for (int i = 0; i < data[0].size() ; i++)
                                    {
                                        for (int j = 0; j < data.size() ; j++)
                                        {
                                            //m.data[j%4][i]=data[i][j];
                                            m.data[i][j]=data[j][i];
                                        }
                                    }

    return m;

}


Matrix Matrix::delCol(size_t i)
{

    //creating the 2d vector like   data    and initialize it with zero
    vector<vector<double>> vec(data.size(), vector<double> (data[0].size(), 10));

    Matrix m(vec);

    //this loop erase the column i from original  object a
    for (int k = 0; k < data.size() ; k++)
    {
        for (int j = 0; j < data[k].size() ; j++)
        {

            if(j==i)
            {

                (m.data[k]).erase(m.data[k].begin()+i);
                //remove(m.data[k][j]);
                //Using vector iterator [vec.begin()+position] for erasing the original object
                data[k].erase(data[k].begin()+i);

            }
            m.data[k][j]=data[k][j];
        }
    }

    return	m;
}

void Matrix::save(const char* filename)
{
bool exsitence=is_file_exist(filename);

if(exsitence==1)
{
    delete_record();
}


// file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open(filename, ios::out | ios::app);

                            // Read the input
                            for (int i = 0; i < data.size(); i++) {
                                for (int j = 0; j < data[0].size() ; j++)
                                {
                                    fout<<data[i][j]<<", ";
                                }

                                fout<<endl;
                            }
}



bool Matrix:: is_file_exist(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}

void Matrix::load(const char* filename)
{
    data.clear();

    ifstream apfile(filename);

    string line="";


    while(getline(apfile,line))
    {
        string line_value;
        vector<double> line_values;
        vector<string >stream;

                        stringstream s(line);
                        //string m;

                        while(getline(s, line_value, ','))

                        {
                            stringstream ss(line_value);

                            double val;

                            ss >> val;
                            line_values.push_back(val);
                            //stream.push_back(line_value);


                        }
        line_values.pop_back();

        data.push_back(line_values);

    }

    apfile.close();

     //delete_record();

}


void Matrix::delete_record()
{
    remove("Matrix_Resotre_File.csv");

}




double Matrix::det()
{
    int n=data.size();//

                    vector<vector<double>> d(data.size(), vector<double> (data[0].size(), 10));  //why should we alwyas give it the initial value
                    //vector<vector<double > > d;

                    for (int i = 0; i < data.size(); i++)
                    {
                        for (int j = 0; j < data[0].size() ; j++)
                        {
                            d[i][j]=data[i][j];
                        }
                    }


    double num1,num2,det = 1,index,total = 1; // Initialize result

    // temporary array for storing row
    //double temp[n + 1];
    double temp[n+1];
    //loop for traversing the diagonal elements
    for(int i = 0; i < n; i++)
    {
                        index = i; // initialize the index

                        //finding the index which has non zero value
                        while(d[index][i] == 0 && index < n) {
                            index++;

                        }
                        if(index == n) // if there is non zero element
                        {
                            // the determinat of matrix as zero
                            continue;

                        }
                        if(index != i)
        {
                                                //loop for swaping the diagonal element row and index row
                                                for(int j = 0; j < n; j++)
                                                {
                                                    swap(d[index][j],d[i][j]);
                                                }
                                                //determinant sign changes when we shift rows
                                                //go through determinant properties
                                                det = det*pow(-1,index-i);
                                            }

                                            //storing the values of diagonal row elements
                                            for(int j = 0; j < n; j++)
                                            {
                                                temp[j] = d[i][j];

                                            }
        //traversing every row below the diagonal element
        for(int j = i+1; j < n; j++)
        {
            num1 = temp[i]; //value of diagonal element
            num2 = d[j][i]; //value of next row element

            //traversing every column of row
            // and multiplying to every row
            for(int k = 0; k < n; k++)
            {
                //multiplying to make the diagonal
                // element and next row element equal
                d[j][k] = (num1 * d[j][k]) - (num2 * temp[k]);

            }
            total = total * num1; // Det(kA)=kDet(A);
        }

    }

    //mulitplying the diagonal elements to get determinant
    for(int i = 0; i < n; i++)
    {
        det = det * d[i][i];

    }
    // cout<<endl<<(det/total)<<endl;		This Part is for debugging
    return (det/total); //Det(kA)/k=Det(A);

}

