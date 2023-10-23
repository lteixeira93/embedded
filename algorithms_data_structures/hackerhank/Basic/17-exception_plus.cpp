#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class CustomExcept : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "n and p should be non-negative";
    }
};

class Calculator : public CustomExcept
{
public: 
    int power(int n, int p) 
    {
        if (n < 0 || p < 0)
        {
            throw CustomExcept();
        }
        else {
            return pow(n,p);
        }
    }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;

    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}