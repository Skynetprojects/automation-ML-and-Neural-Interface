from pygame import *

mixer.init()
mixer.music.load('happy.ogg')
mixer.music.play()

while mixer.music.get_busy():
    time.Clock().tick(10)
