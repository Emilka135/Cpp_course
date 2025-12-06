#include <stdio.h>
#include <iostream>


/* ЧЁ П

*/
 


// class Animal {
//     public:
//         Animal() = default;
//     void walk() {
//         std::cout<<"Animal walk\n";
//     }
//     void fly();
//         std::cout<<"Animal fly\n";
//     void eat();
//         std::cout<<"Animal eat\n";

// }

class Animal {
    public:
       Animal() = default;
    virtual void walk() = 0; // &Animal::walk() = nullptr;
    virtual void fly() = 0;
    virtual void eat() = 0;
    virtual ~Animal();
};




class Cat: public Animal { //наследует от Animal
    public:
    Cat() = default;
    // void walk() {
    //     std::cout<<"Cat walk\n";
    // }
    void wall() owerride {
        std::cout<<"Cat walk\n";
    }
    void fly() owerride final {throw srd::logic_errir("");} // "final" у следующих наследников нельзя вызывать этот метод
    void eat() owerride {
        std::cout<<"Cat eats"
    }



};

class kitten: public Cat { //наследует от Cat
    public:
        kitten() = default;
    
};

kitten Jerry;
Jerry.Cat::walk();
Cat cat;
cat.walk();



