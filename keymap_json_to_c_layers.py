import simplejson as j


def file_to_json_obj(filename) -> dict:
    with open(filename, 'r') as my_file:
        my_str = my_file.read()
    my_in = j.loads(my_str)
    return my_in


def json_layer_to_c_layer(layer: dict, layer_i: int, row_len=12) -> str:
    str_to_print = '[' + layer_i.__str__() + '] = LAYOUT( \\\n'
    for i in range(0, layer.__len__()):
        str_to_print += layer[i]
        if i != layer.__len__() - 1:
            str_to_print += ', '
        if (i + 1) % row_len == 0:
            str_to_print += '\ \n'
    return str_to_print + ')'


def json_file_to_c_layers(filepath: str):
    json_obj = file_to_json_obj(filepath)
    print('const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {\n')
    if 'layers' in json_obj.keys():
        layer_i = 0
        for layer in json_obj['layers']:
            layer_as_str = json_layer_to_c_layer(layer, layer_i)
            if layer_i != json_obj['layers'].__len__() - 1:
                layer_as_str += ','
            layer_as_str += '\n'
            print(layer_as_str)
            layer_i = layer_i + 1
    print('};')


def main():
    json_file_to_c_layers("layouts/personal/prime_e/prime_e_jm_plus_game.json")


if __name__ == '__main__':
    main()
