#pragma once

#include <iostream>
#include <vector>
#include <cmath> // double pow(double base, double exponent)
#include <iomanip>

using namespace std;

class polynominal{
  private:
    vector<double> coefficients;

  public:
    void setCoefficient(const int degree, const double coefficient)
    {
        if(coefficients.size() < degree+1)
        {
            coefficients.resize(degree+1);
            coefficients.at(degree) = coefficient;
        }
        else
        {
            coefficients.at(degree) = coefficient;
        }
    }

    void setCoefficients(const vector<double> original_coefficients)
    {
        coefficients.clear();
        for(auto x : original_coefficients)
        {
            coefficients.push_back(x);
        }
    }

    double getValue(const double x)
    {
        double result = 0;
        for(int degree = 0 ; degree < coefficients.size() ; degree++)
        {
            result += coefficients.at(degree) * pow(x, static_cast<double>(degree));
        }
        return result;
    }


    polynominal* getDerivative()
    {
        polynominal *derivative = new polynominal;
        for(int degree = 0 ; degree < coefficients.size()-1 ; degree++)
        {
            derivative->setCoefficient(degree, coefficients.at(degree+1)*(degree+1));
        }
        return derivative;
    }

    polynominal* getIndefiniteIntegral()
    {
        // constatnt of integral will be 0
        polynominal *indefinite_integral = new polynominal;
        indefinite_integral->setCoefficient(0, 0);
        for(int degree = 0 ; degree < coefficients.size() ; degree++)
        {
            indefinite_integral->setCoefficient(degree+1, coefficients.at(degree)/(degree+1));
        }
        return indefinite_integral;
    }

    double getDefiniteIntegral(const double from, const double to) // F(to) - F(from)
    {
        polynominal *indefinite_integral = getIndefiniteIntegral();
        double F_from = indefinite_integral->getValue(from);
        double F_to = indefinite_integral->getValue(to);
        double result = F_to - F_from;

        delete indefinite_integral;
        return result;
    }
    // TO DO, TO MODIFY : Because I don't know what are 위끝 and 아래끝 in english, I just write them as to, from. Modify it to proper term!


    void printCoefficients()
    {
        for(auto x : coefficients)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    void printPolynominal()
    {
        int precision = 30;
        for(int degree=0 ; degree < coefficients.size() ; degree++)
        {
            if(degree == 0)
            {
                cout << setprecision(precision) << showpoint << fixed;
                cout << coefficients.at(degree);
            }
            else
            {
                if(coefficients.at(degree) == -1)
                {
                    cout << setprecision(precision) << showpoint<< fixed;
                    cout << " - " << "x^" << degree;
                }
                else if(coefficients.at(degree) == 1)
                {
                    cout << " + " << "x^" << degree;
                }
                else if(coefficients.at(degree) == 0)
                {
                    continue;
                }
                else if(coefficients.at(degree) < 0 && coefficients.at(degree) != -1)
                {
                    cout << setprecision(precision) << showpoint<< fixed;
                    cout << " - " << (-1)*coefficients.at(degree) << "x^" << degree;
                }
                else if (coefficients.at(degree) > 0 && coefficients.at(degree) != 1)
                {
                    cout << setprecision(precision) << showpoint<< fixed;
                    cout << " + " << coefficients.at(degree) << "x^" << degree;
                }
            }
        }
        cout << endl;
    }
};

