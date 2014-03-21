Given a regular expression with characters a-z, ' * ', ' . ' 
the task was to find if that string could match another string with characters from: a-z 
where ' * ' can delete the character before it, and ' . ' could match whatever character. ' * ' always appear after a a-z character. 
Example: 
isMatch("a*", "") = true; 
isMatch(".", "") = false; 
isMatch("ab*", "a") = true; 
isMatch("a.", "ab") = true; 
isMatch("a", "a") = true;
