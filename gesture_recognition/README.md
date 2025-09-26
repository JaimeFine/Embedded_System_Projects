# Raspberry Pi Camera Gesture Recognition

This project implements **real-time hand gesture recognition** on a Raspberry Pi using the **PiCamera2**, **OpenCV**, and **MediaPipe** for hand tracking, combined with a **scikit-learn SVM classifier**.
It allows you to **capture hand landmark data**, **train a gesture recognition model**, and **perform live gesture classification**.

## 📦 Features

* ✅ **Hand Landmark Capture** – Record landmark data for different gestures using MediaPipe.
* ⚙️ **Custom Gesture Training** – Train your own SVM model on collected gestures.
* 🎥 **Real-Time Recognition** – Recognize gestures from live PiCamera2 input and overlay results on the video feed.

## 🛠️ Installation

```bash
# Clone the repo
git clone https://github.com/yourusername/raspberry-pi-gesture-recognition.git
cd raspberry-pi-gesture-recognition

# Install dependencies
pip install [dependencies]
```

> Dependencies include:
>
> * `opencv-python`
> * `mediapipe`
> * `numpy`
> * `scikit-learn`
> * `picamera2`

## ▶️ Usage

### 1. Capture Gesture Data

Run the capture script to log landmark data for a specific gesture (e.g., 5-finger hand):

```bash
python src/gesture_capture.py
```

👉 Saves data as `.npy` files inside `gesture_recognition_pack/`.

### 2. Train the Model

After collecting gesture datasets:

```bash
python src/training_program.py
```

👉 Outputs `svm_model.pkl` (your trained classifier).

### 3. Recognize Gestures in Real-Time

```bash
python src/gesture_recognition.py
```

👉 Displays PiCamera feed with recognized gestures (`Hand`, `Fist`, `Thumb`, `2Finger`, `3Finger`, `4Finger`, `5Finger`).
Press **q** to quit.

### 4. Logging Hand Data (optional)

```bash
python src/logging_hand_data.py
```

👉 Continuously logs landmarks with visualization.

## ⚙️ Configuration

Adjust paths and filenames for `.npy` gesture datasets or `svm_model.pkl` inside the scripts if needed.

Default gesture classes:

```
0 – Hand
1 – Fist
2 – Thumb
3 – 2Finger
4 – 3Finger
5 – 4Finger
6 – 5Finger
```

## 🧠 Code Structure

```
src/
├── gesture_capture.py          # Capture landmark data for a gesture
├── logging_hand_data.py        # Live logging of landmarks
├── training_program.py         # Train SVM model on captured gestures
├── gesture_recognition.py      # Real-time gesture recognition
└── gesture_recognition_pack/   # Stores .npy datasets & trained model

```

## 🤝 Contributing

We welcome contributions! Here’s how to get started:

1. 🍴 Fork the repo
2. 🛠️ Create your feature branch (`git checkout -b feature/foo`)
3. ✅ Commit your changes (`git commit -am 'Add foo feature'`)
4. 🚀 Push to the branch (`git push origin feature/foo`)
5. 📬 Open a Pull Request

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
