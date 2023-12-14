
from PIL import Image
import sys
sys.path.append('..')
from util import *


def main():

	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Image File')
	 
	imf = sys.argv[1]

	print(f'Decoding {imf} ...')


	im = Image.open(imf) # Open Image
	pix = im.load()				# Read Image RGB Values
	width, height = im.size

	print('File format :' ,im.format, im.size, im.mode)



	bitlist = []
	i = 0
	for w in range(width):
		for h in range(height):
			for c in range(3):
				bit = getLSB(pix[w,h][c])
				#print (pix[w,h])
				bitlist.append(bit)

				i = i +1

			endstring = ''
			endstring = frombits(bitlist[-144:])
			
				#print (endstring)
			if(endstring =='!)NF@^&I^U%$&T&#@&'): break
		if(endstring=='!)NF@^&I^U%$&T&#@&'): break

	

	print ("Done!")

	data = frombits(bitlist[:-144])
	toTXT(data)


if __name__ == '__main__':
    main()