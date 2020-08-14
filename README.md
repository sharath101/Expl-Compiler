# Expl-Compiler

The project was done under the guidance of Mr. K Murali. <br>
Roadmap: http://silcnitc.github.io/roadmap.html

Specification of the Language(Expl): http://silcnitc.github.io/expl.html <br>
Specification of the Object Oriented Counterpart(OExpl): http://silcnitc.github.io/oexpl-specification.html

Test Programs(Expl): http://silcnitc.github.io/testprograms.html#test6 <br>
Test Programs(OExpl): http://silcnitc.github.io/oexpl-testprograms.html#test7

The Program needs to be copied into the **Input** file to be able to compile it.

**Instructions to compile and run the Input Program:**

1. Clone the repository into your local Machine.

2. Open the terminal in the location you cloned it and paste the following series of commands to compile the Input Program: **yacc -d expl.y; lex expl.l; gcc y.tab.c lex.yy.c -o ans.exe; ./ans.exe; lex xsm.l; gcc lex.yy.c -o ans.exe; ./ans.exe**

3. To run the program, Go to the xsm_expl folder and run the following command **./xsm -l library.lib -e prog.xsm**
