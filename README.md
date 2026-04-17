# Glorious GMMK 3 65% ANSI QMK + Vial Firmware Starter

This repository contains the **keymap/config source files** you need to build a QMK firmware for a GMMK 3 65% ANSI-style layout.

If you're new: this repo is not the full QMK codebase. Think of it as your custom keymap folder + Vial metadata that plugs into a normal `qmk_firmware` checkout.



## Windows quick path (recommended)

Since you are on Windows, use this flow:

1. Install **QMK MSYS** (includes QMK CLI environment).
2. Open **QMK MSYS** terminal (not regular CMD for first setup).
3. Run:
   ```bash
   qmk setup
   ```
4. Your QMK folder is typically under your Windows user profile (for example `C:\Users\<you>\qmk_firmware`).
5. Copy this repo's `vial` folder into:
   `C:\Users\<you>\qmk_firmware\keyboards\gmmk\gmmk3\p65\ansi\keymaps\vial`
6. Compile from QMK MSYS:
   ```bash
   qmk compile -kb gmmk/gmmk3/p65/ansi -km vial
   ```
7. Flash with **QMK Toolbox** on Windows.


## Getting files out of Codex and into your GitHub repo

If your GitHub repository is empty, it usually means this local repo has not been pushed yet.

From a terminal in your local repo:

1. Check remotes:
   ```bash
   git remote -v
   ```
2. If no `origin` (or wrong one), set it:
   ```bash
   git remote add origin https://github.com/<your-user>/<your-repo>.git
   ```
   (or `git remote set-url origin ...` if origin already exists)
3. Push your branch:
   ```bash
   git push -u origin work
   ```
4. On GitHub, switch to branch **work** and you should see the files.

If you want the files on `main`, merge or push to `main` instead after review.

## Where is this repository?

Right now, this repository is a **local folder on the machine** where these commands were run:

