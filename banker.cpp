#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
        int p;  //number of processes
        int r;  //number of resources

        ifstream file ("input.txt");
        if (!file.is_open()) {
                std::cout << "Unable to open file." << std::endl;
                exit(1);
        }

        string in;
        int num;

        getline(file, in);
        num = stoi(in, nullptr, 10);
        p = num;  //reads in number of processes and stores number

        getline(file, in);
        num = stoi(in, nullptr, 10);
        r = num;  //reads in number of resources and stores number

        int allocation[p][r];  //declares matrix for allocation
        int max[p][r];  //declares matrix for max
        int available[r];  //declares array for available resources
        int need[p][r];  //declares matrix for needed resources
        int correct[p];  //declares array used to display safe sequence of processes

        for (int i = 0; i < p; ++i) {  //fills allocation matrix with proper data
                for (int j = 0; j < r; ++j) {
                        getline(file, in);
                        num = stoi(in, nullptr, 10);
                        allocation[i][j] = num;
                }
                for (int k = 0; k < r; ++k) {  //fills max matrix with proper data
                        getline(file, in);
                        num = stoi(in, nullptr, 10);
                        max[i][k] = num;
                }
        }
        for (int l = 0; l < r; ++l) {  //fills available array with proper data
                getline(file, in);
                num = stoi(in, nullptr, 10);
                available[l] = num;
        }
        for (int m = 0; m < p; ++m) {  //calculates need matrix's proper data
                for (int n = 0; n < r; ++n) {
                        need[m][n] = max[m][n] - allocation[m][n];
                }
        }

        int finish[p];  //initializes array for checking safe sequence
        for (int o = 0; o < p; ++o) {
                finish[o] = 0;
        }

        int flag = 0;  //variable to track if safe or not
        int inc = 0;  //incrementer variable
        for (int q = 0; q < p; ++q) {
                for (int s = 0; s < p; ++s) {
                        if (finish[s] == 0) {
                                flag = 0;
                                for (int t = 0; t < r; ++t) {
                                        if (need[s][t] > available[t]) {
                                                flag = 1;
                                                break;
                                        }
                                }
                        if (flag == 0) {
                                correct[inc++] = s;
                                for (int u = 0; u < r; ++u) {
                                        available[u] += allocation[s][u];
                                        finish[s] = 1;
                                }
                        }
                        }
                }
        }
        std::cout << "The following sequence is a safe sequence: " << std::endl;
        for (int v = 0; v < p - 1; ++v) {
                std::cout << "P" << correct[v] << " then ";
        }
        std::cout << "P" << correct[p - 1] << "." << std::endl;
}
