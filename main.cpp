/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nsage
 *
 * Created on March 26, 2018, 10:52 AM
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * 
 */

// calculates mean from vector of floats
float mean(const vector<float>a) {
    int m = 0;
    vector<float>::const_iterator iter;
    
    for (iter=a.begin();iter!=a.end();++iter)
    {
        m += *iter;
    }
    return m/(float)a.size();
}

// calculates slope b from vector of floats
float findSlope(const vector<float>& x,
                const vector<float>& y,
                const float& mean_x,
                const float& mean_y) {
    
    if (x.size() != y.size()) {
        cout << "x.size(): " << x.size() << " \n";
        cout << "y.size(): " << y.size() << " \n";
        cout << "the data is not paired: stopping." << "\n";
        return 0.0;
    }
    else
    {
        float num = 0;
        float denom = 0;
        
        vector<float>::const_iterator iter_x;
        vector<float>::const_iterator iter_y;
        iter_y = y.begin();
    
        for (iter_x=x.begin();iter_x!=x.end();++iter_x)
        {
            num += ( (*iter_x-mean_x)*(*iter_y-mean_y) );
            denom += ( (*iter_x-mean_x)*(*iter_x-mean_x) );
            
            ++iter_y;
        }
        
        if (denom != 0) {
            return num/denom;
        }
        else {
            cout << "not a number." << "\n";
            return -1;
        }
    }
    
}

// calculates x-intercept from vector of floats
float findIntercept(const float& mean_x, const float& mean_y, const float& b) {
    return mean_y - b*mean_x;
}

// calculates the simple linear regression line
void regressionLine(const vector<float>& x, const vector<float>& y) {
    float mean_x = mean(x);
    float mean_y = mean(y);
    
    float b = findSlope(x,y,mean_x,mean_y);
    float a = findIntercept(mean_x,mean_y,b);
    cout << "y = " << a << " + " << b << "x" << "\n"; 
}

int main(int argc, char** argv) {
    
    vector<float> x = {0.0,1.0,2.0,3.0,4.0,5.0};
    vector<float> y = {0.0,-2.1,-4.9,-6.1,-8.0,-10.5};
    
    regressionLine(x,y);
    
    return 0;
}