`/workspace/gmmk3` (this path exists only inside this assistant's Linux environment)

It is **not automatically on your GitHub account** unless you push it to a remote repository.


If you **can't** find `/workspace/gmmk3` on your computer, that is expected.
Your local path will be different (for example `C:\Users\<you>\...` on Windows or `/Users/<you>/...` on macOS).

If you want it on GitHub:

1. Create an empty repo on GitHub (for example `gmmk3-firmware`).
2. In your local clone, add your GitHub repo as `origin`.
3. Push your branch.

Example commands:

```bash
git remote add origin https://github.com/<your-user>/<your-repo>.git
git push -u origin work
```


### How to find it on *your* machine

If you are in the repo terminal, run:

```bash
git rev-parse --show-toplevel
```

That prints the absolute folder path to this repository.

To print the exact `vial` folder path from the repo root, run:

```bash
realpath keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial
```

If you are using a GUI file browser, open that printed path and navigate to:

`keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial`


### Do I already have a repository terminal?

Not automatically on your personal computer.

- The commands in this session were run in a temporary development environment with its own terminal.
- On your own machine, you need to open your own terminal (PowerShell, Command Prompt, macOS Terminal, Linux shell) and clone/create the repo there.

Quick check on your machine:

```bash
git --version
```

If that works, you have a terminal with Git available. Then you can clone your repo and run the QMK commands from that local terminal.


### If Codex created files, are they automatically on my own PC?

No. The files are created in the Codex working environment first.

To have them on your own Windows machine, you must do one of:

- push this repo to GitHub and clone it locally, or
- download/export the files and place them in your local project folder.

Only after that will the source path exist on your machine for Step 3 copying.

## What is in this repo

- `keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/keymap.c` → your key layout, layers, knob behavior, accent-light controls
- `keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/config.h` → Vial UID/unlock combo + RGB defaults
- `keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/rules.mk` → feature flags (Vial/VIA, encoder, RGB)
- `keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/vial.json` → Vial metadata/layout description

So yes: it includes the **keymap source** and the **Vial JSON**.

## What it does NOT include

- It does not include the entire upstream QMK repository.
- It does not include a prebuilt firmware binary yet (`.bin`, `.hex`, or `.uf2`).

You generate that binary by compiling with QMK.

---

## Beginner quickstart (build + flash)

## 1) Install QMK tools

On Windows, easiest path is **QMK MSYS** (then use `qmk` commands in the QMK MSYS terminal).

General docs:
- https://docs.qmk.fm/newbs_getting_started

## 2) Clone/setup `qmk_firmware`

In QMK MSYS terminal:

```bash
qmk setup
```

This creates/clones a local `qmk_firmware` folder.

## 3) Copy this keymap into QMK

Copy this repo's `vial` folder into:

`qmk_firmware/keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial`

You should end with:

`qmk_firmware/keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/keymap.c`

(and the other three files beside it).


### Where is the `vial` folder in this repo?

In this repository, the folder you need to copy is exactly:

`/workspace/gmmk3/keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial`

If you are browsing files manually, it is:

`keyboards -> gmmk -> gmmk3 -> p65 -> ansi -> keymaps -> vial`

The destination in your local QMK checkout should be:

`<your qmk_firmware path>/keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial`


### Step 3 made explicit (what to copy, from where, to where)

You are copying **one folder named `vial`**.

- **Source folder (where you copy FROM):**
  The `vial` folder inside this project:
  `keyboards\gmmk\gmmk3\p65\ansi\keymaps\vial`

- **Destination folder (where you copy TO):**
  Your local QMK folder:
  `C:\Users\<you>\qmk_firmware\keyboards\gmmk\gmmk3\p65\ansi\keymaps\`

After copy, this must exist on your PC:

`C:\Users\<you>\qmk_firmware\keyboards\gmmk\gmmk3\p65\ansi\keymaps\vial\keymap.c`

In File Explorer, open both folders side-by-side and drag the `vial` folder into the destination `keymaps` folder.


#### If you cannot find the source folder yet

That means this project is not downloaded on your PC yet.

Use one of these options first:

1. **Download ZIP** of this repo and extract it (for example to `C:\Users\<you>\Downloads\gmmk3`).
2. **Clone with Git** into a folder you choose.

After that, your source folder will be inside that downloaded/cloned location:

`<where-you-downloaded-this-project>\keyboards\gmmk\gmmk3\p65\ansi\keymaps\vial`

Example if you extracted to Downloads:

`C:\Users\<you>\Downloads\gmmk3\keyboards\gmmk\gmmk3\p65\ansi\keymaps\vial`

## 4) Compile firmware

From QMK MSYS:

```bash
qmk compile -kb gmmk/gmmk3/p65/ansi -km vial
```

If compile succeeds, QMK prints the output firmware filename and path (for example `.bin` or `.uf2`, depending on the keyboard bootloader target).

## 5) Flash with QMK Toolbox / QMK Launcher

1. Open QMK Toolbox (or your QMK Launcher tool).
2. Load the compiled firmware file from step 4.
3. Put keyboard into bootloader mode (often via reset button or holding a specific key combo while plugging in).
4. Click **Flash**.
5. Replug keyboard and test.

---

## Important before flashing

Because GMMK 3 revisions can differ, verify:

- `LAYOUT(...)` in `keymap.c` matches your board's real layout macro.
- `matrix` in `vial.json` matches the keyboard definition.
- `VIAL_KEYBOARD_UID` is unique for your final distributable firmware.
- USB IDs and bootloader target align with your exact board/revision.

## Current feature coverage

- **Knob support** via `ENCODER_MAP_ENABLE` with per-layer actions.
- **Lighting layer** with RGB Matrix + RGB Light controls.
- **Accent light controls** via custom keys (`AC_TOG`, `AC_HUI`, `AC_HUD`, `AC_VAI`, `AC_VAD`).


## Troubleshooting: `invalid keyboard_folder_or_all value`

If you get:

`qmk.exe compile: error: argument -kb/--keyboard: invalid keyboard_folder_or_all value`

it means your current QMK checkout does not have that keyboard path.

Run this in QMK MSYS to discover the exact available GMMK paths:

```bash
qmk list-keyboards | findstr /I gmmk3
```

Then compile with one of the listed values (example for 65% ANSI):

```bash
qmk compile -kb gmmk/gmmk3/p65/ansi -km vial
```

If `gmmk/gmmk3/...` does not appear at all, you are likely using a QMK checkout/fork that does not include GMMK 3 definitions yet.

