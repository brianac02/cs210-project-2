# cs210-project-3
Module 8 - Portfolio Submission for Brian Carman

PROJECT SUMMARY

In this project, the task was to create a program for a grocery store, named Corner Grocer, that could do a few different things, as follows:
1. Get input from a file
2. Use that information to:
   1. Match a user-entered word (string) to one in the file, and return both the entered item and how many times it was found
   2. Return every item in the file (receipt) and how many times it was found
   3. Do the same as in number 2.2, except the numbers are to be represented as asterisks
3. Backup the data in the input file with in output file, storing each item once along with its frequency represented by an integer

I think one of the thing I did best was keeping things readable in organized. I used a lot of in-line comments so that anyone with no coding 
background could understand what's going on in that program. The main function is very un-cluttered, and the class files are very organized and 
readable as well. That's something I've struggled with all along, so I was happy to be able to figure some of that out. I didn't actually seee
the note in the assignment that we SHOULD use maps and pairs, so I spent roughly 15 hours learning the ins and outs of them on my own, which is 
something else that I feel that I did well on - being resourceful and seeking help from peers when I needed it. 

As far as improvements go, there are a few areas where I feel that I definitely could have improved. One area is in the "ChoiceOne" function in the
GroceryStore.cpp file. I wrote a cout statement (three, actually, to keep it all on screen) that outputs each item in the input file / receipt, 
where I could have used a function or block of code similar to in ChoiceThree, where I call the countOccurrences function and then use the for loop
to print asterisks for each int (frequency). Instead, I could just do a for loop i.e
for (const auto& pair : newResult) {
  cout << "-" << pair.first << endl; 
}
No clue if that's exactly right, but that's the first thing that came to mind. Another thing is that I think I could have made it more inclusive as far
as user input goes. I added checks and balance, for instance - when, in main(), I prompt the user to enter their menu choice, either 1, 2, 3, or 4, and if 
the number isn't one of those four, but it's an int, I have the if-else statement print an error message, and if the number / value entered isn't of type
int, I have a block of code that prevents the infinte cin failbit loop. However, say they press "1" for their menu choice. They'll be prompted to enter a 
string IDENTICAL to how it's written on the list of items I provided, because since C++ is caps sensitive, broccoli would return 0 occurrences, but Broccoli
would return a few instances. I think I could've used a if / else statement to see if the character at [0] in the string is capital (< a) then it'd pass as
okay, but else, I would subtract 26 from the value of the letter (like the ASCII value, if that makes sense) which would make a (which, if A is 1 and Z is 26,
a would be 27) and then try to search the vector for a match of that. Other than that, I think the code was fairly well written. 

As written above, I spent a lot of time struggling with a deliberating over this project, given my still limited knowledge of the field. It was the first time
where I really found myself stuck, which was mainly due to having to use maps, pairs, and, well, having to write code that does what functions countSpecificWord
and countOccurrences both do. I had spent a lot of time trying different things, even scratching and starting anew, so, like I said, I had to turn to
my resources, which were including, but not limited to, Stack Overflow and peers and colleagues who have been in the field much longer than I. 

As far as skills that're transferable from this project to the next, the ones that shine above all else would have to be critical thinking skills and 
problem solving skills, which at the end of the day, are 99% of what my journey with coding has been thus far. This project more than the rest,
however, really tested my ability to be able to get a program to do what I need it to do without necessarily having all the knowledge and acumen to do
it from the get-go. 

Last but not least, to make everything readable and maintainable, I first wrote everything out in comments, about what I wanted to do on whichever file.
I outlined my functions, described how I would implement them, and how I would call them. This made writing the code much easier, albeit again, I didn't
necessarily know how to get the program to do what I wanted it to do right away. Nonetheless, the pre-code-writing design made things significantly
more understandable for both writer and reader alike, and I kept many of them around so that I could easily go back in and make edits where I needed to
if certain things weren't working. The other thing is that, as mentioned above, I put about as much as I could into functions, so that the main function
is nice and readable. Initially, I had ChoiceOne - Three written in the if - else statement in main, but the main function was incredibly cluttered,
so I wrote those as their own individual functions, and transferred the block of code that got input from the file as well as backed up the data to 
an output file to functions as well, to free up some more space, and I personally feel like it made the code much easier to understand. 
