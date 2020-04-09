//
// Created by Administrator on ۳۰/۰۳/۲۰۲۰.
//
#include <bits/stdc++.h>

#include<iostream>

#include <vector>

#include<fstream>

#include <sstream>

#include <string>

#include<algorithm>

#include <iomanip>

#include<cmath>

#include<array>
using namespace std;


#ifndef AP_HW3_MATRIX_H
#define AP_HW3_MATRIX_H

class Array
{
private:

    double *p;
public:

    int length;
    Array(int size = 0): length(size)
    {
        p=new double (length);
    }
    double & operator [](const int k)
    {
        return p[k];
    }
};


class Matrix
{
private:

    std::vector<std::vector<double> > data;

    std::array<size_t,2> size;

    Array*p;
public:

    ////////////////////////////////////////
   // vector<double> operator[](double n) ;

    Array& operator [](const int& i)
    {
        return p[i];
    }


//////////////////////////////////////////
    Matrix();

    Matrix(size_t , size_t);


    Matrix(const Matrix& mat);

    Matrix(std::vector<std::vector<double> > d);

    //Matrix();           default constructor

    //Unique pointer constructor

    std::array<size_t, 2> getSize();

    double det();

    Matrix inv();

    std::vector<std::vector<double > > getCofactor(std::vector<std::vector<double > > A, std::vector<std::vector<double > > temp, int p, int q, int n);


    std::vector<std::vector<double > > adjoint(std::vector<std::vector<double > >  A,std::vector<std::vector<double > >adj) ;

    std::vector<std::vector<double > > getMatrixData();

    Matrix T();

    void show();

    Matrix delCol(size_t i);

    Matrix col(size_t i);


    void save(const char*);

    void load(const char*);

    void delete_record();

    void set_matrix_data(std::vector<std::vector<double > >);

    bool is_file_exist(const char *fileName);


    Matrix operator+(const Matrix &b);  //         why const &??????

    Matrix operator-(const Matrix &b);

    Matrix operator*(const Matrix &b);

    Matrix operator*(double scalar);

};

#endif //AP_HW3_MATRIX_H
