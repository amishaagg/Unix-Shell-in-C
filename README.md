# Unix-Shell-in-C
Basic linux shell made using C

## Commands Implemented
### Internal Commands
* cd
* echo
* pwd
* history
* exit
### External Commands
* ls
* date
* mkdir
* cat
* rm

## Detailed Description
Internal commands are handled directly by shell. For each external command I have made a .c file and used fork() and execl() to implement those functions. I am reading input through readline.

### Errors handled:
1)waitpid(): On error, -1 is returned.
2)If process id returned by fork is <0, means there was error in fork.
3)invalid arguments

### Commands
* cd:
  * -P use the physical directory structure without following symbolic links
  * --help gives description of cd
  * errors: too many arguments, no such directory found, error opening help file

* echo: 
-n do not output the trailing newline
-E disable interpretation of backslash escapes (default)

* history: 
-c clear
-d remove a particular entry

* pwd: 
-P print the physical directory, without any symbolic links
--help help gives description of pwd
errors: too many arguments, error in getting current directory, error opening help file

* exit

* ls:
-1 display in different lines
-a display all files, including hidden
errors: could not open current directory, invalid argument

* cat(takes multiple arguments)
-n number the lines
-E add '$' to the end of line
errors: error opening file, file doesnt exist

* date
-u shows Universal time(GMT)
-R shows date in RFC 5322 format
errors: invalid command

* rm
-f ignore nonexistent files and arguments, never prompt
-i prompt before every removal
errors: can't remove as its a directory, file doesn't exist

* mkdir
-m set file mode (as in chmod)
-v print a message when directory created
errors: file already exists, error while creating(errno)

### Assumptions
1)echo prints backslash characters and quotes too.
2)rm -i when prompts, 1 means yes and any other int means no.
3)any other options or commands except those mentioned above are considered to be invalid.
