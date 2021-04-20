# SHA-512 C Program
## Description
The purpose of the application is to take in a File from the command line as an argument and parse it into a SHA-512 Hash. The application is written in the C programming language and was developed upon a Debian based linux distribution (Ubuntu) such that the tests.sh file that is ran during the ```make test``` command will only work on these distrubutions that have GCC- Make Installed either through Build Essentials or another Sudo Command. The output of the code is similar to that of sha512Sum command that is built into many debian based linux distributions and this can be seen within the tests.sh which will test the program against it. Pass meaning sha512sum and this application have the same SHA-512 Output Message.

The guidelines used when creating this application was the Secure Hash Standard publication located on Nist (https://www.nist.gov/publications/secure-hash-standard), as this publication is well written and conside and seems to be a common standard when developers wish to create their own Secure Hash Algorithm Functions within an application and is universal among most Programming Languages as long as you know the language itself and can deciphyer the symbols within the publication.

---

### Note (Lab Work Folder)
Inside the <i>LabWork</i> folder there are files that run SHA-256 which were compiled over weeks of work within the module but are not inheritantly attatched to the SHA-512 side of the application and can be ignored if you the user wishes to do so.

---
## Compilation Instructions
#### Requirements
| Syntax | Description |
| ----------- | ----------- |
| <b>Make-</b><i>Makefile Support</i> | http://manpages.ubuntu.com/manpages/cosmic/man1/make.1.html |
| <b> gcc or clangd</b> | May use (<i>sudo apt-get install build-essentials</i>)|
</br>

### Running the Main Sha512 Algorithm (Requires a Input File)
    1. Ensure you have make and gcc installed upon your operating system/distribution.
    2. Next Run ```make sha512```, this will look into the MakeFile and folow the commands and create a executeable sha512 program.
    3. Next on your terminal while in the folder of your previously made executeable run ```./sha512 <"Your File">```(Replace the <"Your File"> part with your own path to file / file name within the folder eg. ```./sha512 input.txt```  OR  ```./sha512 ./abc.txt```)
    4. After the above command is ran, the program should output the SHA-512 output message of your inputted file or give a warning/error if your file was not found. <i> If your file was not found ensure that you have the path correct or the file name correct </i>
### Running the Tests
    1. Ensure you have make and gcc installed upon your operating system/distribution.
    2. Next Run ```make test```.
    3. The Application should continue to print out the sha512sum and this applications output and compare them against eachother using both the empty.txt file and the abc.txt file. You may change these files if you know what you are doing and test different SHA-512 inputs, to ensure that the code is satisfactory and prints the correct values.
----

## SHA-512 Algorithm and it's Purpose

 The SHA-512 algorithm belongs to a family of other Secure Hash Standerds such as  SHA, SHA-1, SHA-2 and SHA-3 Each having it's own Block Size, Output Size and Internal State Sizes. SHA-512 being much more secure than the original SHA or algorithms in the SHA-0 or SHA-1 Categories as it's in the SHA-2 Category which is larger in hash message size and computing time, it is less influenced by Collision Based Attacks and Primeage Attacks. The fall back on using SHA-512 is its time to calculate a single hash so for programs that require many hashes calculated at the same time such as a web server dealing with 1000's of passwords per minute, it may not always be the most efficent or another example may be bitcoin where they opted for a SHA256 for the blocks within crypto.

 The purpose of these Secure Hash Algorithms in general is to generate digests of messages that are non reversible to ensure the integrity of a file since the digests were generated. Such as when you go to download a file online, you can compare the file you downloaded to the SHA Message Digest displayed on the webpage, using a local program and a character comparator. If the file you downloaded has a different hash to the original one displayed, it is highly likely the integrity of the file has been tampered with and would not be safe to run on your local machine as someone has probably infected it with a virus or intends to use it for mal practice such as stealing user information. SHA is not the only function family which deals in hashed message digests as there is also MD2 and MD5 but the decesion on which algorithm to use is mostly up to the developers usages and how often the hashing function will be called upon, which may require some expertise into Big-O Notation and Data Structures to ensure the most efficent algorithm is used while also being the most secure for the developers use case and computer hardware.

## Terms
| Syntax | Description |
| ----------- | ----------- |
| <b>Primeage Attack</b> |  Using pre-computed tables of solutions are used in a brute-force manner in order to crack passwords. Requires a very powerful computational array of machines to crack.
| <b>Collision Based Attack</b> | Non Sensical message produces the same hash as the original message. Computation Time is 2^n/2 where n is the Length of Message. This is why the larger Message Digests are harder to perform collision based attacks on as L the length would be much longer and require more computational power. |
</br>

# Questions

## 1. Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?
----
Simarly to basic mathematics such as addition. If we have even one of the inputs to an output it is easy to find the other input of a calculation. 
i.e

    2 + x = 4. x must be 2 by basic algebra.

But in the case of a Secure Hash Output, we do not know the inputs so this problem because increasingly harder.

    x + y = 50.
In the above we cannot tell what two numbers make up **50** or if they are the original, we can take guesses such as **25+25** or **10+40** but if we are never told the original inputs we could never know.
So this adds 1 dimension of difficulty to reversing the Hash Message Digest alone.

Next we need to consider a major key part in the hashing algorithm, in that a real hash function uses hundreds of one-way operations that take place sequentially while using previous operations resulting outputs in the later performed operations calculation, this can also be known as <b> Bit Dependency </b>. So when calculating hash output you are basically dealt with a  **all or nothing approach** where if even one bit is changed the whole output message could be vastly different.

<i>Below is an example in SHA-512</i>
    
    Input "0001":
    
    Output: 65c5c6dd34bf2c6ef2991bca4da7f80bb95480b30edcc547221850ef80d167d63aa2960dd610037d1867e1203e797b3991bc1ea18b575de0152f2a3c5c3d62a1

    Input "0011":
    
    Output: 0eedcf6ff77f791c328f6f76fc36b9506233c224f1ba542fe7c8ed52473ae6a347ccb9ba7623dbc7281b6cb4e5cbd3784d5686aa6c6caab728c9642ff3e416a2

As you can see from the above, even by changing one 0 to a 1. The output has completely changed thus you cannot reverse a Secure Hash Algorithms output one sequence at a time, you need try millions of full inputs before you will recieve the original message value as no less than the original input will do.

The hashing algorithms also use non linear operations, such that you could not reverse a input using linear algebra techniques thus even the example at the beggining of this section is not even fully relevant to the complexity of the operations performed within the hashing algorithm as it uses many combinations of non linear and linear operations to compute it's output.

---
## 2. Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
---
Yes it would be possible to design a algorithm that does this, infact it is very similar to the algorithms behind Bitcoin Mining where pools of machines try to mine bitcoins by dealing with SHA-256 hashing, although it takes these pools of machines a long time to mine even a single coin which is equivilent to a very small amount of progress. So any single users machine would not be enough to find all the possible inputs for a particular hashed output within the machine or users lifetime unless we progress to the realm of quantum computing which can perform the tasks in computing we have in our time with multitude of times improved efficency. According to a post by Nella Ludlow on Forbes.com, in her words she stated that 

*"If usable quantum computing were accessible, the field of cryptography would dramatically change, encryption codes could be broken quickly and perhaps crushing Blockchain technology."*

This could be perhaps very true as a Quantum Machine does not work on the simple binary system that we have today, but on the idea of Qubits which has the ability of being both a 1 and a 0 at the same time for multiple iterations per Qubit. As of last year IBM promised a [1000 Qubit PC](https://www.sciencemag.org/news/2020/09/ibm-promises-1000-qubit-quantum-computer-milestone-2023) this would mean the pc could consecutively be 1000s of 1 and 0's at the same time and perform operations in a concurrent way and speed that pc's of today would never catch up with even in large pools like they are within bitcoin mining. 
So if given a working quantum pc as stated above, it would be very possible to crack the different inputs required to create the same hash digest outputs within a person's lifetime for multiple types of SHA Hash Function but as of right now quantum computers are neither widely available or fully developed so based on current hardware, no single consumer based pc would be able to crack a SHA-2, or SHA-3 category Digest within a person’s life time.

In terms of SHA-1, it has already been done through multiple methods and the idea of having a hashed output be the same with different inputs parallels with the idea of Collision Attacks and Collision within hashing in general. As users have had tried to brute force a SHA message to find its original inputs and even found algorithms to perform this successfuly such as cracking SHA-1 by using a [chosen-prefix collision](https://www.usenix.org/system/files/sec20-leurent.pdf) for it.

---
## 3. How difficult is it to find a hash digest beginning with at least twelve zeros?
---

Considering that a hash digest is usually made up of Hexadecimal values, each string in the digest can range from anywhere between 0 and 15 (F in Hex). So you would have a 1/15^12 chance before we even consider the complexity of these algorithms and their non linearity as discussed above. A user would have a more likely hood to win their national lottery 10 times over than they would finding a hash digest to begin with 12 0's by inputting some file or text. This issue is also the prime difficulty within the Bit Coin Mining industry currently. The hash of a block within bitcoin needs to start with a certain number of zero values but the probability of calculating such a hash is very low therefore numerous attempts are made by thousands of users machines across the planet to generate new hashes and attempt to increment the nonce value such that they eventually can reach a valid hash and move onto the next major block. The issue with bitcoin mining is that as their target requires more nonce values or is "lower" the more exponentially difficult the task becomes and this is only the cracking of a SHA-256 algorithm not like the SHA-512 based algorithm built in this application. The current objective of bitcoin is to find the input for a 17 nonce value hash string but it has taken bitcoin over 10 years to get to this point with thousands of machines running day and generating millions of hashes to get this far. So the likely hood of you inputting something into a Secure Hash Algorithm and recieving back a Hash Digest with 12 leading 0's is impossibly possible as the chance of it happening is so low it might as well be impossible.
