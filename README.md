# igrep

igrep is an implementation of a command line utility, grep, that searches plain text files for a specific string.

igrep supports the "-i", "-n", "-h" flags.
if "-i" (ignore clase flag) is included igrep will ignore the case of the string argument.
if "-n" (line number flag) is included igrep will print the line number of the text.
if "-h" (print help flag) is included igrep will print a usage message and then immediately exit.
*Also possilbe to have both "-i" and "n" flags

pg25525.txt is included as a sample text file.
Example of command: igrep -i The <pg25525.txt


Contributor: Ryan Samuel

