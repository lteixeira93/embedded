/*
The mathematical term symmetric difference (△ or ⊕) of two sets is the set of elements which are in either of the two sets but not in both. 
For example, for sets A = {1, 2, 3} and B = {2, 3, 4}, A △ B = {1, 4}.

Symmetric difference is a binary operation, which means it operates on only two elements. 
So to evaluate an expression involving symmetric differences among three elements (A △ B △ C), you must complete one operation at a time. 
Thus, for sets A and B above, and C = {2, 3}, A △ B △ C = (A △ B) △ C = {1, 4} △ {2, 3} = {1, 2, 3, 4}.
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 

#define V_NUM 3

using namespace std;

void print_2d_vector(vector <vector<int>> const &v);
void print_vector(vector <int> const &v);
void initialize_vectors(void);

void find_symmetric_diff(vector <vector<int>> const &v_set) {
    vector <int> v_merge;

    v_merge.reserve(v_set.size());

    for (size_t i = 0; i < V_NUM; i++) {
        v_merge.insert(v_merge.end(), v_set.at(i).begin(), v_set.at(i).end());
        sort(v_merge.begin(), v_merge.end());
        
        for (int i = v_merge.size() - 1; i > 0;) {
            const int n = v_merge[i];
            if (v_merge[i - 1] == n) {
                while (v_merge[i] == n) {
                    v_merge.erase(v_merge.begin() + i--);
                }
            }
            else {
                i--;
            }
        }
    }
    
    cout << "The symmetric difference is: " << endl;
    print_vector(v_merge);
}

int main(void) {
    /* code */    
    
    initialize_vectors();    

    return 0;
}

void print_2d_vector(vector <vector<int>> &v) {
    cout << "Vectors set: " << endl;
    for (const auto &r : v) {
        cout << '{';

        for (const auto &s : r) {
            cout << ' ' << s << ' ';
        }

        cout << '}' << endl;
    }
}

void print_vector(vector <int> const &v) {
    cout << '{';
    for (const auto &r : v) {        
        cout << ' ' << r << ' ';        
    }
    cout << '}' << endl;
}

void initialize_vectors(void) {
    srand(time(NULL));

    int v_size{0}, v_random_size{0};
    vector <int> v_random{0}; 
    vector <vector <int>> v_set{0};    

    v_random.clear(); 

    for (size_t i = 0; i < V_NUM; i++) {
        v_random_size = (1 + rand() % 10);

        for (size_t j = 0; j < v_random_size; j++) {
            v_random.push_back(rand() % 10);            
        }      
        v_set.push_back(v_random);
        v_random.clear();  
    }

    /* Sorting, removing duplicates and printing */
    for (size_t k = 0; k < V_NUM; k++) {
        sort(v_set.at(k).begin(), v_set.at(k).end());
        v_set.at(k).erase(unique(v_set.at(k).begin(), v_set.at(k).end()), v_set.at(k).end());
    }    

    print_2d_vector(v_set);    

    find_symmetric_diff(v_set);    
}

