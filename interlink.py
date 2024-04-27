import cv2
import pygame
from pygame import *
import numpy as np
import serial
from keras.models import model_from_json
from keras.preprocessing import image

ser = serial.Serial('COM7', 9600)


def switch():
    global ser
    while True:

        print("Press 1 Manual Mode\npress 2 for Emotion Recognition \npress 3 for Neural Interface \n")
        option = int(input("your Mode : "))

        if option == 1:

            if not ser.isOpen():
                ser.open()
            ser.write(b'9')
            ser.close()

        elif option == 2:

            if not ser.isOpen():
                ser.open()
            print("Emotion Recognition Camera Activated")

            # load model
            model = model_from_json(open("fer.json", "r").read())
            # load weights
            model.load_weights('fer.h5')

            face_haar_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

            cap = cv2.VideoCapture(0)

            while True:
                ret, test_img = cap.read()  # captures frame and returns boolean value and captured image
                if not ret:
                    continue
                gray_img = cv2.cvtColor(test_img, cv2.COLOR_BGR2GRAY)

                faces_detected = face_haar_cascade.detectMultiScale(gray_img, 1.32, 5)

                for (x, y, w, h) in faces_detected:
                    cv2.rectangle(test_img, (x, y), (x + w, y + h), (255, 0, 0), thickness=7)
                    roi_gray = gray_img[y:y + w, x:x + h]  # cropping region of interest i.e. face area from  image
                    roi_gray = cv2.resize(roi_gray, (48, 48))
                    img_pixels = image.img_to_array(roi_gray)
                    img_pixels = np.expand_dims(img_pixels, axis=0)
                    img_pixels /= 255

                    predictions = model.predict(img_pixels)

                    # find max indexed array
                    max_index = np.argmax(predictions[0])

                    emotions = ('angry', 'disgust', 'fear', 'happy', 'sad', 'surprise', 'neutral')
                    predicted_emotion = emotions[max_index]

                    cv2.putText(test_img, predicted_emotion, (int(x), int(y)), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255),
                                2)

                    if cv2.waitKey(10) == ord('e'):
                        print("Emotion Recognition Activated")
                        mixer.init()
                        # profile 1
                        if predicted_emotion == 'sad':
                            # time.sleep(1)
                            print("Sad Profile Activated")
                            ser.write(b'3')
                            # mixer.init()
                            mixer.music.load('sad.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break
                        # profile 2
                        if predicted_emotion == 'angry':
                            # time.sleep(1)
                            print("angry Profile Activated")
                            ser.write(b'2')
                            # mixer.init()
                            mixer.music.load('angry.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break
                        # profile 3
                        if predicted_emotion == 'disgust':
                            # time.sleep(1)
                            print("disgust Profile Activated")
                            ser.write(b'7')
                            # mixer.init()
                            mixer.music.load('disgust.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break
                        # profile 4
                        if predicted_emotion == 'fear':
                            # time.sleep(1)
                            print("fear Profile Activated")
                            ser.write(b'6')
                            # mixer.init()
                            mixer.music.load('disgust.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break
                        # profile 5
                        if predicted_emotion == 'surprise':
                            # time.sleep(1)
                            print("surprise Profile Activated")
                            ser.write(b'1')
                            # mixer.init()
                            mixer.music.load('disgust.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break
                        # profile 6
                        if predicted_emotion == 'neutral':
                            # time.sleep(1)
                            print("neutral Profile Activated")
                            ser.write(b'4')
                            pygame.mixer.fadeout(2)
                            pygame.mixer.music.stop()
                            pygame.mixer.quit()

                            break
                        # profile 7
                        if predicted_emotion == 'happy':
                            # time.sleep(1)
                            print("Happy Profile Activated")
                            ser.write(b'5')
                            # mixer.init()
                            mixer.music.load('happy.ogg')
                            mixer.music.play()

                            while mixer.music.get_busy():
                                time.Clock().tick(10)
                                if cv2.waitKey(10) == ord('e'):
                                    pygame.mixer.fadeout(2)
                                    pygame.mixer.music.stop()
                                    pygame.mixer.quit()
                                    break

                            break

                resized_img = cv2.resize(test_img, (800, 600))
                cv2.imshow('Skynet ', resized_img)

                if cv2.waitKey(10) == ord('q'):
                    ser.write(b'8')

                    pygame.mixer.music.stop()
                    pygame.mixer.quit()
                    break

            cap.release()
            cv2.destroyAllWindows()
            ser.close()

        elif option == 3:

            if not ser.isOpen():
                ser.open()
            print("Neural Interface Activated \n\n ")
            ser.write(b'0')
            ser.close()

        else:
            if not ser.isOpen():
                ser.open()
            ser.write(b'8')
            print("Incorrect mode")
            break


switch()
ser.close()
