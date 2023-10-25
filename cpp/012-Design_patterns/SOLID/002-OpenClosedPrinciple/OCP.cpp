//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <boost/lexical_cast.hpp>
//
//using namespace std;
//using namespace boost;
//
//enum class Color { red, green, blue };
//enum class Size { small, medium, large };
//
//struct Product
//{
//    string name;
//    Color color;
//    Size size;
//};
//
//struct ProductFilter
//{
//    vector<Product*> byColor(vector<Product*> items, Color color)
//    {
//        vector<Product*> result;
//        for(auto& i: items)
//            if (i->color == color)
//                result.push_back(i);
//        return result;
//    }
//
//    // Starting bad practice...
//    // Filter by size
//    vector<Product*> bySize(vector<Product*> items, Size size)
//    {
//        vector<Product*> result;
//        for(auto& i: items)
//            if (i->size == size)
//                result.push_back(i);
//        return result;
//    }
//    // Filter by color and size...
//    vector<Product*> byColorAndSize(vector<Product*> items, Color color, Size size)
//    {
//        vector<Product*> result;
//        for(auto& i: items)
//            if (i->color == color && i->size == size)
//                result.push_back(i);
//        return result;
//    }
//
//    // ...
//};
//
//template<typename T>
//struct Specification
//{
//    virtual bool isSatisfied(T* item) = 0;
//};
//
//template<class T>
//struct Filter
//{
//    virtual vector<T*> filter(vector<T*> items,
//                              Specification<T>& spec) = 0;
//};
//
//struct BetterFilter : Filter<Product>
//{
//    virtual vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override
//    {
//        vector<Product*> result;
//
//        for(auto& item : items)
//            if(spec.isSatisfied(item))
//                result.push_back(item);
//        return result;
//    }
//};
//
//struct ColorSpecification : Specification<Product>
//{
//    Color color;
//    ColorSpecification(Color color) : color {color} {};
//    bool isSatisfied(Product* item) override
//    {
//        return item->color == color;
//    }
//
//};
//
//
//int main(void)
//{
//    Product apple {"Apple", Color::green, Size::small};
//    Product tree {"Tree", Color::green, Size::medium};
//    Product house {"House", Color::blue, Size::large};
//
//    vector<Product*> items { &apple, &tree, &house };
//
//    // ProductFilter pf;
//    // auto green_things = pf.byColor(items, Color::green);
//
//    // for(auto& item : green_things)
//    //     cout << item->name << " is green\n";
//
//    BetterFilter bf;
//    ColorSpecification green { Color::green };
//    for(auto& item : bf.filter(items, green))
//        cout << item->name << " is green\n";
//
//    return 0;
//}
