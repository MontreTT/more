import cv2
import time
import sys
sys.path.append('..')
from util import *


def decodeMsg(file):


	vidcap = cv2.VideoCapture(file)
	frame_width = int(vidcap.get(3))
	frame_height = int(vidcap.get(4))
	frame_rate	=int(vidcap.get(5))
	print(vidcap)	


	bitlist = []

	loop = True	
	while loop:
	
		success, frame = vidcap.read()
		if not success:
			print ('Fwak')
			break
		for h in range(frame_height):
			for w in range(frame_width):
				for clr in range(3):

					bitlist.append(getLSB(int(frame[h,w][clr])))


				if frombits(bitlist[-144:]) == "!)NF@^&I^U%$&T&#@&" : return frombits(bitlist[:-144])





def main():

	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Video File')
	 
	vidf = sys.argv[1]
	 
	print(f'Reading {vidf} ...')

	
	message = decodeMsg(vidf)
	print ("Done!")

	toTXT(message)
	

	

if __name__ == '__main__':
    main()