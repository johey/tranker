NOTE_NAMES = [ 'C ', 'Cx', 'D ', 'Dx', 'E ', 'F ', 'Fx', 'G ', 'Gx', 'A ', 'Ax', 'B ' ]
def midi_name(number):
  octave = int(number/12)
  name = NOTE_NAMES[number % 12]

  return [name, octave]

def hex8(value):
  alphabet = "0123456789ABCDEF"
  ln = int(value/16)
  rn = value%16
  return alphabet[ln]+alphabet[rn]

