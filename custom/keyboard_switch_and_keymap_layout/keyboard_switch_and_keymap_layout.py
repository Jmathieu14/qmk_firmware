def get_x_spaces(x: int):
    string_of_spaces = ''
    for i in range(0, x):
        string_of_spaces = string_of_spaces + ' '
    return string_of_spaces


def pad_string_to_length(my_str, required_length):
    if my_str.__len__() < required_length:
        spaces_to_add = required_length - my_str.__len__()
        return '{0}{1}'.format(my_str, get_x_spaces(spaces_to_add))
    return my_str


class KeyboardSwitchRow:
    def __init__(self, switch_count):
        self.switch_count = switch_count
        self._validate_count()

    def _validate_count(self):
        if self.switch_count <= 0:
            raise ValueError("Invalid switch count of {0} provided".format(self.switch_count))

    def __str__(self):
        return "row switch count: {0}".format(self.switch_count)


class KeyboardSwitchLayout:
    def __init__(self, rows: list[KeyboardSwitchRow]):
        self.rows = rows

    def total_switch_count(self):
        total_count = 0
        for row in self.rows:
            total_count = total_count + row.switch_count
        return total_count

    def get_largest_row_size(self):
        largest_row_size = self.rows[0].switch_count
        if self.rows.__len__() > 1:
            for i in range(1, self.rows.__len__()):
                largest_row_size = max(largest_row_size, self.rows[i].switch_count)
        return largest_row_size

    def __str__(self):
        rows_string = ""
        for row in self.rows:
            rows_string = "{0}\n{1}".format(rows_string, row)
        return rows_string


class KeyboardKeymap:
    def __init__(self, name: str, key_codes: list[str]):
        self.name = name
        self.key_codes = key_codes

    def get_min_keycode_length(self):
        min_length = 0
        for key_code in self.key_codes:
            if key_code.__len__() > min_length:
                min_length = key_code.__len__()
        return min_length


class KeyboardLayout:
    def __init__(self, switch_layout: KeyboardSwitchLayout, keymap_layers: list[KeyboardKeymap]):
        self.switch_layout = switch_layout
        self.keymap_layers = keymap_layers
        self._validate_input()

    def _validate_input(self):
        for layer in self.keymap_layers:
            if not layer.key_codes.__len__() == self.switch_layout.total_switch_count():
                raise ValueError("Layer {0} has {1} keycodes on a board with {2} switches"
                                 .format(layer.name, layer.key_codes.__len__(), self.switch_layout.total_switch_count()))

    def min_keycode_length_for_column(self, column_index, layer: KeyboardKeymap):
        rows = self.switch_layout.rows
        min_length = layer.key_codes[0].__len__()
        switch_index = column_index
        for i in range(0, rows.__len__()):
            max_index = rows[i].switch_count - 1
            if column_index <= max_index:
                keycode = layer.key_codes[switch_index]
                min_length = max(min_length, keycode.__len__())
            switch_index = switch_index + max_index + 1
        return min_length

    def get_min_keycode_length_per_column_for_layer(self, layer: KeyboardKeymap):
        min_keycode_lengths = []
        largest_row = self.switch_layout.get_largest_row_size()
        for i in range(0, largest_row):
            min_keycode_lengths.append(self.min_keycode_length_for_column(i, layer))
        return min_keycode_lengths

    def layer_as_string(self, layer_index: int):
        layer: KeyboardKeymap = self.keymap_layers[layer_index]
        string_to_return = '\n\t[{0}] = LAYOUT( \\\n'.format(layer.name)
        num_rows = self.switch_layout.rows.__len__()
        rows = self.switch_layout.rows
        key_code_index = 0
        min_keycode_lengths = self.get_min_keycode_length_per_column_for_layer(layer)
        for row_index in range(0, num_rows):
            for switch_index in range(0, rows[row_index].switch_count):
                min_keycode_length = min_keycode_lengths[switch_index]
                my_keycode = pad_string_to_length(layer.key_codes[key_code_index], min_keycode_length)
                tab_str = '\t\t' if switch_index == 0 else ''
                if row_index == num_rows - 1 and switch_index == rows[row_index].switch_count - 1:
                    string_to_return = '{0}{1}{2})'.format(string_to_return, tab_str, my_keycode)
                elif switch_index == rows[row_index].switch_count - 1:
                    string_to_return = '{0}{1}{2}, \\\n'.format(string_to_return, tab_str, my_keycode)
                else:
                    string_to_return = '{0}{1}{2}, '.format(string_to_return, tab_str, my_keycode)
                key_code_index = key_code_index + 1
        return string_to_return

    def __str__(self):
        keyboard_layout_as_string = "const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {\n"
        for layer_index in range(0, self.keymap_layers.__len__()):
            layer_string = self.layer_as_string(layer_index)
            if layer_index != self.keymap_layers.__len__() - 1:
                layer_string = layer_string + ","
            keyboard_layout_as_string = "{0}{1}\n".format(keyboard_layout_as_string, layer_string)
        return keyboard_layout_as_string + "\n};"
