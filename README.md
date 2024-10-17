# SDL Experiments

Built on Debian 12.

---

Simple projects to practice SDL2:
- simple_triangle_exe - just drawing one triangle
- key_mouse_control_exe - if key is pressed, then print this key to standard output; if mouse is used, then draw rectangle bounded by mouse.

To build these projects, you can run the script `bash format_and_build.sh`. It first formats the code using [.clang-format](.clang-format), then builds all projects using CMake and Makefile in the build/ directory.