#import nltk

#nltk.download('vader_lexicon')
from gtts import gTTS
from playsound import playsound
import os
from pydub import AudioSegment
from pydub.silence import detect_nonsilent

from nltk.sentiment.vader import SentimentIntensityAnalyzer
from random import randint
from cvzone.SerialModule import SerialObject

arduino = SerialObject()

def load(file):
    sound = AudioSegment.from_file(file, format='mp3')

    bpm = 92

    rate = 1.4375

    octaves = -0.2 # For decreasing, octave can be -0.5, -2 etc.


    new_bpm = rate ** (octaves * 2)
    new_bpm = new_bpm * bpm


    new_sample_rate = int(sound.frame_rate * (2.0 ** octaves))

    new_sound = sound._spawn(sound.raw_data, overrides={'frame_rate': new_sample_rate})

    new_sound.export(file, format="mp3")


sia = SentimentIntensityAnalyzer()

tld = "com"

lang = "it"

audio = "tts.mp3"

def runloop(audio):
    load(audio)
    playsound(audio)
    os.remove(audio)

good = ["Thanks, that was very nice!", "You're pretty chill hermano!", "Have a drink with me sometime"]

bad = ["Screw you", "Kill yourself", "Your mom is fat"]

neu = ["Meh, whatever", "Yeah, I guess", "Sure, if you say so"]

data = 0

while True:

    text = input("C: ")

    results = sia.polarity_scores(text)
    del results['compound']
    #print(results)
    sentiment = max(results, key=results.get)
    if sentiment == 'neu':
        output = gTTS(text=neu[randint(0, len(good) - 1)], lang=lang, tld=tld)
        output.save(audio)
        runloop(audio)
        data = 1
        arduino.sendData([data])
    elif sentiment == 'pos':
        output = gTTS(text=good[randint(0, len(good) - 1)],lang=lang, tld=tld)
        output.save(audio)
        runloop(audio)
        data = 2
        arduino.sendData([data])
    elif sentiment == 'neg':
        output = gTTS(text=bad[randint(0, len(good) - 1)], lang=lang, tld=tld)
        output.save(audio)
        runloop(audio)
        data = 3
        arduino.sendData([data])
    arduino.sendData([0])
