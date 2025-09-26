from picamera2 import Picamera2
import cv2
import mediapipe as mp
import numpy as np
import pickle

model = pickle.load(open("/home/JFan/gesture_recognition_pack/svm_model.pkl", "rb"))	# Loading the trained model

# Initialize Mediapipe for the hand tracking
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=2, min_detection_confidence=0.5)
mp_draw = mp.solutions.drawing_utils

# Initialize picamera
picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={"size": (640, 480), "format": "RGB888"}))
picam2.start()

while True:
	frame = picam2.capture_array()
	frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGRA2RGB)
	results = hands.process(frame_rgb)
	frame_bgr = cv2.cvtColor(frame, cv2.COLOR_BGRA2BGR)

	# Matching and Recognizing hand gestures
	if results.multi_hand_landmarks:
		for hand_landmarks in results.multi_hand_landmarks:
			mp_draw.draw_landmarks(frame_bgr, hand_landmarks, mp_hands.HAND_CONNECTIONS)
			coords = [[lm.x, lm.y] for lm in hand_landmarks.landmark]
			x_test = np.array(coords).flatten()
			pred = model.predict([x_test])[0]
			gestures = {0:"Hand",1:"Fist",2:"Thumb",3:"2Finger",4:"3Finger",5:"4Finger",6:"5Finger"}
			gesture = gestures[pred]
			cv2.putText(frame_bgr, gesture, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

	else:
		cv2.putText(frame_bgr, "No hand detected", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

	cv2.imshow("Gestures", frame_bgr)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

picam2.stop()
hands.close()
cv2.destroyAllWindows()
