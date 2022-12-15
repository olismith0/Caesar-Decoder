# Ceasar Decoder

This c++ application is used to decrypt a given .txt which includes Ceaser Cipher Encrypted text. The application performs letter and word analysis to suggest the key in which the encrypted text has been encrypted with.

---

## Prerequisites

In order to compile this application you will need to install:

- g++

This can be installed with `$ sudo apt-get install g++`

---

## Setup

In order to view this applications source code locally, you can either download the .zip or run the command:

```bash
$ git clone https://github.com/olismith0/Caesar-Decoder.git
```

After downloading the code you will have to compile the code with the prerequisite g++.

```bash
$ g++ caesar_os.cpp enc_library_os.cpp –o caesar_os
```

This will create and executable file called `caesar_os`

To run the created executable you have to pass it two arguments:

- The encrypted text document, I have provided one in this repository. 
- The name of the Text File which will include the decrypted text.

```bash
./caesar_os example_encrypted_text.txt decrypted_text.txt
```
---
# Author
Name: Oli Smith

University Email: w20000418@northumbria.ac.uk

University ID: w20000418