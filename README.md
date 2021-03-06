# Syracuse

## Conjecture

The syracuse sequence is defined : $${\displaystyle f(n)={\begin{cases}{\frac {n}{2}}&{\text{if }}n\equiv 0{\pmod {2}}\newline 3n+1&{\text{if }}n\equiv 1{\pmod {2}}.\end{cases}}}$$   
For more information about the conjecture, see [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture " ").  

## Goal

In this repo, you can find 2 main idea, building the syracuse tree, starting by 1, getting all the parents of the numbers and build the tree out of that. On top of that using graphviz's tool `dot`, we can visualize the tree in a svg file.  
The second idea, is for a given number $n$, plot the graph of $f(n)$ using matplotlib.pyplot in python.

## Compiling
For the compilation you'll need tools such as : make and gcc.  
For the tree visualization, you'll need the `dot` executable from [graphviz](https://graphviz.org/download/).  
For the graph visualization, you will need python3 and matplotlib.pyplot package.

### Syracuse Tree

