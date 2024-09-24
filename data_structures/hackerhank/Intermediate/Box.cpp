#include<iostream>
#include<ostream>

using namespace std;

class Box
{
public:
	/* Constructors, copy ctor and destructors */
	Box();
	Box(long long unsigned int l, long long unsigned int b, long long unsigned int h);
	Box(const Box& source);
	~Box();

	/* Overloaded operators */
	bool operator<(const Box& rhs);
	friend std::ostream &operator<<(std::ostream &os, const Box& rhs);

	/* Member methods */
	long long unsigned int getLength();
	long long unsigned int getBreadth();
	long long unsigned int getHeight();
	long long unsigned int CalculateVolume();
private:
	long long unsigned int m_l;
	long long unsigned int m_b;
	long long unsigned int m_h;
};

Box::Box()
	: m_l {0}, m_b {0}, m_h {0}
{}

Box::Box(long long unsigned int l, long long unsigned int b, long long unsigned int h)
	: m_l{ l }, m_b{ b }, m_h{ h }
{}

Box::Box(const Box& source)
{
	this->m_l = source.m_l;
	this->m_b = source.m_b;
	this->m_h = source.m_h;
}

Box::~Box()
{}

bool Box::operator<(const Box& rhs)
{
	if ((this->m_l < rhs.m_l) || ((this->m_b < rhs.m_b) && (this->m_l == rhs.m_l)) || ((this->m_h < rhs.m_h) && (this->m_b == rhs.m_b) && (this->m_l == rhs.m_l)))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream &os, const Box& rhs)
{	
	os << rhs.m_l << " " << rhs.m_b << " " << rhs.m_h;

	return os;
}

long long unsigned int Box::getLength()
{
	return this->m_l;
}

long long unsigned int Box::getBreadth()
{
	return this->m_b;
}

long long unsigned int Box::getHeight()
{
	return this->m_h;
}

long long unsigned int Box::CalculateVolume()
{
	return getLength() * getBreadth() * getHeight();
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}