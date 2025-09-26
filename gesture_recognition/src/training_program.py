import numpy as np
from sklearn.svm import SVC
import pickle

hand = np.load("/home/JFan/gesture_recognition_pack/hand.npy")
fist = np.load("/home/JFan/gesture_recognition_pack/fist.npy")
thumb = np.load("/home/JFan/gesture_recognition_pack/thumb.npy")
secfinger = np.load("/home/JFan/gesture_recognition_pack/2finger.npy")
thifinger = np.load("/home/JFan/gesture_recognition_pack/3finger.npy")
foufinger = np.load("/home/JFan/gesture_recognition_pack/4finger.npy")
fiffinger = np.load("/home/JFan/gesture_recognition_pack/5finger.npy")

x = np.vstack([hand,fist,thumb,secfinger,thifinger,foufinger,fiffinger]).reshape(-1, 42)
y = ([0]*len(hand)+[1]*len(fist)+[2]*len(thumb)+[3]*len(secfinger)+[4]*len(thifinger)+[5]*len(foufinger)+[6]*len(fiffinger))

model = SVC(kernel='linear')
model.fit(x, y)
print("Model trained")
pickle.dump(model, open("/home/JFan/gesture_recognition_pack/svm_model.pkl", "wb"))
