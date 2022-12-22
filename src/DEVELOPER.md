
In part C of the project, some of the data structures used were double pointers to arrays and structs. Struct pointers were passed as parameters to 
the functions along with function pointers in some functions.

Structs:
1) A ca_data struct that describes a 2D cellular automata. It has an array of unsigned characters called cadata,width and height of the array,
  the number of states the array could have, dimensions of the input array and a flag which 
  specifies if an array should be wrapped or not.


Functions:
1) void initCA(struct ca_data *ca, int state);


  This method initialize every state of an array to the state that the user gives. 
  Parameters: 1) struct pointer called ca: this has the array and other properties of the struct object which can be accessed using ->
              2) states: this has the value that the array cells have to be initialized to.
 

2) int set1DCACell(struct ca_data *ca, unsigned int x , unsigned char state);

This method sets the state of an array to a character or an integer. It returns an integer based on whether the setting actually happened or not.
  Parameters: 1) struct pointer called ca: this has the array and other properties of the struct object which can be accessed using ->
              2) x: user sets the state to a value at that index.
              3) state: user sets the array[index] to the state.

3) void displayCA(struct ca_data *ca);

This function displays the CA.
  Parameters: 1) the struct pointer which can access the number of cells as well as the array of cells to display.
             

4) struct ca_data * create1DCA(int w, unsigned char state);

This method creates a new 1D cellular automata. We set the num to the number of cells, and initialize the array with initValue. We use 
malloc throughout to dynamically allocate memory.
  Parameters: 1) int w: sets the number of cells.
              2) unsigned char state: initializes the array to the initValue and creates the 1D cellular automata.


5) void step1DCA(struct ca_data *ca, unsigned char (*ptrFunction)(struct ca_data *, int), int flag);


  This function performs 1 step of the cellular automata. It takes 3 parameters:
  Parameters:i) a struct pointer that corresponds to the current array that we are working with.
            ii) a function pointer that points to the rule that sets the value of the character at the given index.
            iii) a flag which specifies what to do for edge cases(whether to wrap or not).


6) int set2DCACell( struct ca_data *ca, unsigned int x, unsigned int y, unsigned char state);

  
  This method sets the state of an array to a character or an integer. It returns an integer based on whether the setting actually happened or not.
  Parameters:1) struct pointer called ca: this has the array and other properties of the struct object which can be accessed using ->
             2) x: x coordinate of the index.
             3) y: y coordinate of the index.
             4) state: sets the 2D CA to that state.

7) struct ca_data *create2DCA( int w, int h, unsigned char qstate); 

  This method creates a new 2D cellular automata. We set the w to width, h to height, and initialize the array with qstate. We use 
  malloc throughout to dynamically allocate memory.
  Parameters: 1) int w: width of the array
              2) int h: height of the array. 
              3) unsigned char qstate: initializes the array to the qstate and creates the 2D cellular automata.

8) void step2DCA( struct ca_data *ca, unsigned char (*rule)(struct ca_data *, int x, int y));

  
  This function performs 1 step of the cellular automata. It takes 2 parameters:
  Parameters:i) a struct pointer that corresponds to the current array that we are working with.
            ii) a function pointer that points to the rule that sets the value of the character at the given index.
           
  
 