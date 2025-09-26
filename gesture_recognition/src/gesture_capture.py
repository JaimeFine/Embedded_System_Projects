from picamera2 import Picamera2
import numpy as np
import cv2
import mediapipe as mp	# Mediapipe for the handtracking

# Initialize Mediapipe hand detection
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.5)
mp_draw = mp.solutions.drawing_utils

# Initialize and configure the PiCamera
picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={"size": (640, 480), "format": "RGB888"}))
picam2.start()

# Prepare to log hand landmark data
log = []
capture_seconds = 5
frame_rate = 30
target_frames = capture_seconds * frame_rate
print(f"Capturing {target_frames} frames-start movingyour hand")

# Capture and process frames, use different fingers to capture different gestures
while len(log) < target_frames:
	frame = picam2.capture_array()
	frame_rgb = frame
	frame_bgr = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
	results = hands.process(frame_rgb)

	if results.multi_hand_landmarks:
		for hand_landmarks in results.multi_hand_landmarks:
			mp_draw.draw_landmarks(frame_bgr, hand_landmarks, mp_hands.HAND_CONNECTIONS)	# Draw landmarks and connections on the frame
			coords = [[lm.x, lm.y] for lm in hand_landmarks.landmark]	# Extract (x, y) coordinates of each landmark
			log.append(coords)
			cv2.putText(frame_bgr, f"Logged: {len(log)}/{target_frames}", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)	# Display logging progress on screen
	else:
		cv2.putText(frame_bgr, "No hand detected", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

	cv2.imshow("Capture", frame_bgr)
	cv2.waitKey(1)

# Save the captured hand landmark data, here in the example is the pinkie, you can adjust the filename as will
np.save("gesture_recognition_pack/5finger.npy",log)
print(f"Saved {len(log)} frames")

picam2.stop()
hands.close()
cv2.destroyAllWindows()

