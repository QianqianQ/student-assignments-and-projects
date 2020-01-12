title: Vector of strings
task_id: M1-STRINGS
points: 1
last_modified: 2015-09-10  (clarified the expected output format)

**Objective:** Practice use of C++ strings, as part of a STL vector.

Implement a program that stores and removes given strings from a
vector, as commanded by the user. You should implement a simple
command line user interface that supports the following commands. In
the beginning the proram should print `Commands: ADD, PRINT, REMOVE,
QUIT`, followed by newline, and before each command: `Enter command:`,
followed by newline. Then the program should read the command and do
the following:

  * "ADD": Adds a given string to the vector. The program should first
    prompt: `Enter a name:` (without space, followed by newline). Then
    it reads the name from the user and adds it to a the
    vector. Finally, it prints: `Number of names in the vector:`, a
    newline, the size of the vector, and finally newline. The ADD
    functionality is implemented in function `adder`.
  
  * "REMOVE": Removes the last string from the vector. This
    operation is implemented in function `remover`. The function
    should print the removed string in the following way: `Removing
    the last element:`, followed by a newline, then the string and a
    newline.

  * "PRINT": Outputs all stored strings, each on a separate line
    (e.g., followed by newline character). This operation is
    implemented in function `printer`.

  * "QUIT": that exits the program.

In addition to the above three functions, you need to implement
function `cmdReader` that parses the commands and calls the
appropriate functions. The detailed function interfaces can be found
in file "vector_strings.hpp".

Here is an example of an session:

<pre>
Commands: ADD, PRINT, REMOVE, QUIT
Enter command:
<font color="red">ADD</font>
Enter a name:
<font color="red">Erkki</font>
Number of names in the vector:
1
Enter command:
<font color="red">ADD</font>
Enter a name:
<font color="red">Tiina</font>
Number of names in the vector:
2
Enter command:
<font color="red">PRINT</font>
Erkki
Tiina
Enter command:
<font color="red">REMOVE</font> 
Removing the last element:
Tiina
Enter command:
<font color="red">QUIT</font></pre>

(red lines above are input from user)
