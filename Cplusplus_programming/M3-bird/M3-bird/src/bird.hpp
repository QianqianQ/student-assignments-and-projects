#ifndef BIRD_HH
#define BIRD_HH

#include <string>
#include <ostream>
#include <vector>
#include <iostream>


/*
 * CLASS BIRD
 */
// All member functions are implemented in this header file.
// There is no bird.cc.

class Bird {
public:



  // Constructor (explicit, we want to avoid implicit typecasts from string)
  explicit Bird(std::string const &name) : name(name)
  {}

  // We use implicit copy constructor and assignment operator.

  // Virtual - this class may be derived from
  virtual ~Bird() {}


  // All birds can fly, or at least the birds we are implementing
  // in this exercise.
  //
  // Notice that flying is not a const member function -
  // const birds cannot fly! They can only speak.

  void fly(std::ostream &os) { os << name << " flies!" << std::endl; }

  // How birds speak is defined by their genus (it is implemented in
  // the derived classes)

  virtual void speak(std::ostream &os) const = 0;

  // Returns the name of the bird.
  std::string getName() const
  {
    return name;
    }

private:
  std::string name;

};

/*
 * CLASS AVIARY
 */
class Aviary {
    public:
        Aviary() {}

        // When a bird is added to the aviary, it's ownership
        // is transferred. When the aviary is destroyed, all
        // the birds are destroyed too.
        //
        // If bird is NULL, std::logic_error is thrown.
        void addBird(Bird *bird);

        // This function calls the speak() method of all
        // birds in the order they were added to the aviary.
        // The first parameter is passed to the speak() method
        // of a bird.
        void speakAll(std::ostream &os) const;

        // Create a new type alias sizeType

        // Returns how many birds there are in the aviary.
        size_t size() const;

        // You must implement at least the indexing operator [].
        // It must work for both const and nonconst aviaries.
        // If the aviary is indexed out of bounds, std::out_of_range is
        // thrown.
        // The return types are const Bird * for the const version and
        // Bird * for the nonconst version.

        // Obviously this class must NOT leak any resources.
        // If somebody tries to copy an instance of this class,
        // the compilation must fail.
        Bird* operator[](size_t j);
        Bird* operator[](int i) const;

    private:
        std::vector<Bird*> list;
};

/*
 * TODO: IMPLEMENT CLASSES OWL AND DUCK HERE
 */
class Duck: public Bird{
public:
    Duck(const std::string& name): Bird(name){};
    void speak(std::ostream &os) const {
        os<<getName()<<": "<<"QUACK"<<std::endl;
    }

};

class Owl: public Bird{
public:
    Owl(const std::string& name): Bird(name){};
    void speak(std::ostream &os) const {
        os<<getName()<<": "<<"WHUU"<<std::endl;
    }

};


#endif


