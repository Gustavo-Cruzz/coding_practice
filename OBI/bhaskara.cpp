#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// Calculate and print the quadratic roots of a given equation
vector<float> get_quadratic_roots(float a, float b, float delta, int n_roots){
    float r1 = (-b + sqrt(delta)) / (2*a);
    float r2 = (-b - sqrt(delta)) / (2*a);

    if (n_roots == 0) return {r1};

    return {r1, r2};
}

// Calculate the number of roots of a quadratic equation and print a message
int get_num_roots(float delta){
    switch ((delta >= 1) - (delta < 0)) {
        case 1:
            return 1;
        case 0:
            return 0;
    }
    return -1;
}

// Calculates the value of delta and calls the function to calculate the roots
float get_delta(float a, float b, float c){
    return (b*b) - (4*a*c);
}

int main(){
    float a, b, c;
    cin >> a >> b >> c;

    float delta = get_delta(a, b, c);
    int n_roots = get_num_roots(delta);

    // If there are no roots, exit the program
    if (n_roots == -1) {
        cout << "The result has no roots\n";
        return 0;
    }

    auto roots = get_quadratic_roots(a, b, delta, n_roots);

    cout << "The root(s) is/are:\n";
    for (auto i: roots){
        cout << i << endl;
    }
    return 0;
}