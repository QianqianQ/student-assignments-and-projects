title: Container printer
task_id: M3-TOSTRING
points: 1


**Objective:** Learn basic use of templates.

In this exercise you will need to implement different overloaded
versions of function *toString* that returns the contents of an
container as a string.

  * One version of the function gets a container type as a parameter,
    in which case it will return the contents of the whole container
    in a string.	
  * Another version of the function gets beginning and ending
    iterators, in which case the range between iterators is printed.
  * In addition, if given a string, the *toString* should just return
    the string inside double quotes: `"somestring"` 

Apart from the single string case, the function should return the
container items as comma separated list inside brackets. For example,
in the case of string container elements, it would return something
like the following:

`{ foo, bar, baz }`

The functions should work with any kind of sequential container.
