import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow


class TestKeyboardSwitchRow(unittest.TestCase):

    def test_init_switch_row_raises_no_error__on_value_one_or_greater(self):
        valid_switch_layout = KeyboardSwitchRow(5)
        self.assertEquals(valid_switch_layout.switch_count, 5)

    def test_validate_count_throws_error_on_value_less_than_one(self):
        with self.assertRaises(ValueError):
            KeyboardSwitchRow(0)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeyboardSwitchRow)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
