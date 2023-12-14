import wave
import io
import sys
sys.path.append('..')
from util import *

def main():

	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Audio File')
	#string of audiofile to decode
	imf = sys.argv[1]
	 
	print(f'Reading {imf} ...')
	
	#audio file 2
	obj = wave.open(imf,'rb')
	
	#len of frames 
	nframes = obj.getnframes()
	#list of frames
	frames = bytearray(obj.readframes(nframes))

	#message to output
	bitlist = []
	
	#for each frame
	for i in range(len(frames)):
		#bitlist append last bit of frames [i]
		bitlist.append(getLSB(int(frames[i])))
		
		
		if(len(bitlist) > 144 ):

			if (frombits(bitlist[-144:]) == "@@@@@@@@@@@@@@@@@@" ): break


	print ("Done!")

	data = frombits(bitlist[:-144])
	toTXT(data)


if __name__ == '__main__':
    main()



