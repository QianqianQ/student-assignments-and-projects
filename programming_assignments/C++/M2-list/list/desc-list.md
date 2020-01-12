title: List
task_id: M2-LIST
points: 1


**Objective:** Understanding the basic handling of list, and using input
stream as a source.

This exercise reads series of lines into a list container from input
stream, that can be the standard input, or for example a file. You
will need to implement the following functions:

  * **getLines(is, list)** that will read lines from the given input
  stream (**is**), and add each line to the **list**. You will find
  function **[getline](http://www.cplusplus.com/reference/string/string/getline/?kw=getline)**
  useful for reading lines from the input stream. The function will
  read as long as the input stream is readable. See **[istream]()**
  reference for ideas how to check the input stream state.

  * **print(list)** that will print each string in the **list** on a
  separate line on standard output stream.

  * **sortAndUnique(list)** that will sort the list into alphabetical
  order and remove duplicate strings. See [list] reference for further
  information.

[list]: http://www.cplusplus.com/reference/list/list/?kw=list
