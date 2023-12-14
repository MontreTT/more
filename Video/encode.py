import cv2
import io
import os
import sys
sys.path.append('..')
from util import *


def encode(message,file):

	message = 	readTXT("secret_file_in.txt") + "!)NF@^&I^U%$&T&#@&"
	#message  = 	readIMG('pic.png')

	message_bits = tobits(message) 
	bit_length = len(message_bits)
	MESSAGE_LENGTH = len(message_bits)

	print("Reading Video Frames:")

	vidcap = cv2.VideoCapture(file)
	frame_width = int(vidcap.get(3))
	frame_height = int(vidcap.get(4))
	frame_rate	=int(vidcap.get(5))
	fourcc = cv2.VideoWriter_fourcc(*'RGBA')
	encodedFile = file[:-4] + '-2.avi'
	out = cv2.VideoWriter(encodedFile,fourcc,10, (frame_width,frame_height))

	print(vidcap)

	count=0
	i = 0 # Index for message bits list
	while True:
			success, frame = vidcap.read() # Read next frame
			count +=1
			if count > 100 : break # Read only 100 frames
			if not success:
				break

			for h in range(frame_height):
				for w in range(frame_width):
					if (i< MESSAGE_LENGTH):
						Rbit = message_bits[i] 
						Gbit = message_bits[i+1]
						Bbit = message_bits[i+2]
						R = addint(frame[h,w][0],Rbit)
						G = addint(frame[h,w][1],Gbit)
						B = addint(frame[h,w][2],Bbit)
						#print(frame[w,h],' - ',R,',',G,',',B)
						frame[h,w] = [R,G,B]
						#print (h , w, ' ',frame[h,w])
						i = i + 3
					else:
						break
			#temp_folder = 'tempDir'
			#cv2.imwrite(os.path.join(temp_folder, "{:d}.png".format(count)), frame)	
			# Write the frame into the file 'output.avi'
			out.write(frame)
			count += 1

	# When everything done, release the video capture and video write objects
	vidcap.release()
	out.release()
	print("Done!")



def main():

	if len(sys.argv) != 2:
		raise ValueError('Missing argument: Video File')
	 
	vidf = sys.argv[1]
	 
	print(f'Reading {vidf} ...')

	encode('msg',vidf)
	

	

if __name__ == '__main__':
    main()