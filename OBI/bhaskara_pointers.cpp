#include<iostream>
#include<cmath>
 
using namespace std;

// Calculate and print the quadratic roots of a given equation
void get_quadratic_roots(float a, float b, float delta, int n_roots, float *root1, float *root2){
    float r1 = (-b + sqrt(delta)) / (2*a);
    float r2 = (-b - sqrt(delta)) / (2*a);

    if (n_roots == 0) *root1 = r1;

    *root1 = r1;
    *root2 = r2;
}

// Calculate the number of roots of a quadratic equation and print a message
void get_num_roots(float delta, int *n_roots){
    *n_roots = ((delta >= 1) - (delta < 0));
}

// Calculates the value of delta and calls the function to calculate the roots
void get_delta(float a, float b, float c, float *delta){
    *delta = (b*b) - (4*a*c);
}

int main(){
	int n_roots = 0;
    float a, b, c, delta;
    float root1, root2;
    cin >> a >> b >> c;

    get_delta(a, b, c, &delta);
    get_num_roots(delta, &n_roots);
	
    // If there are no roots, exit the program
    if (n_roots == -1) {
        cout << "The result has no roots\n";
        return 0;
    }

    get_quadratic_roots(a, b, delta, n_roots, &root1, &root2);

    cout << "The root(s) is/are:\n";
    cout << root1 << endl;
    cout << root2 << endl;
    return 0;
}