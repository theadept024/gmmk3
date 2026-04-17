# Enable Vial + VIA dynamic keymaps
VIA_ENABLE = yes
VIAL_ENABLE = yes

# Encoder is disabled in scaffold builds until real encoder pins are known.
ENCODER_ENABLE = no
ENCODER_MAP_ENABLE = no

# Lighting is disabled in scaffold builds until board-specific LED driver data is known.
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

# Keep common QMK features on for a practical baseline
LTO_ENABLE = yes
NKRO_ENABLE = yes
