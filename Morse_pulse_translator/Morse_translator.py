import serial
morse_dictionary = {".-": "a",
              "-...": "b",
              "-.-.": "c",
              "-..": "d",
              ".": "e",
              "..-.": "f",
              "--.": "g",
              "....": "h",
              "..": "i",
              ".---": "j",
              "-.-": "k",
              ".-..": "l",
              "--": "m",
              "-.": "n",
              "---": "o",
              ".--.": "p",
              "--.-": "q",
              ".-.": "r",
              "...": "s",
              "-": "t",
              "..-": "u",
              "...-": "v",
              ".--": "w",
              "-..-": "x",
              "-.--": "y",
              "--..": "z",

              }


# The length of a dot is 1 time unit.
# A dash is 3 time units.
# The space between symbols (dots and dashes) of the same letter is 1 time unit.
# The space between letters is 3 time units.
# The space between words is 7 time units.

phrase = []
def translate_morse(morse_list):
    morse_phrase = "".join(morse_list)

    if morse_phrase in morse_dictionary:
        phrase.append(morse_dictionary[morse_phrase])
    print("".join(phrase))

def pulse_to_morse(pulse_list):
    morse_list = []

    while len(pulse_list) != 0:
        if pulse_list[0] == 1 and pulse_list[1] == 0:
            morse_list.append(".")
            pulse_list.pop(0)
        elif pulse_list[0] == 1 and pulse_list[1] == 1:
            morse_list.append("-")
            pulse_list.pop(0)
            pulse_list.pop(0)
        elif pulse_list[0] == 0 and pulse_list[1] == 1:
            pulse_list.pop(0)
        elif pulse_list[0] == 0 and pulse_list[1] == 0:
            pulse_list.pop(0)
            pulse_list.pop(0)
            print(morse_list)
            translate_morse(morse_list)

def creating_morse_list():

    pulse_list = []
    data = serial.Serial('com6', 9600)
    zero_count = 0
    one_count = 0


    ext = False
    while ext is False:
        pulse = int(data.readline().decode('ascii'))

        # print(one_count)
        # print(zero_count)
        if one_count > 20:
            print("".join(phrase))
            ext = True
        if pulse == 0:
            zero_count += 1
            one_count = 0
        elif pulse == 1:
            one_count += 1
            zero_count = 0
        if pulse == 1 and one_count == 1 or pulse == 1 and one_count == 3:
            pulse_list.append(pulse)
            print(pulse_list)

        elif pulse == 0 and zero_count == 1 or pulse == 0 and zero_count == 6 or pulse == 0 and zero_count == 12:
            pulse_list.append(pulse)
            print(pulse_list)
            if zero_count == 6:
                pulse_to_morse(pulse_list)
            if zero_count == 12:
                print("New word")
                phrase.append(" ")

creating_morse_list()


