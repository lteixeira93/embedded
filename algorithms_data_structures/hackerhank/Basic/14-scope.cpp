#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

    Difference();

	Difference(vector <int> e) : 
    elements {e}
    {}

    void computeDifference(void)
    {
        this->maximumDifference = 0;

        // 1 2 5
        for (int i = 0; i < elements.size(); i++)
        {
            for (int j {i+1}; j < elements.size(); j++)
            {
                if(abs(elements.at(i) - elements.at(j)) > this->maximumDifference)
                {
                    this->maximumDifference = abs(elements.at(i) - elements.at(j));
                }
            }
        }
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}