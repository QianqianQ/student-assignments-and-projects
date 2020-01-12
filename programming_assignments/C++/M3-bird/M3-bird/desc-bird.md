### Task: Birds 

**Objective:** Practice abstract classes and inheritance.

You will need to implement different kinds of birds that all can fly
(expect *const* birds). Birds also speak, but in different languages
specific to the bird type. **Bird** (in *bird.hpp*) is the abstract
base class for birds. You will need to implement **Duck** and **Owl** 
(and define them also in *bird.hpp*). To save some
effort, you can implement the needed functions inline in the bird-specific
header files together with the the class definitions.

The bird language is simple: duck says "QUACK" and owl says
"WHUU". The speak function should output the name of the bird, colon,
space and followed by one of the above, e.g.:

`Donald: QUACK`
 
In addition, you will need to implement class **Aviary** (in the same
*bird.hpp*) that stores the birds. Implement also *Aviary* member functions into 
the *aviary.cpp* file.

**It is good practise to have different header files for different classes, but 
here it is more pratical to store all of the classes in a single header, as 
otherwise you should return over 6 files.**

You will find more instructions in the header files.
Use this [zip package](http://src.aalto.fi/cpptasks/M3-bird.zip) to get
the files related to this task. The package also contains Makefile and headers
that you can use to build and test the code in your own machine.

