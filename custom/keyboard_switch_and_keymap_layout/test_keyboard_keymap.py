import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardKeymap


class TestKeyboardKeymap(unittest.TestCase):
    def test_get_min_keycode_length__returns_6(self):
        keymap_list = [
            "KC_ESC", "KC_7", "KC_6",
            "KC_5", "KC_4", "KC_3",
            "KC_2", "KC_1"
        ]
        keymap = KeyboardKeymap("layer_1", keymap_list)
        self.assertEqual(keymap.get_min_keycode_length(), 6)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeyboardKeymap)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
