import wave
import io
import sys
sys.path.append('..')
from util import *


def main():

	#argv[1] audio file 
	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Audio File')
	 #audio file name 
	imf = sys.argv[1]
	 
	print(f'Reading {imf} ...')
	
	
	#file to encrypt on audio file
	message = 	readTXT("secret_file_in.txt")
	#message  = 	readIMG('pic.png')
	
	#add flag to end 
	message = message + "@@@@@@@@@@@@@@@@@@"
	
	
	message_bits = tobits(message) #message to bit list(0,1)
	bit_length = len(message_bits)

	#obj = read audio file 
	obj = wave.open(imf,'rb')
	#out = open audio file2 to write
	out = wave.open(imf[:-4]+'-2.wav','wb')
	
	#get parametrs of auiod file1
	nchannels, sampwidth, framerate, nframes, comptype, compname = obj.getparams()
	#sets parametrs of audio file2 to 1
	out.setparams(obj.getparams())

	#list of frames
	frames = bytearray(obj.readframes(nframes))
	out.setnframes(nframes)
	
	
	for i in range(bit_length):
		frames[i] = addint(int(frames[i]),message_bits[i])

	out.writeframes(frames)

	obj.close()
	out.close()
	print("Done!")


if __name__ == '__main__':
    main()
