<details> <summary> Creating your own oscillator/effect </summary>

This is more complicated especially when you're operating on Windows as me. 

# STEP 0 - MSYS
For start let's install [MSYS2](https://www.msys2.org/) 

Open the link and follow the instructions from the site. 

# STEP 1 - Clone repo
Open Git Bash and navigate to home folder of msys installation. 
```
cd c:/msys64
```
Then clone repo.
```
git clone https://github.com/korginc/logue-sdk.git
```
# STEP 3 - Initialize and update modules 

Navigate into cloned repo folder 

``` 
cd logue-sdk
```
and initialize it by running the command 
```
git submodule update --init
```
# STEP 4 GNU Compiler Collection
Open Mintty (MSYS) <img src = mintty>
run 
```
pacman -S unzip
```
Navigate to gcc folder in cloned repo 
```
cd logue-sdk/tools/gcc
```
and run command 
```
./get_gcc_msys.sh
```
# STEP 5 GNU Make 
It will allow to create a .prlgunit file that we will transfer into our little synth. 
```
pacman -S make
```

# STEP 6 Info-Zip 
Mintty provides Info-zip 3.0
```
pacman -S zip
```

*We could also install the Logue CLI but we're using Librarian so no need. *

# STEP 7 Prepared package 
Since I am following the instructions from Korg site 

I will help myself with already prepared package by guys from DOTEC-AUDIO

1. Download [bitcrusher effect](https://www.korg.com/us/support/download/others/0/832/4743/) 
2. Unzip folder
3. Copy it to logue-sdk/platform/nutekt-digital
