from PIL import Image
import sys
sys.path.append('..')
from util import *



def main():

	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Image File')
	 
	imf = sys.argv[1]
	print(f'Reading {imf} ...')

	im = Image.open(imf) # Open Image
	pix = im.load()		# Read Image RGB Values
	width, height = im.size

	print('File Format :',im.format, im.size, im.mode)
	print('Embedding secret_file_in.txt to file')
	message = readTXT("secret_file_in.txt")

	
	for i in range(3-len(message)%3):
		message = message + '*'

	message = message + '!)NF@^&I^U%$&T&#@&'

	message_bits = tobits(message) 
	MESSAGE_LENGTH = len(message_bits)


	i = 0 # Index for message bits list
	for w in range(width):
		for h in range(height):

			Rbit = message_bits[i]
			Gbit = message_bits[i+1]
			Bbit = message_bits[i+2]

			R = addint(pix[w,h][0],Rbit)
			G = addint(pix[w,h][1],Gbit)
			B = addint(pix[w,h][2],Bbit)			
			im.putpixel((w,h),(R,G,B))
		
			i = i + 3	
			if (i >= MESSAGE_LENGTH): break
		if (i >= MESSAGE_LENGTH): break
			

	encodedFile = imf[:-4] + '-2.png'
	im.save(encodedFile)
	print('Saving encoded File as:' ,encodedFile)


if __name__ == '__main__':
    main()



























