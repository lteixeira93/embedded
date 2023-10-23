#include <iostream>
#include <vector>

using namespace std;

static int *applyAll(const vector <int> &arr_x, const vector <int> &arr_y) 
static void printAll(const int *const &aa_ret, int size_aa_ret); 

int main (void) 
{
	int *aa_ret {nullptr};
	vector <int> arr_x {1, 2, 3, 4, 5};
	vector <int> arr_y {10, 20, 30};

	aa_ret = applyAll(arr_x, arr_y);

	printAll(aa_ret, arr_x.size() * arr_y.size());

	delete [] aa_ret;
	aa_ret = nullptr;

	return 0;
}

static int *applyAll(const vector <int> &arr_x, const vector <int> &arr_y) 
{
	int *arr_res {nullptr}, pos{0};

	arr_res = new int[arr_x.size() * arr_y.size()];

	for (int i {0}; i < arr_x.size(); i++) 
	{
		for (int j {0}; j < arr_y.size(); j++) 
		{
			arr_res[pos] = (arr_y.at(i) * arr_x.at(j));
			pos++;
		}	
	}

	return arr_res;
}

static void printAll(const int *const &aa_ret, int size_aa_ret) 
{
	for (int i {0}; i < size_aa_ret; i++) {
		cout << *(aa_ret+i) << " " << endl;
	}
}
