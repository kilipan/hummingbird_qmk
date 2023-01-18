# hummingbird

![hummingbird](https://github.com/PJE66/hummingbird/blob/main/Images/Hummingbird_Top.png?raw=true)

*A 30-key split-unibody column-stagger keyboard.*  
**IMPORTANT: This firmware is only suitable for the Seeed Xiao RP2040 MCU!**
If you would like to use a different MCU, please consider using ZMK firmware.

* Keyboard Maintainer: [kilipan](https://github.com/kilipan)
* Hardware Supported: *Hummingbird keyboard with Seeed Studio Xiao RP2040 Controller*
* Hardware Availability: [*The creator's github page*](https://github.com/PJE66/hummingbird)

Make example for this keyboard (after setting up your build environment):

    make hummingbird:default

Flashing example for this keyboard:

    make hummingbird:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Default keymap
The default keymap is set to Colemak (mod DH) with the Z, V, K, and / keys missing. They are reacheable via combos of the nearest two buttons in the bottom row.
Please consult the [keymap file](https://github.com/kilipan/hummingbird_qmk/blob/main/keymaps/default/keymap.c) for further details.

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Press the reset button (labelled "R") while holding down the bootloader button (labelled "B")
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (hold right button of the right thumb and press the top button of the left ring finger
