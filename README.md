# xv6 User Mode Find Program

This project is a user-mode implementation of a simple `find` command running on the xv6 operating system. The program uses a recursive approach to find all files with a specific name in a directory tree.

## Usage

The program can be executed as follows:
```sh
find <directory> <filename>
```
For example, to search for the file `test.txt` inside the `/home/user` directory:
```sh
find /home/user test.txt
```
This command searches for files named `test.txt` within the specified directory and its subdirectories and prints the found file paths to the screen.

## Installation and Compilation

1. To compile in the xv6 environment:
```sh
make clean
make qemu
```
2. Ensure that the following line is added to the Makefile to enable execution:
```Makefile
UPROGS += _find
```

## File Descriptions

- `user/find.c`: Source code of the `find` command.
- `Makefile`: Modified Makefile for compiling the program.
- `README.md`: This file, containing project descriptions.

## Notes

- The program uses `strcmp()` to compare file names.
- The directories `.` and `..` should be ignored.
- Since it runs on xv6, it cannot be executed in Linux or Windows environments.

## Contributing

If you want to contribute to the project, follow these steps to open a **pull request**:
```sh
git clone https://github.com/username/xv6-find-program.git
cd xv6-find-program
git checkout -b new-feature
# Make your changes and commit them
git push origin new-feature
```
Then, you can submit a **pull request** via GitHub.

## License
This project is shared in accordance with the xv6 licensing terms.

---
Feel free to reach out if you have any questions! 😊

