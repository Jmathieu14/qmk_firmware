import unittest

from custom.keyboard_switch_layout import KeyboardSwitchLayout


class KeyboardSwitchRowTest(unittest.TestCase):

    def test_init_switch_row_throws_no_error__on_value_one_or_greater(self):
        valid_switch_layout = KeyboardSwitchLayout(5)
        self.assertEquals(valid_switch_layout.rows, 5)

    def test_validate_count_throws_error_on_value_less_than_one(self):
        with self.assertRaises(ValueError):
            KeyboardSwitchLayout(0)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(KeyboardSwitchRowTest)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
