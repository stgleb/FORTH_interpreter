Design Decisions:
1. Built-in functions are kept in a list of (string, stack_func) pairs, called "func_list", 
	while user-defined functions are kept in a list of (name, def) pairs, where name is a string 
	and def is a list of strings. The list of pairs is called "definitions".
	-- makes the programming easier to keep built-in and user-defined functions in separate lists
	-- does not detract from efficiency
2. Words in a user-defined function are checked before being added to the definitions list. 
	Each word must be either an integer, the name of a built-in function, the name of a 
	pre-existing user-defined function, or the name of the user-defined function currently 
	being defined (for recursion).
	-- checking each word before adding to definitions list is consistent with gforth. this is efficient
		because it prevents us from having to check each word in the function definition when
		running a user-defined function. each word is checked once, rather than multiple times, if, say,
		we want to run a particular user-defined function multiple times
3. Recursive functions are defined normally, without the word "recurse" or "recursive".
	-- not consistent with forth/gforth, but makes the programming easier
	-- for each word, we must check to see if it is the same as the function name, but this 
		does not decrese efficiency by more than O(1) 
4. If/else statements are not permitted outside of function definitions.
	-- consistent with gforth and makes programming easier
	-- affects efficiency in that one less thing is being checked upon user input
5. Nested if/else statements not permitted.
	-- not consistent with gforth, but makes the programming easier
	-- does not affect efficiency, but limits how complex user-defined functions can get