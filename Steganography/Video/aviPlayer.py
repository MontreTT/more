import cv2
import time

def play_videoFile(filePath,mirror=False):
    cap = cv2.VideoCapture(filePath)
    cv2.namedWindow('AVI Player',cv2.WINDOW_AUTOSIZE)
    while True:
        suc, frame = cap.read()
        if (not suc):break
        if mirror:
            frame = cv2.flip(frame, 1)
        cv2.imshow('AVI Player', frame)
        if cv2.waitKey(1) == 27:
            break  # esc to quit
    cv2.destroyAllWindows()


def main():

	filename = input('Filename: ')
	play_videoFile(filename,mirror=False)


if __name__ == '__main__':
    main()