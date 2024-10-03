#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>

const int N =100;                //number of cells in one direction
const int tau_max = 10; 
const int tau_l = 9;             // cell is infected when 0 < tau <= tau_l
const int infection_rate = 1.0;  //tunes how aggressive the infection spreads

struct Point  // this data structure contains the state of a cell
{
    /* data */
    int curr_tau, next_tau;       // current tau and tau for the next step
    int left, top, right, bottom; // stores the tau values around the cell
    int no_infected;              // number of infected cells in the neighbourhood
};


void initialize(Point* points) {
    using namespace std;
    //
    ifstream my_file("Initial_conditions_100*100center.txt"); // this file has initial conditions
    //
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,7);

    for (int i=0; i<N*N; i++) {
        my_file >> points[i].curr_tau;
        //points[i].curr_tau = distribution(generator);
    }
}

void vonneumann(Point* points) { // updates the left, right, top and bottom data for the cell
    for (int i=0; i<N*N; i++){   // vonneumann bondary condition used
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
    //
    using namespace std;
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    int a,b,c,d;
    for (int i=0; i<N*N; i++) {
        // counting number of infected neighbours
        points[i].no_infected = 0;
        a = points[i].left;
        b = points[i].top;
        c = points[i].right;
        d = points[i].bottom;
        if (a >=1 && a<=tau_l) points[i].no_infected += 1;
        if (b >=1 && b<=tau_l) points[i].no_infected += 1;
        if (c >=1 && c<=tau_l) points[i].no_infected += 1;
        if (d >=1 && d<=tau_l) points[i].no_infected += 1;
        //
    }
    for (int i=0; i<N*N; i++) {
        if (points[i].curr_tau == 0) {

            double probability = infection_rate*points[i].no_infected/4.0;
            if (distribution(generator) < probability) points[i].next_tau = 1;
            else points[i].next_tau = 0;
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

    std::ofstream outFile("SIRS_data.txt"); // this file stroes the results

    int Total_steps = 400; // no of evolutions
    for (int i=0; i<=Total_steps; i++) {
        update(points);
        // print
        for (int j=0; j<N*N; j++) {
            outFile << points[j].curr_tau << " ";
        } outFile << "\n";
        //
        reassign(points);
        vonneumann(points);
    }
    outFile.close();
    return 0;
    delete[] points;
}