# Here the annotations are skipped, many of the code are similar with the gesture capture file
from picamera2 import Picamera2
import cv2
import mediapipe as mp
import numpy as np

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=2, min_detection_confidence=0.5)
mp_draw = mp.solutions.drawing_utils

picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={"size": (640, 480), "format": "RGB888"}))
picam2.start()

log = []
while True:
	frame = picam2.capture_array()
	frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGRA2RGB)
	results = hands.process(frame_rgb)
	frame_bgr = cv2.cvtColor(frame, cv2.COLOR_BGRA2BGR)

	if results.multi_hand_landmarks:
		for hand_landmarks in results.multi_hand_landmarks:
			mp_draw.draw_landmarks(frame_bgr, hand_landmarks, mp_hands.HAND_CONNECTIONS)
			coords = [[lm.x, lm.y] for lm in hand_landmarks.landmark]
			log.append(coords)
			cv2.putText(frame_bgr, f"Logged: {len(log)}", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

			thumb_tip = hand_landmarks.landmark[4]
			cv2.putText(frame_bgr, f"Thumb: ({thumb_tip.x:.2f}, {thumb_tip.y:.2f})", (50, 80), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
	else:
		cv2.putText(frame_bgr, "No hand detected", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

	cv2.imshow("Hands", frame_bgr)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

np.save("fist_log.npy", log)
picam2.stop()
hands.close()
cv2.destroyAllWindows()
