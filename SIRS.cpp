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


void initialize(Point* points) {
    using namespace std;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,7);

    for (int i=0; i<N*N; i++) {
        points[i].curr_tau = distribution(generator);
    }

    //for (int i=0; i<N*N; i++) cout << points[i].curr_tau;
}

void vonneumann(Point* points) {
    for (int i=0; i<N*N; i++){
        if (i%N == 0) {
            points[i].left = points[i+N-1].curr_tau;
            points[i].right = points[i+1].curr_tau;
        }
        else if ((i+1)%N == 0) {
            points[i].left = points[i-1].curr_tau;
            points[i].right = points[i+1-N].curr_tau;
        }
        else {
            points[i].left = points[i-1].curr_tau;
            points[i].right = points[i+1].curr_tau;
        }
    }

    for (int i=0; i<N*N; i++) {
        if (i<N) {
            points[i].top = points[i+ (N-1)*N].curr_tau;
            points[i].bottom = points[i+N].curr_tau;
        }
        else if (i<N*N && i>=(N*N - N)) {
            points[i].top = points[i-N].curr_tau;
            points[i].bottom = points[i - (N-1)*N].curr_tau;
        }
        else {
            points[i].top = points[i-N].curr_tau;
            points[i].bottom = points[i+N].curr_tau;
        }
    }
}

void update(Point* points) {  //update happens in next_tau
    int no_infected;
    int a,b,c,d;
    for (int i=0; i<N*N; i++) {
        // counting number of infected neighbours
        no_infected = 0;
        a = points[i].left;
        b = points[i].top;
        c = points[i].right;
        d = points[i].bottom;
        if (a >=1 && a<=4) no_infected += 1;
        if (b >=1 && b<=4) no_infected += 1;
        if (c >=1 && c<=4) no_infected += 1;
        if (d >=1 && d<=4) no_infected += 1;
        //
    }
    for (int i; i<N*N; i++) {
        if (points[i].curr_tau == 0) {
            if (no_infected >= 2) points[i].next_tau = 1;
        }
        else if (points[i].curr_tau == tau_max) points[i].next_tau = 0;
        else points[i].next_tau = points[i].curr_tau + 1;

        //std::cout << points[i].next_tau << "\n";
    }
}

void reassign(Point* points) {  //assigns the next_tau values to curr_tau
    for (int i=0; i<N*N; i++) {
        points[i].curr_tau = points[i].next_tau;
    }
}


int main(){
    Point* points = new Point[N*N];
    initialize(points);
    vonneumann(points);

    std::ofstream outFile("SIRS_data.txt");

    int Total_steps = 10;
    for (int i=0; i<=Total_steps; i++) {
        update(points);
        // print
        for (int j=0; j<N*N; j++) {
            outFile << points[i].curr_tau << " ";
            //std::cout << points[i].next_tau << "\n";
        } outFile << "\n";
        //
        reassign(points);
        vonneumann(points);
    }
    outFile.close();
    return 0;
}
