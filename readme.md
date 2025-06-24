# 🔗 Pipex

`pipex` is a system-level programming project in the 42 curriculum. It focuses on using pipes, process forking, and file descriptor redirection to mimic shell behavior in executing a series of commands.

## 📚 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [File Structure](#-file-structure)
- [Subject Breakdown](#-subject-breakdown)
- [License](#-license)
- [Subject PDF](#-subject-pdf)

## 📖 Overview

The `pipex` project challenges you to reproduce a simplified shell pipeline execution using C. You must handle file I/O redirection, process creation, and inter-process communication through pipes.

Example:

```bash
< infile cmd1 | cmd2 > outfile
```

Your program must behave similarly to the shell when executing this sequence.

## ✨ Features

- ✅ Execute multiple commands connected by pipes
- ✅ Handle input and output redirection with files
- ✅ Use `fork`, `dup2`, `execve`, and `pipe`
- ✅ Parse environment variables to find executable paths
- ✅ Handle error messaging and proper exit codes

## ⚙️ Installation

```bash
git clone https://github.com/adil-ech/pipex
cd pipex
make
```

This will compile the `pipex` executable.

## 🚀 Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

## 📁 File Structure

```
pipex/
├── src/
│   ├── main.c
│   ├── pipex.c
│   ├── execute.c
│   ├── path_utils.c
│   ├── error.c
├── include/
│   └── pipex.h
├── libft/               # Custom libft
├── Makefile
```

## 📄 Subject Breakdown

### ✅ Mandatory Part

- Manage file descriptors for input/output
- Create pipes and fork processes
- Use `execve` to launch commands
- Implement proper path resolution using `PATH` env
- Handle all possible errors gracefully (file not found, permission denied, etc.)

### ❌ Bonus Part

*Not implemented in this version.*

## 📬 License

This project is part of the 42 Network curriculum and is intended for educational use only.

## 📄 Subject PDF

You can read the official 42 Pipex subject here:\
👉 [Get\_next\_line Subject PDF](./en.subject.pdf)

