import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, \
    KeyboardSwitchLayout, KeyboardKeymap, KeyboardLayout

nine_key_switch_layout = KeyboardSwitchLayout([
    KeyboardSwitchRow(3),
    KeyboardSwitchRow(3),
    KeyboardSwitchRow(3)
])

uneven_key_switch_layout = KeyboardSwitchLayout([
    KeyboardSwitchRow(1),
    KeyboardSwitchRow(2),
    KeyboardSwitchRow(3)
])

nine_key_layer_list = [
    "KC_8", "KC_7", "KC_6",
    "KC_5", "KC_4", "KC_3",
    "KC_2", "KC_1", "KC_0"
]

long_keycode_list = [
    "KC_8", "KC_7", "KC_6",
    "KC_5", "KC_4", "KC_3",
    "KC_2", "KC_1", "TO(DEFAULT)"
]

uneven_rows_keycode_list = [
    "KC_0",
    "KC_DOT", "KC_RGHT",
    "KC_1", "KC_2", "KC_3"
]
nine_key_layer = KeyboardKeymap("layer_1", nine_key_layer_list)
nine_key_keyboard_layout = KeyboardLayout(nine_key_switch_layout, [nine_key_layer])
long_keycode_layer = KeyboardKeymap("layer_with_one_long_keycode", long_keycode_list)
long_keycode_keyboard_layout = KeyboardLayout(nine_key_switch_layout, [long_keycode_layer])
uneven_keycode_layer = KeyboardKeymap("uneven_layer", uneven_rows_keycode_list)
uneven_keyboard_layout = KeyboardLayout(uneven_key_switch_layout, [uneven_keycode_layer])


class TestKeyboardLayout(unittest.TestCase):
    def test_init_with_invalid_input__raises_error(self):
        eight_key_layer_list = [
            "KC_8", "KC_7", "KC_6",
            "KC_5", "KC_4", "KC_3",
            "KC_2", "KC_1"
        ]
        eight_key_layer = KeyboardKeymap("layer_1", eight_key_layer_list)
        with self.assertRaises(ValueError) as error:
            KeyboardLayout(nine_key_switch_layout, [eight_key_layer])
        self.assertEqual(error.exception.__str__(), "Layer layer_1 has 8 keycodes on a board with 9 switches")

    def test_init_with_valid_input__does_not_raise_error(self):
        self.assertIsNotNone(nine_key_keyboard_layout)

    def test_min_keycode_length_for_second_column__returns_4(self):
        col_index = 1
        self.assertEqual(4, nine_key_keyboard_layout.min_keycode_length_for_column(col_index, nine_key_layer))

    def test_min_keycode_length_for_last_column__returns_11(self):
        col_index = 2
        self.assertEqual(11, long_keycode_keyboard_layout.min_keycode_length_for_column(col_index, long_keycode_layer))

    def test_min_keycode_length_for_first_column_in_uneven_layout__returns_6(self):
        col_index = 0
        self.assertEqual(6, uneven_keyboard_layout.min_keycode_length_for_column(col_index, uneven_keycode_layer))

    def test_min_keycode_length_for_last_column_in_uneven_layout__returns_7(self):
        col_index = 1
        self.assertEqual(7, uneven_keyboard_layout.min_keycode_length_for_column(col_index, uneven_keycode_layer))

    def test_layer_as_string__returns_expected_string_for_layer_1(self):
        actual = nine_key_keyboard_layout.layer_as_string(0)
        expected = '\n[layer_1] = LAYOUT( \\\n' \
                   'KC_8, KC_7, KC_6, \\\n' \
                   'KC_5, KC_4, KC_3, \\\n' \
                   'KC_2, KC_1, KC_0)'
        self.assertEqual(actual, expected)

    def test_layer_as_string__returns_expected_string_for_layer_with_one_long_keycode(self):
        actual = long_keycode_keyboard_layout.layer_as_string(0)
        expected = '\n[layer_with_one_long_keycode] = LAYOUT( \\\n' \
                   'KC_8, KC_7, KC_6       , \\\n' \
                   'KC_5, KC_4, KC_3       , \\\n' \
                   'KC_2, KC_1, TO(DEFAULT))'
        self.assertEqual(actual, expected)

    def test_layer_as_string__returns_expected_string_for_uneven_keyboard_layout(self):
        actual = uneven_keyboard_layout.layer_as_string(0)
        expected = '\n[uneven_layer] = LAYOUT( \\\n' \
                   'KC_0  , \\\n' \
                   'KC_DOT, KC_RGHT, \\\n' \
                   'KC_1  , KC_2   , KC_3)'
        self.assertEqual(actual, expected)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeyboardLayout)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
