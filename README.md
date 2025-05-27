# EKG Classification using C++

> I created this project to help my fellow classmates who are going through the same course and challenges I experienced. I hope it makes things easier for you.

## 📌 Overview

This is a C++ based implementation for classifying EKG (electrocardiogram) signals. The goal is to analyze heartbeat data and classify each signal into categories such as **bradycardia**, **normal**, or **tachycardia** based on voltage thresholds and time intervals.

The program reads an input file that contains timestamped voltage values, processes them, detects peaks, and classifies the heartbeats accordingly.

## ⚙️ Features

- Input: EKG data in plain text format (timestamp and voltage).
- Peak detection logic to determine heartbeat intervals.
- Classification logic based on:
  - **Bradycardia** (slow heart rate)
  - **Normal** heartbeat
  - **Tachycardia** (fast heart rate)
- Output: Heartbeat classifications printed to console and optionally saved to a file.

## 🧠 How It Works

1. Load the dataset from a file (e.g., `ekg_data.txt` or `ekg_bil344.txt`).
2. Parse each line to extract time and voltage.
3. Detect rising and falling edges to locate peaks.
4. Measure RR intervals (time between beats).
5. Classify based on thresholds (e.g., BPM < 60 → bradycardia).

## 📂 File Structure

```
EKG-Classifier/
│
├── ekg_classifier.cpp      # Main C++ source code
├── ekg_data.txt            # Default sample EKG input file
├── ekg_$ders$.txt          # Per-course data file (e.g., ekg_bil344.txt)
├── output.txt              # Classification results (optional)
├── README.md               # This documentation
```

## 🔧 Requirements

- C++11 or later
- A standard C++ compiler (e.g., `g++`, `clang`)
- No external libraries required

## 🚀 Build & Run

```bash
g++ ekg_classifier.cpp -o ekg_classifier
./ekg_classifier ekg_data.txt
```

## 🔽 Downloading and Using Course-Specific Data

If you'd like to analyze course-specific EKG files (e.g., for coursework or simulation), just pass the course code as an argument.

### 💻 Example

```bash
# To use data for the course 'bil344':
./ekg_classifier bil344

# This will look for a file named:
ekg_bil344.txt
```

Just replace `$ders$` with your course code.

---

## 📈 Future Improvements

- GUI visualization for heartbeat curves
- Real-time signal analysis
- Integration with CSV or JSON data sources

## 🤝 Contribution

This project is designed for educational use and not intended for medical diagnosis. Feel free to fork it, test it, and improve it. Pull requests are welcome.

## 📬 Contact

For questions or collaboration, you can reach me via GitHub or email.
