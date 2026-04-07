# 🐺 cub3D

> *My own 3D game engine, built from scratch in C using raycasting mathematics. A tribute to the legendary Wolfenstein 3D.*

## 💡 About The Project

`cub3D` is a graphics and mathematics project that challenges you to create a realistic 3D graphical representation from a 2D map. To achieve this, the project relies on **Raycasting**, the exact same rendering technique used in the 1992 classic, *Wolfenstein 3D*.

The program reads a `.cub` configuration file containing texture paths, floor/ceiling colors, and a 2D grid map. It then calculates the distance from the player to the walls in the user's field of view and renders vertical stripes of pixels to create the illusion of a 3D environment. 

> **Note on Timeline:** I built this rendering engine roughly one year ago as I advanced through the graphics branch of the 42 curriculum. I am archiving it here on this new GitHub profile to showcase my ability to translate complex mathematical logic into functional software.

## 🧠 Key Concepts Learned

* **Raycasting Mathematics:** Utilizing trigonometry, vectors, and the Digital Differential Analysis (DDA) algorithm to calculate ray intersections with grid lines efficiently.
* **Texture Mapping:** Calculating the exact pixel on a 2D image (texture) that corresponds to a specific point on the 3D wall to render brick, stone, or wood realistically.
* **MiniLibX API:** Deepening my knowledge of window management, keyboard/mouse hooks, and pushing massive arrays of pixels (images) to the screen frame-by-frame without lagging.
* **Parsing & Validation:** Extracting complex scene data from a file, validating colors (RGB), loading images, and ensuring the 2D map is strictly closed by walls to prevent rendering errors or segmentation faults.

## 🚀 Getting Started

### Prerequisites
* A C compiler (e.g., `gcc` or `clang`)
* `make`
* Math library (`-lm`)
* **MiniLibX Dependencies:** Depending on your OS, you may need X11 libraries (like `libxext-dev` and `libx11-dev` on Linux).

