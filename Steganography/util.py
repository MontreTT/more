
def toTXT(data):
	with open("secret_file_out.txt",'w+') as out:
		out.write(data)

def frombits(bits):
    chars = []
    for b in range(int(len(bits) / 8)):
        byte = bits[b*8:(b+1)*8]
        chars.append(chr(int(''.join([str(bit) for bit in byte]), 2)))
    return ''.join(chars)


def getLSB(val):
	return (val%2)

def readTXT(filename):
	with open(filename,'r',encoding="utf8") as file:
		data = file.read()
	return data

def readIMG(filename):
	with io.open(filename,'r',encoding="utf8") as file:
		data = file.read()
	return data



def tobits(s):
    result = []
    for c in s:
        bits = bin(ord(c))[2:]
        bits = '00000000'[len(bits):] + bits
        result.extend([int(b) for b in bits])
    return result


def addint(val,bit):
	if (val%2 == 1):
		if (bit == 0):
			val = val - 1
	else:
		if (bit == 1):
			val = val + 1
	return val



def toJPG(data):
	with io.open("secret_file_out.png",'w+', encoding="utf-8") as out:
		out.write(data)


def toJPG(data):
	with io.open("secret_file_out.png",'w+', encoding="utf-8") as out:
		out.write(data)

