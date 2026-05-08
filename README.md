# Sliding Puzzle Game (Taquin)

A C-based implementation of the classic "Taquin" sliding puzzle, featuring a graphical interface and efficient grid manipulation.

## 📂 Project Overview

This project is a digital version of the sliding puzzle (Taquin) developed in C. It handles grid randomization, move validation, and win-condition checking. The game uses a graphical interface powered by the **libMLV** library.

* **Key Concepts:** 2D Arrays, Game Logic, Event Handling, Graphical Rendering.
* **External Library:** libMLV (Multimedia Library).

## 🛠️ Prerequisites

This project requires the **libMLV** library.

### Installing libMLV

You can download the library from the official university website: [http://www-igm.univ-mlv.fr/~borie/libMLV/](https://www.google.com/search?q=http://www-igm.univ-mlv.fr/~borie/libMLV/)

On Linux (Debian/Ubuntu), install it via:

```bash
sudo apt-get install libmlv3-dev

```

## 🚀 Getting Started

### Compilation

The project uses the C99 standard. To compile, run:

```bash
make

```

### Execution

Launch the game with:

```bash
./taquin

```

### Cleaning Up

To remove object files and the executable:

```bash
make clean

```

---

*Developed as part of the ESIEE Paris engineering curriculum.*
