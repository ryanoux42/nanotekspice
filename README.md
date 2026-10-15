# 🔌 NANOTEKSPICE

## Description

**NANOTEKSPICE** is a **digital electronics simulator** written in **C++**, inspired by [SPICE](https://en.wikipedia.org/wiki/SPICE).

The program reads a **circuit description file** (`.nts`) made of components and the links between their pins, builds the circuit graph, and lets the user **set inputs**, **run simulation ticks** and **display outputs** from an interactive shell.

Every component works with **tri-state logic**: `0` (false), `1` (true) and `U` (undefined).

This project focuses on **object-oriented design** in C++: **interfaces**, **abstract classes**, **inheritance**, the **factory pattern**, **smart pointers** and **exceptions**.

---

## 🏗️ Architecture

```
IComponent            (interface)
   └── AComponent     (abstract class: name, pins, links)
         ├── Special      → input, output, clock, true, false
         ├── Elementary   → and, or, xor, not
         ├── Gates        → 4001, 4011, 4030, 4069, 4071, 4081
         └── Advanced     → 4008, 4013, 4512, ...
```

- **`ComponentFactory`** creates components by type name (`std::unique_ptr<IComponent>`)
- **`Parser`** reads the `.nts` file and validates `.chipsets:` and `.links:`
- **`Circuit`** owns the components, runs the simulation and the interactive shell

---

## 🧩 Supported Components

| Type | Components |
|------|-------------|
| Special | `input`, `output`, `clock`, `true`, `false` |
| Elementary | `and`, `or`, `xor`, `not` |
| Gates | `4001` (4 NOR), `4011` (4 NAND), `4030` (4 XOR), `4069` (6 NOT), `4071` (4 OR), `4081` (4 AND) |
| Advanced | `4008` (4-bit adder), `4013` (dual D flip-flop), `4512` (8-channel selector) |

> Work in progress (in `src/AdvancedComponent`, not wired into the build): `4017`, `4040`, `4094`, `4514`, `4801`, `2716`, `logger`.

---

## ⚙️ Usage

### Compilation

```bash
make
```

> Builds on Linux with `g++` (C++20).

Other rules:
```bash
make re      # Rebuild everything
make clean   # Remove object files
make fclean  # Remove binaries and object files
```

---

### Execution

```bash
./nanotekspice circuit.nts
```

### Shell commands

| Command | Description |
|---------|-------------|
| `display` | Print the current tick, all inputs and all outputs |
| `<input>=<value>` | Set an input or clock to `0`, `1` or `U` (applied at next simulation) |
| `simulate` | Run one tick of the simulation |
| `loop` | Simulate continuously until `Ctrl+C` |
| `exit` | Quit the program |

---

## 📄 Circuit File Format

```
# AND gate
.chipsets:
input in_1
input in_2
and gate
output out

.links:
in_1:1 gate:1
in_2:1 gate:2
out:1 gate:3
```

- `.chipsets:` → `<type> <name>`
- `.links:` → `<name>:<pin> <name>:<pin>`
- `#` → comment

### Example session

```
$ ./nanotekspice and.nts
> display
tick: 0
input(s):
  in_1: U
  in_2: U
output(s):
  out: U
> in_1=1
> in_2=1
> simulate
> display
tick: 1
input(s):
  in_1: 1
  in_2: 1
output(s):
  out: 1
> exit
```

---

## 🫂 Team

- Ryan Hercule
- Jean-Garice Denoncin
