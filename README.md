# SHA-512 C Program

This Repo was a project made for my 4th Year in Software Development in the <b>Theory of Algorithms Module</b>.

## Description
The purpose of the application is to take in a File from the command line as an argument and parse it into a SHA-512 Hash. The application is written in the C programming language and was developed upon a Debian based linux distribution (Ubuntu) such that the tests.sh file that is ran during the ```make test``` command will only work on these distrubutions that have GCC- Make Installed either through Build Essentials or another Sudo Command. The output of the code is similar to that of sha512Sum command that is built into many debian based linux distributions and this can be seen within the tests.sh which will test the program against it. Pass meaning sha512sum and this application have the same SHA-512 Output Message.

The guidelines used when creating this application was the Secure Hash Standard publication located on Nist (https://www.nist.gov/publications/secure-hash-standard), as this publication is well written and conside and seems to be a common standard when developers wish to create their own Secure Hash Algorithm Functions within an application and is universal among most Programming Languages as long as you know the language itself and can deciphyer the symbols within the publication.

### Note (Lab Work Folder)
Inside the <i>LabWork</i> folder there are files that run SHA-256 which were compiled over weeks of work within the module but are not inheritantly attatched to the SHA-512 side of the application and can be ignored if you the user wishes to do so.


## Compilation Instructions
#### Requirements

* make ("http://manpages.ubuntu.com/manpages/cosmic/man1/make.1.html")
* gcc or clang installed (May use sudo <i>apt-get install build-essentials</i>)

### Running the Main Sha512 Algorithm (Requires a Input File)
1. Ensure you have make and gcc installed upon your operating system/distribution.
2. Next Run ```make sha512```, this will look into the MakeFile and folow the commands and create a executeable sha512 program.
3. Next on your terminal while in the folder of your previously made executeable run ```./sha512 <"Your File">```(Replace the <"Your File"> part with your own path to file / file name within the folder eg. ```./sha512 input.txt```  OR  ```./sha512 ./abc.txt```)
4. After the above command is ran, the program should output the SHA-512 output message of your inputted file or give a warning/error if your file was not found. <i> If your file was not found ensure that you have the path correct or the file name correct </i>

### Running the Tests
1. Ensure you have make and gcc installed upon your operating system/distribution.
2. Next Run ```make test```.
3. The Application should continue to print out the sha512sum and this applications output and compare them against eachother using both the empty.txt file and the abc.txt file. You may change these files if you know what you are doing and test different SHA-512 inputs, to ensure that the code is satisfactory and prints the correct values.


## The Purpose of the SHA-512 Algorithm 

