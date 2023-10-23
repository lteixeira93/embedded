# What are Boost C++ libraries?
```
The Boost C++ libraries are a collection of open-source C++ libraries that provide support for tasks and functionalities commonly used in C++ development. The Boost libraries are highly respected among C++ developers and are widely used in many applications and software projects.

The Boost libraries are designed to be portable, well-documented, and easy to use. They are distributed under the Boost Software License, which allows them to be used for both open-source and commercial projects. The Boost libraries cover a wide range of topics, including utilities, algorithms, data structures, and many others.

sudo apt update && sudo apt install build-essential g++ python3-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev libc6-dbg gdb valgrind -y
```

# (S)ingle Responsability Principle
```
Each function deals only what is supposed to do
Ex: Persist data in storage should have a unique funtion dedicated for this.
```

# (O)pen-Closed Principle
```
System should be open to extensions by inheritance/template but not modification of existing code.
In OCP.cpp the struct ProductFilter is being modified each time a use case is required (Bad practice)
Ex: Create a template to deal all possible data
```

# (L)iskov Substitution Principle
```
Subtypes should be immeadiately substitutable for their base types.
If you have a function which takes a base class, any derived class should be
able to be substituted into the function
```

# (I)nterface Segregation Principle
```
Not implement too large interfaces, separate between functionalities
```

# (D)ependency Inversion Principle
```
High level models should not depend on low level modules, both should depend on abstractions
```
