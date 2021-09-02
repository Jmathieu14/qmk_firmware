class KeyboardSwitchRow:
    def __init__(self, switch_count):
        self.switch_count = switch_count

    def __str__(self):
        return "row switch count: {0}".format(self.switch_count)


class KeyboardSwitchLayout:
    def __init__(self, rows):
        self.rows = rows

    def __str__(self):
        rows_string = ""
        for row in self.rows:
            rows_string = "{0}\n{1}".format(rows_string, row)
        return rows_string


row_one = KeyboardSwitchRow(4)
row_two = KeyboardSwitchRow(5)

demo_switch_layout = KeyboardSwitchLayout([row_one, row_two])

print(demo_switch_layout)
