# Get_Next_Line

With the project get next line, I was able to finally write a function that will allow you to read a line ending with an
newline character from a file descriptor.

You are now starting to understand that it will get tricky to read data from a file descriptor if you don’t know its size beforehand. What size should your buffer be? How
many times do you need to read the file descriptor to retrieve the data ?

It is perfectly normal and natural that, as a programmer, you would want to read a
“line” that ends with a line break from a file descriptor. For example each command that
you type in your shell or each line read from a flat file.

Thanks to the project get_next_line, you will finally be able to write a function
that will allow you to read a line ending with a newline character from a file descriptor.
