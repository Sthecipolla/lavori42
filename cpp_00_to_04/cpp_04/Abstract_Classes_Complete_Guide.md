# Abstract Classes in C++ - Complete Guide

## 📖 **Definition**
An **abstract class** is a class that cannot be instantiated directly but serves as a blueprint for derived classes.

---

## 🔧 **How to Create Abstract Classes**

### **Method 1: Pure Virtual Functions**
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
    virtual void eat() const = 0;        // Another pure virtual
    virtual ~Animal() {}                 // Virtual destructor (not pure)
};
```

### **Method 2: Pure Virtual Destructor**
```cpp
class Animal {
public:
    virtual ~Animal() = 0;  // Pure virtual destructor
    virtual void makeSound() const;
};

// MUST provide implementation in .cpp file:
Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}
```

### **Method 3: Mix of Pure and Regular Virtual**
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;     // Pure virtual (abstract)
    virtual void sleep() const {            // Regular virtual (concrete)
        std::cout << "Animal sleeping" << std::endl;
    }
    virtual ~Animal() {}
};
```

---

## ⚡ **Key Rules**

1. **One Pure Virtual = Entire Class Abstract**
   - Even ONE `= 0` function makes the whole class abstract

2. **Pure Virtual Destructor Needs Implementation**
   ```cpp
   virtual ~Animal() = 0;  // Declaration
   Animal::~Animal() {}    // Implementation still required!
   ```

3. **Derived Classes Must Implement ALL Pure Virtuals**
   ```cpp
   class Dog : public Animal {
   public:
       void makeSound() const override { std::cout << "Woof!"; }  // REQUIRED
       void eat() const override { std::cout << "Eating bones"; } // REQUIRED
   };
   ```

4. **Can Have Non-Virtual Members**
   ```cpp
   class Animal {
   protected:
       std::string name;  // Regular member
   public:
       void setName(const std::string& n) { name = n; }  // Regular method
       virtual void makeSound() const = 0;               // Pure virtual
   };
   ```

---

## ✅ **What You CAN Do with Abstract Classes**

### **1. Create Pointers/References**
```cpp
Animal* ptr;           // ✅ OK
Animal& ref = dog;     // ✅ OK  
Animal* array[10];     // ✅ OK
std::vector<Animal*>   // ✅ OK
```

### **2. Point to Derived Objects**
```cpp
Animal* animals[3];
animals[0] = new Dog();     // ✅ OK
animals[1] = new Cat();     // ✅ OK
animals[2] = new Bird();    // ✅ OK
```

### **3. Use Polymorphism**
```cpp
void playWithAnimal(Animal* animal) {  // ✅ OK
    animal->makeSound();  // Calls correct derived implementation
}
```

### **4. Inherit from Abstract Classes**
```cpp
class Dog : public Animal {  // ✅ OK
    void makeSound() const override { std::cout << "Woof!"; }
};
```

---

## ❌ **What You CANNOT Do with Abstract Classes**

### **1. Direct Instantiation**
```cpp
Animal* animal = new Animal();     // ❌ Compiler Error!
Animal obj;                        // ❌ Compiler Error!
Animal array[5];                   // ❌ Compiler Error!
```

### **2. Incomplete Derived Classes**
```cpp
class Dog : public Animal {
    // Missing makeSound() implementation
    // Missing eat() implementation  
};
Dog myDog;  // ❌ Compiler Error! Dog is also abstract
```

---

## 🎯 **Common Patterns**

### **Interface Pattern**
```cpp
class IDrawable {
public:
    virtual void draw() const = 0;
    virtual void resize(int width, int height) = 0;
    virtual ~IDrawable() = 0;
};
```

### **Template Method Pattern**
```cpp
class Algorithm {
public:
    void execute() {  // Template method
        initialize();
        process();    // Pure virtual - must implement
        cleanup();
    }
protected:
    virtual void initialize() { /* default implementation */ }
    virtual void process() = 0;  // Pure virtual
    virtual void cleanup() { /* default implementation */ }
};
```

### **Abstract Factory Pattern**
```cpp
class AnimalFactory {
public:
    virtual Animal* createAnimal() = 0;
    virtual ~AnimalFactory() = 0;
};

class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal() override { return new Dog(); }
};
```

---

## 🧪 **Example: Complete Abstract Class Implementation**

