# Babylon Shelf

This is a silly project that imitates Library of Babel. Python and C++ versions are present.

# How to run it?

1. Copy the repository:

```
git clone https://github.com/Aleph017/Babylon-Shelf
```
2. Change directory to the copied repository:

```
cd Babylon-Shelf
```

## Python version
Simply run it with `python`:

```
python source_code.py
```

## C++ version
1. Compile with `g++` and rename the binary, e.g. `shelf`:

```
g++ source_code.cpp -o shelf
```

2. Run the binary:

```
shelf [-r|-q] [word to find]
```

# What does it do?

It asks the user a word to find and then generates random "words" until the generated one is identical to user's word.

Python version is very slow, because it's Python, and it's not very advanced.

I've spent a little bit more time working on C++ version, so there are 2 flags:
  * `-r || --russian` if you ever want to see russian text or find a russian word
  * `-q || --quiet` if you don't want the program to print in output while it searches your word

And also you can specify the word to look for from CLI:
`shelf [one flag] [your word]`
