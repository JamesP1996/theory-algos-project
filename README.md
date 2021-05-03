# SHA-512 C Program
## Description
The purpose of the application is to take in a File from the command line as an argument and parse it into a SHA-512 Hash. The application is written in the C programming language and was developed upon a Debian based linux distribution (Ubuntu) such that the tests.sh file that is ran during the make test command will only work on these distributions that have GCC/Clangd with Make Installed either through the Build Essential package or another Sudo apt-get Command. The output of the code is similar to that of sha512Sum command that is built into many debian based linux distributions and this can be seen within the tests.sh shell script file which will test the program against the sha512sum command. A Pass meaning sha512sum and this application have the same SHA-512 Digest Output Message.
The guidelines used when creating this application was the Secure Hash Standard publication located on Nist (https://www.nist.gov/publications/secure-hash-standard), as this publication is well written and concise and seems to be a common standard when developers wish to create their own Secure Hash Algorithm Functions within an application and is universal among most Programming Languages as long as you know the language itself and can decipher the symbols within the publication.


---

### Note (Lab Work Folder)
Inside the <i>LabWork</i> folder there are files that run SHA-256 which were compiled over weeks of work within the module but are not inheritably attached to the SHA-512 side of the application and can be ignored if you the user wishes to do so.

---
## Compilation Instructions
#### Requirements
| Syntax | Description |
| ----------- | ----------- |
| <b>Make-</b><i>Makefile Support</i> | http://manpages.ubuntu.com/manpages/cosmic/man1/make.1.html |
| <b> gcc or clangd</b> | May use (<i>sudo sudo apt install build-essential</i>)|
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

 The SHA-512 algorithm belongs to a family of other Secure Hash Standerds such as  SHA, SHA-1, SHA-2 and SHA-3 Each having it's own Block Size, Output Size and Internal State Sizes. SHA-512 being much more secure than the original SHA or algorithms in the SHA-0 or SHA-1 Categories as it's in the SHA-2 Category which is larger in hash message size and computing time, it is less influenced by Collision Based Attacks and Preimage Attacks. The fall back on using SHA-512 is its time to calculate a single hash so for programs that require many hashes calculated at the same time such as a web server dealing with 1000's of passwords per minute, it may not always be the most efficent or another example may be bitcoin where they opted for a SHA256 for the blocks within crypto.

 The purpose of these Secure Hash Algorithms in general is to generate digests of messages that are non reversible to ensure the integrity of a file since the digests were generated. Such as when you go to download a file online, you can compare the file you downloaded to the SHA Message Digest displayed on the webpage, using a local program and a character comparator. If the file you downloaded has a different hash to the original one displayed, it is highly likely the integrity of the file has been tampered with and would not be safe to run on your local machine as someone has probably infected it with a virus or intends to use it for mal practice such as stealing user information. SHA is not the only function family which deals in hashed message digests as there is also MD2 and MD5 but the decision on which algorithm to use is mostly up to the developers usages and how often the hashing function will be called upon, which may require some expertise into Big-O Notation and Data Structures to ensure the most efficient algorithm is used while also being the most secure for the developers use case and computer hardware.

## Terms
| Syntax | Description |
| ----------- | ----------- |
| <b>Preimage Attack</b> |  Using pre-computed tables of solutions are used in a brute-force manner in order to crack passwords. Requires a very powerful computational array of machines to crack.
| <b>Collision Based Attack</b> | Non Sensical message produces the same hash as the original message. Computation Time is 2^n/2 where n is the Length of Message. This is why the larger Message Digests are harder to perform collision based attacks on as L the length would be much longer and require more computational power. |
</br>

# Questions

## 1. Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?
----
Similarly to basic mathematics such as addition. If we have even one of the inputs to an output it is easy to find the other input of a calculation. 
i.e

    2 + x = 4. x must be 2 by basic algebra.

But in the case of a Secure Hash Output, we do not know the inputs so this problem because increasingly harder.

    x + y = 50.
In the above we cannot tell what two numbers make up **50** or if they are the original, we can take guesses such as **25+25** or **10+40** but if we are never told the original inputs we could never know what numbers made up 50.
So this adds 1 dimension of difficulty to reversing the Hash Message Digest alone.

Next we need to consider a major key part in the hashing algorithm, in that a real hash function uses hundreds of one-way operations that take place sequentially while using previous operations resulting outputs in the later performed operations calculation, this can also be known as <b> Bit Dependency </b>. So when calculating hash output you are basically dealt with a  **all or nothing approach** where if even one bit is changed the whole output message could be vastly different.

<i>Below is an example in SHA-512</i>
    
    Input "0001":
    
    Output: 65c5c6dd34bf2c6ef2991bca4da7f80bb95480b30edcc547221850ef80d167d63aa2960dd610037d1867e1203e797b3991bc1ea18b575de0152f2a3c5c3d62a1

    Input "0011":
    
    Output: 0eedcf6ff77f791c328f6f76fc36b9506233c224f1ba542fe7c8ed52473ae6a347ccb9ba7623dbc7281b6cb4e5cbd3784d5686aa6c6caab728c9642ff3e416a2

As you can see from the above, even by changing one 0 to a 1. The output has completely changed thus you cannot reverse a Secure Hash Algorithms output one sequence at a time, you need try millions of full inputs before you will receive the original message value as no less than the original input will do.

The hashing algorithms also use non linear operations, such that you could not reverse a input using linear algebra techniques thus even the example at the beginning of this section is not even fully relevant to the complexity of the operations performed within the hashing algorithm as it uses many combinations of non linear and linear operations to compute it's output.

---
## 2. Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
---
Yes it would be possible to design a algorithm that does this, infact it is very similar to the algorithms behind Bitcoin Mining where pools of machines try to mine bitcoins by dealing with SHA-256 hashing, although it takes these pools of machines a long time to mine even a single coin which is equivalent to a very small amount of progress. So any single users machine would not be enough to find all the possible inputs for a particular hashed output within the machine or users lifetime unless we progress to the realm of quantum computing which can perform the tasks in computing we have in our time with multitude of times improved efficiency. According to a post by Nella Ludlow on Forbes.com, in her words she stated that 

*"If usable quantum computing were accessible, the field of cryptography would dramatically change, encryption codes could be broken quickly and perhaps crushing Blockchain technology."*

This could be perhaps very true as a Quantum Machine does not work on the simple binary system that we have today, but on the idea of Qubits which has the ability of being both a 1 and a 0 at the same time for multiple iterations per Qubit. As of last year IBM promised a [1000 Qubit PC](https://www.sciencemag.org/news/2020/09/ibm-promises-1000-qubit-quantum-computer-milestone-2023) this would mean the pc could consecutively be 1000s of 1 and 0's at the same time and perform operations in a concurrent way and speed that pc's of today would never catch up with even in large pools like they are within bitcoin mining but this is a long running debate and others feel that quantum computing will not break the mining ecosystem like Roger Huang who also is a poster for Forbes on he's post Titled "[Here’s Why Quantum Computing Will Not Break Cryptocurrencies](https://www.forbes.com/sites/rogerhuang/2020/12/21/heres-why-quantum-computing-will-not-break-cryptocurrencies/)"
So if given a working quantum pc as stated above, it would be very possible to crack the different inputs required to create the same hash digest outputs within a person's lifetime for multiple types of SHA Hash Function but as of right now quantum computers are neither widely available or fully developed so based on current hardware, no single consumer based pc would be able to crack a SHA-2, or SHA-3 category Digest within a person’s life time.

In terms of SHA-1, it has already been done through multiple methods and the idea of having a hashed output be the same with different inputs parallels with the idea of Collision Attacks and Collision within hashing in general. As users have had tried to brute force a SHA message to find its original inputs and even found algorithms to perform this successfully such as cracking SHA-1 by using a [chosen-prefix collision](https://www.usenix.org/system/files/sec20-leurent.pdf) for it.

---
## 3. How difficult is it to find a hash digest beginning with at least twelve zeros?
---

### Mining Difficulty in CryptoCurrency
To answer this question we can look into the topic of cryptocurrencies and the respective mining difficulty of bitcoin. Cryptocurrencies rely on the use of blockchains that contain transaction history of all cryptocurrency transactions. These transactions are hashed or crypotograhically encoded into a series of alphanumeric numbers. Hashing involves taking a string of data of any length and running it through a hashing algorithm to produce a output of fixed length. Each block will contain the hash of the previous block header, similarly to our sha-512 algorithm. The mining section of this involves the use of computers to run hashing algorithms to process the most recent block; the information that a user needs to mine is stored in the block header. The block header consists of a version number,timestamp, the hash used in the previous block, the hash of the Merkle Root, the nonce value and the target hash. This block was generated by taking the hash of the block contents, adding a random string of numbers to it (nonce) and hashing the whole block again. If the block meets the requirements of the target i,e is below the target value then the block is added to the blockchain and then whoever made this block will be rewarded it and paid in in crypto.
The issue is that as the requirement of the hash becomes more complicated, as the valid hash needs to be below a certain value, the more repetitions the miners will need to go through on that hash function in order to get an acceptable result. It is possible to get lucky as the numbers are randomly generated and be rewarded but this is uncommon now as over time as the difficulty has increased, the miners need to plug through more nonce values per block on average. Since each hash is generated randomly,it can take millions of guesses or hashes before the target requirement is met but because the chance of getting a valid target are so low it is similar to winning the lottery. The current mining difficulty in 2021 is 23.14 trillion which is highly different then the value 2-4 years ago of 3.51 trillion.
This means it currently takes 23.14 times the length of time that the original difficulty of mining took which was 1. So lets say if the first ever block took 12 hours to mine on a consumer machine of today, that means that the current valid hash would take 23.14 trillion * 12 hours to mine, i.e three hundred ninety billion years. This is why bitcoin mining is often done in pools / clusters using special machines that far exceed the hashing ability's of a consumer machine. There are full warehouses full of these machines that can mine 10-100's of times faster then the average consumer machine, just to try get to the next valid value and these machines run 24 hours a day everyday and cost a huge amount of electricity to run, not to mention the potential for a machine's hardware to break is highly increased as the machines degrade quickly over time by being ran at 100% of their capacity.

### Back to the original question
So back to the original question of "How difficult is it to find a hash digest beginning with at least twelve zeros" if we take the calculations used within cryptocurrencies mining and adjust it for SHA-512 we can get an actual length of time it would take to get to this value if not by luck.

If we take the bitcoin mining algorithm of target/max512(sha512) and the reciprocal of the probability and divide that by the hashrate which in this case we will use that of average laptop hardware i.e 100k.

Then the maths comes out as follows

```text 
Target = maximum sha512 hex value with 12 leading 0's in decimal form 
============================
4.76 x 10 ^ 139

Maximum SHA-512 hash in decimal in decimal form
============================
1.34 x 10 ^ 154

Calculate probability
============================
 (4.76 x 10 ^ 139) / (1.34 x 10 ^ 154) 
============================
3.55 x 10 ^ -15

Reciprocal Division
=============================
1 / (3.55 x 10 ^ -15)
=============================
 = 2.81 x 10 ^ 14

Average Computer Hashing 100k
=============================
(2.81 x 10 ^ 14) / 100000
=============================
= 2810000000 seconds

ANS: It would take roughly 2810000000 Seconds to calculate the hash value through brute forcing methods on a average consumer based pc released in 2017 and not luck of the draw which equates to 91.357.. years. 


```

As shown above the chance of a average user or consumer who is not invested in heavy duty crypto / hashing machines or has their own personal quantum computer, it would take a life time to calculate a SHA-512 hash starting with 12 0's using brute force methods and that is if your hardware had not failed somehow in 91 years. 
For reference it would take a CoinTerra TerraMiner IV mining machine 17 seconds as it does 1,600,000 Mhash/s M standing for million.







# Sources
1. Secure Hash Standard by NIST - https://www.nist.gov/publications/secure-hash-standard

2. Secure Hash Algorithms - https://en.wikipedia.org/wiki/Secure_Hash_Algorithms

3. Build-Essential Package Debian - https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/

4. GCC GNU Compiler - https://gcc.gnu.org/

5. Clangd - https://clangd.llvm.org/

6. GNU Make Files - https://www.gnu.org/software/make/manual/html_node/Introduction.html

7. Make File Support - http://manpages.ubuntu.com/manpages/cosmic/man1/make.1.html

8. Secure Hash Algorithms by Brilliant - https://brilliant.org/wiki/secure-hashing-algorithms/

9. Hexadecimal Wikipedia - https://simple.wikipedia.org/wiki/Hexadecimal

10. Collision Attack - https://en.wikipedia.org/wiki/Collision_attack
 
11. Preimage Attack - https://en.wikipedia.org/wiki/Preimage_attack
12. Pipeline Implementation of Secure Hash Algorithm (SHA-l)for  Cryptographic Application in Network Security - https://core.ac.uk/download/pdf/11786346.pdf

13. Bitcoin - https://bitcoin.org/en/
14. Bitcoin : A simple idea with complications - https://www.cybersecurityintelligence.com/blog/blockchain---a-simple-idea-with-complications--5073.html
15. Bitcoin Nonce Definition by Investopedia - https://www.investopedia.com/terms/n/nonce.asp
16. How Bitcoin Mining works by FreeCodeCamp - https://www.freecodecamp.org/news/how-bitcoin-mining-really-works-38563ec38c87/
17. Stack Exchange Mining Difficulty and Leading Zeros - https://bitcoin.stackexchange.com/questions/85896/mining-difficulty-and-leading-zeros
18. Quantum Computing by Wikipedia - https://en.wikipedia.org/wiki/Quantum_computing
19. 1000 Qubit PC by IBM - https://www.sciencemag.org/news/2020/09/ibm-promises-1000-qubit-quantum-computer-milestone-2023
20. Nella Ludlow - Forbes - https://www.forbes.com/sites/cognitiveworld/2019/02/24/why-quantum-computings-time-is-now/
21. Roger Huang Forbes - https://www.forbes.com/sites/rogerhuang/2020/12/21/heres-why-quantum-computing-will-not-break-cryptocurrencies/

22. SHA-1 is a Shambles: First Chosen-Prefix Collision on SHA-1 and Application to the PGP Web of Trust - https://www.usenix.org/system/files/sec20-leurent.pdf

23. Target - The number you need to get below to mine a block by learnmeabitcoin.com https://learnmeabitcoin.com/technical/target