### **animal.hpp**
```cpp
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type;
    std::string name;

public:
    // Constructors (can be concrete)
    Animal();
    Animal(const std::string& name);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    
    // Pure virtual functions (makes class abstract)
    virtual void makeSound() const = 0;
    virtual void eat() const = 0;
    
    // Regular virtual functions (can be overridden)
    virtual void sleep() const;
    virtual std::string getType() const;
    
    // Concrete functions (inherited as-is)
    void setName(const std::string& name);
    std::string getName() const;
    
    // Virtual destructor
    virtual ~Animal();
};

#endif
```

### **animal.cpp**
```cpp
#include "animal.hpp"

Animal::Animal() : type("unknown"), name("unnamed") {}

Animal::Animal(const std::string& name) : type("unknown"), name(name) {}

Animal::Animal(const Animal& other) : type(other.type), name(other.name) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        name = other.name;
    }
    return *this;
}

void Animal::sleep() const {
    std::cout << name << " is sleeping..." << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::setName(const std::string& n) {
    name = n;
}

std::string Animal::getName() const {
    return name;
}

Animal::~Animal() {
    std::cout << "Animal " << name << " destroyed" << std::endl;
}
```

### **dog.hpp**
```cpp
#ifndef DOG_H
#define DOG_H

#include "animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const std::string& name);
    
    // MUST implement pure virtual functions
    void makeSound() const override;
    void eat() const override;
    
    // Can override regular virtual functions
    void sleep() const override;
    
    ~Dog();
};

#endif
```

### **dog.cpp**
```cpp
#include "dog.hpp"

Dog::Dog() : Animal() {
    type = "dog";
}

Dog::Dog(const std::string& name) : Animal(name) {
    type = "dog";
}

void Dog::makeSound() const {
    std::cout << name << " says: Woof! Woof!" << std::endl;
}

void Dog::eat() const {
    std::cout << name << " is eating dog food" << std::endl;
}

void Dog::sleep() const {
    std::cout << name << " is sleeping in the doghouse" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
```

---

## 🎭 **Usage Example**

```cpp
#include "dog.hpp"
#include "cat.hpp"

int main() {
    // ❌ Animal animal;  // Error: cannot instantiate abstract class
    
    // ✅ Create derived objects
    Animal* animals[3];
    animals[0] = new Dog("Buddy");
    animals[1] = new Cat("Whiskers");
    animals[2] = new Dog("Max");
    
    // ✅ Polymorphism works
    for (int i = 0; i < 3; i++) {
        std::cout << "Animal: " << animals[i]->getName() 
                  << " (" << animals[i]->getType() << ")" << std::endl;
        animals[i]->makeSound();  // Calls correct derived implementation
        animals[i]->eat();        // Calls correct derived implementation
        animals[i]->sleep();      // May call derived or base implementation
        std::cout << "---" << std::endl;
    }
    
    // ✅ Clean up
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    return 0;
}
```

---

## 🧠 **Memory Points**

1. **Abstract = Has at least one pure virtual function (`= 0`)**
2. **Cannot instantiate abstract classes directly**
3. **Can use pointers/references to abstract classes**
4. **Derived classes must implement ALL pure virtual functions**
5. **Pure virtual destructor still needs implementation**
6. **Abstract classes can have concrete members and methods**
7. **Virtual destructor is essential for proper cleanup**

---

## 🚨 **Common Mistakes**

### **1. Forgetting to Implement Pure Virtuals**
```cpp
class Dog : public Animal {
    void makeSound() const override { /* implemented */ }
    // ❌ Forgot to implement eat() - Dog becomes abstract too!
};
```

### **2. Missing Pure Virtual Destructor Implementation**
```cpp
class Animal {
    virtual ~Animal() = 0;  // Declaration
};
// ❌ Missing: Animal::~Animal() {} in .cpp file
```

### **3. Trying to Instantiate Abstract Class**
```cpp
std::vector<Animal> animals;  // ❌ Error: needs Animal objects
std::vector<Animal*> animals; // ✅ OK: pointers to Animal
```

### **4. Not Using Virtual Destructor**
```cpp
class Animal {
    ~Animal() {}  // ❌ Not virtual - memory leaks with polymorphism
};
```

---

## 💡 **When to Use Abstract Classes**

- ✅ When you have a **common interface** multiple classes should implement
- ✅ When you want to **prevent instantiation** of base class
- ✅ When you need **polymorphism** but base class doesn't make sense alone
- ✅ When you want to **force derived classes** to implement specific methods
- ✅ When creating **frameworks** or **libraries** with extensible designs

**Examples:** Shape (Circle, Rectangle), Vehicle (Car, Motorcycle), Animal (Dog, Cat), Stream (FileStream, NetworkStream)

---

*This guide covers everything you need to know about abstract classes in C++!*
