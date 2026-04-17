# GMMK 3 P65 ANSI (Template)

This folder contains a template keyboard definition scaffold for QMK.

## Required before production use

- Confirm MCU/bootloader values in `../info.json`
- Define real matrix pins in `../config.h`
- Validate `keyboard.json` layout and matrix mapping against PCB
- Verify USB IDs and lighting drivers match hardware

Once hardware definitions are correct, build with:

```bash
qmk compile -kb gmmk/gmmk3/p65/ansi -km vial
```
