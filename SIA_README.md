# How to use this

1. load the ergodox ez keymap json in ./keyboards/ergodox_ez/keymaps/sia/keymap.json into https://config.qmk.fm/
2. make modifications to it there & download it back into ./keyboards/ergodox_ez/keymaps/sia/keymap.json
3. modify ./users/sia/keymap.c and ./users/sia/keymap.h if making changes to custom code/symbols
4. run ./util/docker_build.sh ergodox_ez:sia
5. load teensy loader (v1.52 known to work with my ergodox_ez)
6. load the .hex file and hit go
