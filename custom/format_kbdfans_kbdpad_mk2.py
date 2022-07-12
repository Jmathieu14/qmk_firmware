from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, KeyboardSwitchLayout
from custom.keyboard_switch_and_keymap_layout.parser.keymap_c_parser import parse_keymap_c


def main():
    four_switch_row = KeyboardSwitchRow(4)
    kbdpad_switch_layout = KeyboardSwitchLayout([four_switch_row, four_switch_row, four_switch_row, four_switch_row, four_switch_row, four_switch_row])
    kbdpad_keymap_filepath = '../keyboards/kbdfans/kbdpad/mk2/keymaps/jmath_custom/keymap.c'
    my_layout = parse_keymap_c(kbdpad_keymap_filepath, kbdpad_switch_layout, 'LAYOUT_ortho_6x4')
    print(my_layout.__str__())


if __name__ == '__main__':
    main()
