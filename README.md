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

C'est intéressant de noter que pour ce projet, contrairement au Sudoku qui utilisait `-ansi`, tu utilises ici la norme **C99**. Cela t'a probablement permis d'utiliser des fonctionnalités plus modernes, comme les déclarations de variables dans les boucles `for` ou le type `bool`. C'est une bonne pratique de le mentionner car cela montre que tu maîtrises différentes normes du langage C.
