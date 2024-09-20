#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>

const int N = 10; //number of cells in one direction
const int tau_max = 7;

struct Point
{
    /* data */
    int curr_tau, next_tau;
    int left, top, right, bottom;
};


void initialize(int* points) {
    using namespace std;
    default_random_engine generator;
    uniform_real_distribution<int> distribution(1,7);

    for (int i=0; i<N*N; i++) {
        points[i].curr_tau = distribution(generator);
    }
}

int i(int a, int b) {
    return a*N + b;
}

void vonneumann(Point* points) {
    for (int i=0; i<N*N; i++){
        if (i%N == 0) {
            points[i].left = points[i+N-1].curr_tau;
        }
        else points[i].left = points[i-1].curr_tau;

        if (i<N) {
            points[i].top = points[i + (N-1)*N].curr_tau;
        }
        else points[i].top = points[i-N].curr_tau;

        if ((i+1)%N == 0) {
            points[i].right = points[i+1-N].curr_tau;
        }
        else points[i].right = points[i+1].curr_tau;
        
        if (i<N*N && i>=(N*N - N)) {
            points[i].bottom = points[i - (N-1)*N].curr_tau;
        }
        else points[i].bottom = points[i-N].curr_tau
    }
}


int main(){
    Point* points = new Point[N];
    initialize(points);
}
