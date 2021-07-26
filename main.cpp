#include <iostream>
#include <vector>
#include <cmath> // double pow(double base, double exponent), double sqrt(double x)
#include "polynominal.hpp"

const double pi = 3.141592653589793;
using namespace std;

vector<double> getCoefs(const unsigned int);
unsigned int factorial(const unsigned int);

int main()
{
    polynominal *pdf = new polynominal;
    int num = 1;
    cout << "Input how many terms to approximate. When input 0, loop ends. : ";
    cin >> num;
    pdf->setCoefficients(getCoefs(num));
    cout << "Probability density function which is approximated with taylor series." << endl;
    pdf->printPolynominal();
    cout << endl;

    double z_score = 0;
    while(true)
    {
        cout<< "Input z-score(Loop ends when -1 is inputed.) : ";
        cin >> z_score;
        if(z_score == -1)
        {
            break;
        }
        double result = pdf->getDefiniteIntegral(0,z_score) / sqrt(2*pi);
        cout << "P(0<Z<z-score) = " << result << endl;
    }

	delete pdf;
    return 0;
}

vector<double> getCoefs(const unsigned int num) // get coefficients of taylor series of e^(-x^2/2)
{
    unsigned int goal_degree = (num-1) * 2;
    vector<double> coefs;

    for(unsigned int degree = 0 ; degree <= goal_degree ; degree++)
    {
        if(degree % 2 == 1)
        {
            coefs.push_back(0);
            continue;
        }
        unsigned int n = degree / 2;
        double a = pow(-1.0, static_cast<double>(n));
        double b = pow(2.0, static_cast<double>(n));
        double c = factorial(n);
        
        coefs.push_back(a/(b*c));
    }

    return coefs;
}

unsigned int factorial(const unsigned int num)
{
    unsigned int result = 1;
    for(unsigned int count=1 ; count <= num ; count++)
    {
        result *= count;
    }
    return result;
}
